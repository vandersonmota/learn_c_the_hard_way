#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/** our old friend die from ex17 */
void die(const char *message)
{
    if (errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

// a typedef creates a fake type, in
// this case for a function pointer
typedef int (*compare_cb)(int a, int b);

int *bubble_sort(int *numbers, int count, compare_cb cmp)
{
    int temp = 0;
    int i = 0;
    int j = 0;
    int *target = malloc(count * sizeof(int));

    if(!target) die("Memory error.");

    memcpy(target, numbers, count * sizeof(int));
    for (i=0; i < count; i++) {
        for(j = 0; j < count - 1; j++) {
            if (cmp(target[j], target[j+1]) > 0) {
                temp = target[j+1];
                target[j+1] = target[j];
                target[j] = temp;
            }
        }
    }

    return target;
}

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int pivot(int i, int j) {
    return (i+j) / 2;
}

int partition(int *array, int left, int right, compare_cb cmp) {
    int p = pivot(left, right);
    swap(&array[p], &array[right]);
    int store = left;
    int i = 0;
    for(i=left; i < right;i++){
        if (cmp(array[i], array[right]) <= 0){
            swap(&array[i], &array[store]);
            store++;
        }
    }
    swap(&array[store], &array[right]);
    return store;
}

void *quicksort(int *numbers, int left, int right, compare_cb cmp) {
    if (left < right) {
        int p = partition(numbers, left, right, cmp);
        quicksort(numbers, left, p-1, cmp);
        quicksort(numbers, p+1, right, cmp);
    }
}

int sorted_order(int a, int b)
{
    return a - b;
}

int reverse_order(int a, int b)
{
    return b - a;
}

int strange_order(int a, int b)
{
    if(a == 0 || b == 0){
        return 0;
    } else {
        return a % b;
    }
}

/**
 * Used to test that we are sorting things correctly
 * by doing the sort and printing it out.
 */

void test_sorting(int *numbers, int count, compare_cb cmp)
{
    int i = 0;
    quicksort(numbers, 0, count-1, cmp);

    for(i = 0; i < count; i++) {
        printf("%d", numbers[i]);
    }
    printf("\n");
    unsigned char *data = (unsigned char *)cmp;
    for(i=0; i < 25; i++) {
        printf("%02x:", data[i]);
    }
    printf("\n");

}

int main(int argc, char *argv[])
{
    if(argc < 2) die("USAGE: ex18 4 3 1 5 6");
    int count = argc - 1;
    int i = 0;
    char **inputs = argv + 1;

    int *numbers = malloc(count * sizeof(int));
    if(!numbers) die("Memory error.");

    for(i=0; i < count; i++){
        numbers[i] = atoi(inputs[i]);
    }

    test_sorting(numbers, count, sorted_order);
    test_sorting(numbers, count, reverse_order);
    test_sorting(numbers, count, strange_order);

    free(numbers);
    return 0;
}
