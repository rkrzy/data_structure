#include <stdio.h>
#include <stdlib.h>
#include "chapter4_stack//stack_interface.h"

extern Stack *create_static_stack();
extern Stack *create_dynamic_stack();

void print_element(const char *label, element e) {
    printf("%s: [%d] %s - %s\n", label, e.student_no, e.name, e.address);
}

int main() {

    Stack *static_stack = create_static_stack();

    Stack *dynamic_stack = create_dynamic_stack();

    element e1 = {1, "Kim", "Busan"};
    element e2 = {2, "Lee", "Seoul"};

    static_stack->ops->push(static_stack, e1);
    static_stack->ops->push(static_stack, e2);

    dynamic_stack->ops->push(dynamic_stack, e2);
    dynamic_stack->ops->push(dynamic_stack, e1);

    element top_static = static_stack->ops->peek(static_stack);
    print_element("Static Stack Top", top_static);

    element top_dynamic = dynamic_stack->ops->peek(dynamic_stack);
    print_element("Dynamic Stack Top", top_dynamic);

    // 6. 각 스택의 pop
    element popped_static = static_stack->ops->pop(static_stack);
    print_element("Static Stack Pop", popped_static);

    element popped_dynamic = dynamic_stack->ops->pop(dynamic_stack);
    print_element("Dynamic Stack Pop", popped_dynamic);

    static_stack->ops->destroy(static_stack);
    dynamic_stack->ops->destroy(dynamic_stack);

    printf("\n정적/동적 스택 테스트 완료!\n");

    return 0;
}
