#include "chapter3_array_struct_pointer.h"

int get_distance(point p1, point p2){
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

polynomial poly_add1(polynomial A, polynomial B)
{
    polynomial C;
    int Apos = 0, Bpos = 0, Cpos = 0;
    int degree_a = A.degree;
    int degree_b = B.degree;
    C.degree = MAX(A.degree, B.degree);

    while(Apos <= A.degree && Bpos <= B.degree){
        if(degree_a > degree_b){
            C.coef[Cpos++] = A.coef[Apos++];
            degree_a--;
        }else if( degree_a == degree_b){
            C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
            degree_a--, degree_b--;

        } else{
            C.coef[Cpos++] = B.coef[Bpos++];
            degree_b--;
        }
    }
    return C;
}
void print_poly(polynomial p)
{
    for(int i = p.degree; i > 0; i--){
        if(p.coef[p.degree-i] != 0){
            printf("%3.1fx^%d + ", p.coef[p.degree-i],i);
        }
    }
    printf("%3.1f\n", p.coef[p.degree]);
}

SparseMatrix matrix_transpose2(SparseMatrix a)
{
    SparseMatrix b;

    int bindex;
    b.rows = a.rows;
    b.cols = a.cols;
    b.terms = a.terms;

    if(a.terms > 0){
        bindex = 0;
        for(int c = 0; c< a.cols; c++){
            for(int i = 0; i < a.terms; i++)
            {
                if(a.data[i].col == c){
                    b.data[bindex].row = a.data[i].col;
                    b.data[bindex].col = a.data[i].row;
                    b.data[bindex].value = a.data[i].value;
                    bindex;
                }
            }
        }
    }
    return b;
}
void swap(int *px, int *py)
{
    int tmp;
    tmp = *px;
    *px = *py;
    *py = tmp;
}

void get_integers(int list[])
{
    printf("정수 입력(6개)");
    for(int i = 0 ; i < 6; i++){
        scanf("%d", &list[i]);
    }
}

int cal_sum(int list[])
{
    int sum = 0;
    for(int i = 0; i < 6; ++i)
    {
        sum += *(list + i);
    }
    return sum;
}

void change_value(int * two)
{
    for(int i = 0; i < 10; i++){
        two[i] = 20 + i;
    }
}
complex  complex_add(complex a, complex b){
    complex c;
    c.real = a.real + b.real;
    b.imaginary = a.imaginary + b.imaginary;
    return c;
}

void insert(int array[], int size, int loc, int value) {
    for (int i = size; i > loc; i--) {
        array[i] = array[i - 1];
    }
    array[loc] = value;
    size++;
}

void delete(int array[], int size, int loc) {
    for(int i = loc; i <size; i++){
        array[i] = array[i+1];
    }
}


void change_string(str * str1){
    str1->num = (int *) malloc(sizeof(int));
    str1->string = (char *) malloc(sizeof(char) * 100);

    *str1->num = 100;
    strcpy(str1->string, "just testing");
}