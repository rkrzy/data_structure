#include "chapter2_recursive.h"

int factorial(int n){
    if(n <= 1) return 1;
    else return (n * factorial(n-1));
}

int sub(int n){
    if( n < 0 ) return 0;
    return n + sub(n - 3);
}

int sub_iteration(int n){
    int result = 0;
    for(int i = n; i > 0; i -= 3){
        result += i;
    }
    return result;
}
double power(double x, int n){
    if(n == 0) return 1;
    else if((n%2) == 0){
        return power(x * x, n/2);
    }else{
        return x * power(x*x, (n-1)/2);
    }
}
int fib(int n)
{
    if(n == 0) return 0;
    if(n == 1) return 1;
    return (fib(n-1) + fib(n-2));
}

int fib_iteration(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;

    int pp = 0;
    int p = 1;
    int result = 0;

    for(int i = 2; i <= n; i++){
        result = p +pp;
        pp = p;
        p = result;
    }
    return result;
}

void hanoi_tower(int n, char from, char tmp, char to){
    if(n == 1){
        printf("원판 1을 %c에서 %c로 옮긴다.\n", from, to);
    }else{
        hanoi_tower(n-1, from, to, tmp);
        printf("원판 %d을 %c에서 %c로 옮긴다.\n", n, from, to);
        hanoi_tower(n-1, tmp, from, to);
    }
}

int add(int n){
    if(n == 1) return 1;
    else{
        return n + add(n-1);
    }
}

double add2(double n){
    if(n == 1) return 1;
    else{
        return 1/n + add2(n-1);
    }
}

int binomial_coefficient(int n, int k){
    if(n == k || k == 0){
        return 1;
    }
    else{
        return binomial_coefficient(n - 1, k - 1) + binomial_coefficient(n - 1, k);
    }
}

int screen[WIDTH][HEIGHT];

char read_pixel(int x, int y){
    return screen[x][y];
}

void write_pixel(int x, int y, int color)
{
    screen[x][y] = color;
}
void flood_fill(int x, int y)
{
    if(x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) return;
    if(read_pixel(x,y) != WHITE) return;
    if(read_pixel(x,y) == WHITE){
        write_pixel(x, y, BLACK);
        flood_fill(x+1,y);
        flood_fill(x-1,y);
        flood_fill(x,y+1);
        flood_fill(x,y-1);
    }
}
