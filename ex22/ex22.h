#ifndef _ex22_h
#define _ex22_h

// makes THE_SIZE in ex22.c available to other .c files
extern int THE_SIZE;

int get_age();
void set_age(int age);

//updates a static variable that's inside update_ratio
double update_ratio(double ratio);

void print_size();

#endif
