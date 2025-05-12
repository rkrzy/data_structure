#include "stack_interface.h"

#define MAX_STACK_SIZE 100

typedef struct {
    element *data;
    int capacity;
    int top;
}DynamicStack;

static int is_empty(Stack * s)
{
    return ((DynamicStack *)s->data)->top == -1;
}

static int is_full(Stack *s)
{
    return ((DynamicStack *)s->data)->top == MAX_STACK_SIZE -1;
}
static void push(Stack *s, element item){
    DynamicStack * ds = (DynamicStack *)s->data;
    if(is_full(s)) {
        ds->capacity *= 2;
        ds->data = (element *) realloc(ds->data, ds->capacity * sizeof(element));
    }
    ds->data[++ds->top] = item;
}
static element pop(Stack *s){
    DynamicStack *ds = (DynamicStack *)s->data;
    if(is_empty(s)) {
        exit(1);
    }
    else{
        return ds->data[ds->top--];
    }
}
static element peek(Stack *s){
    DynamicStack *ds = (DynamicStack *)s->data;
    if(is_empty(s)) {
        exit(1);
    }
    else{
        return ds->data[ds->top];
    }
}
static void destroy(Stack * s){
    DynamicStack * ds = (DynamicStack *)s->data;
    free(ds->data);
    free(s->data);
    free(s->ops);
    free(s);
}
Stack *create_dynamic_stack() {
    Stack *stack = malloc(sizeof(Stack));
    stack->data = malloc(sizeof(DynamicStack));
    ((DynamicStack *)stack->data)->capacity = 100;
    ((DynamicStack *)stack->data)->top = -1;
    ((DynamicStack *)stack->data)->data = malloc(sizeof(element) * ((DynamicStack *)stack->data)->capacity);
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