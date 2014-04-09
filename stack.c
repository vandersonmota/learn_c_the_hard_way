#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int items[MAX];
int top = 0;

int array_length(int *a) {
    return sizeof(*a)/sizeof(int);
}

int push(int *stack, int value) {
    if (top > MAX) {
        printf("Overflow\n");
        return 1;
    }
    else {
        printf("Pushed %d\n", value);
        stack[top] = value;
        top++;
        return 0;
    }
}

int pop(int *stack) {
  if (top == 0) {
      printf("Underflow\n");
      return 1;
  }
  else {
      printf("Popped %d\n", stack[top-1]);
      stack[top-1] = 0;
      top--;
      return 1;
  }
}

int main(int argc, char *argv[]) {
    int *stack = items;

    push(stack, 2);
    pop(stack);
    pop(stack);
    push(stack, 2);
    push(stack, 2);
    push(stack, 2);
    push(stack, 2);
    push(stack, 2);
    push(stack, 2);
    push(stack, 2);
    push(stack, 2);
    push(stack, 2);
    push(stack, 2);
    push(stack, 2);
    push(stack, 2);
    push(stack, 2);
}
