#include "stack_interface.h"

#define MAX_STACK_SIZE 100

typedef struct {
    element arr[MAX_STACK_SIZE];
    int top;
}StaticStack;

static int is_empty(Stack * s)
{
    StaticStack *ss = (StaticStack *)s->data;
    return ss->top == -1;
}
static int is_full(Stack *s)
{
    StaticStack *ss = (StaticStack *)s->data;
    return ss->top == MAX_STACK_SIZE-1;
}
void push(Stack *s, element item){
    StaticStack *ss = (StaticStack *)s->data;
    if(is_full(s))return;
    ss->arr[++ss->top] = item;
}
static element pop(Stack *s){
    StaticStack *ss = (StaticStack *)s->data;
    if(is_empty(s)) exit(1);
    return ss->arr[ss->top--];
}

static element peek(Stack *s)
{
    StaticStack *ss = (StaticStack *) s->data;
    if(is_empty(s))exit(1);
    return ss->arr[ss->top];
}
static void destroy(Stack *s){
    free(s->data);
    free(s->ops);
    free(s);
}

Stack *create_static_stack(){
    Stack *stack = malloc(sizeof(Stack));
    stack->data = malloc(sizeof(StaticStack));
    ((StaticStack *)stack->data)->top = -1;

    StackOps *ops = malloc(sizeof(StackOps));
    ops->push = push;
    ops->pop = pop;
    ops->peek = peek;
    ops->is_empty = is_empty;
    ops->is_full = is_full;
    ops->destroy = destroy;

    stack->ops = ops;
    return stack;
}