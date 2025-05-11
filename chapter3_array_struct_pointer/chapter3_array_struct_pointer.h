//
// Created by 임준식 on 25. 5. 11.
//

#ifndef DATA_STRUCTURE_CHAPTER3_ARRAY_STRUCT_POINTER_H
#define DATA_STRUCTURE_CHAPTER3_ARRAY_STRUCT_POINTER_H
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define MAX(a, b) (((a) > (b))? (a):(b))
#define MAX_DEGREE 101
#define MAX_TERMS 100
typedef struct Point{
    int x;
    int y;
} point;

typedef struct {
    int degree;
    float coef[MAX_DEGREE];
} polynomial;

typedef struct {
    int row;
    int col;
    int value;
}element;

typedef struct SparseMatrix {
    element data[MAX_TERMS];
    int rows;
    int cols;
    int terms;
}SparseMatrix;

typedef struct{
    char name[50];
    int age;
    float salary;
}Person;

typedef struct {
    float real;
    float imaginary;
}complex;

typedef struct {
    int* num;
    char * string;
}str;

int get_distance(point p1, point p2);

polynomial poly_add1(polynomial A, polynomial B);
void print_poly(polynomial p);

SparseMatrix matrix_transpose2(SparseMatrix a);

void swap(int *px, int *py);

void get_integers(int list[]);

int cal_sum(int list[]);

complex  complex_add(complex a, complex b);

void insert(int array[], int size, int loc, int value);
void delete(int array[], int size, int loc);
#endif //DATA_STRUCTURE_CHAPTER3_ARRAY_STRUCT_POINTER_H
