//
// Created by 임준식 on 25. 5. 12.
//

#ifndef DATA_STRUCTURE_STACK_INTERFACE_H
#define DATA_STRUCTURE_STACK_INTERFACE_H
#define MAX_STRING 100
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int student_no;
    char name[MAX_STRING];
    char address[MAX_STRING];
} element;

typedef struct Stack Stack;

typedef struct {
    void (*push)(Stack *s, element item);
    element (*pop)(Stack *s);
    element (*peek)(Stack *s);
    int (*is_empty)(Stack *s);
    int (*is_full)(Stack *s);
    void (*destroy)(Stack *s); // 동적 할당된 경우 해제
} StackOps;

struct Stack {
    void *data;         // 실제 구현체 포인터
    StackOps *ops;      // 함수 테이블
};

#endif //DATA_STRUCTURE_STACK_INTERFACE_H
