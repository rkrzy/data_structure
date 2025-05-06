//
// Created by 임준식 on 25. 5. 5.
//


#ifndef DATA_STRUCTURE_CHAPTER2_RECURSIVE_H
#define DATA_STRUCTURE_CHAPTER2_RECURSIVE_H
#include <stdio.h>
#define WHITE 0
#define BLACK 1
#define YELLOW 2
#define WIDTH 100
#define HEIGHT 100

int factorial(int n);
int sub(int n);
int sub_iteration(int n);
double power(double x, int n);
int fib(int n);
int fib_iteration(int n);
void hanoi_tower(int n, char from, char tmp, char to);
int add(int n);
double add2(double n);
int binomial_coefficient(int n, int k);


#endif //DATA_STRUCTURE_CHAPTER2_RECURSIVE_H
