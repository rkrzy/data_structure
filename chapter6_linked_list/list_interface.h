//
// Created by 임준식 on 25. 5. 14.
//

#ifndef DATA_STRUCTURE_LIST_INTERFACE_H
#define DATA_STRUCTURE_LIST_INTERFACE_H

#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100

typedef int element;

typedef struct ListNode {
    element data;
    struct ListNode * link;
}ListNode;

typedef struct{
    int coef;
    int expon;
    struct PolyList *link;
}PolyList;

typedef struct ListType {
    int size;
    PolyList *head;
    PolyList *tail;
}ListType;

typedef struct List List;
typedef struct{
    void (*error)(char *message);
    void (*init)(List *l);
    int (*is_empty)(List *l);
    int (*is_full)(List *l);
    element (*get_entry)(List *l, int pos);
    void (*print_list)(List *l);
    void (*insert_last)(List *l, element item);
    void (*insert)(List *l, int pos, element item);
    element (*delete)(List *l, int pos);
    int (*get_length)(List *l);
    void (*clear)(List *l);
    void (*replace)(List *l, int pos, element item);
}ListOps;

ListNode * linked_search_list(ListNode *head, element x);
ListNode* linked_insert_first(ListNode *head, int value);
ListNode* linked_insert(ListNode *head, ListNode *pre, element value);
ListNode * linked_delete_first(ListNode * head);
ListNode * linked_delete(ListNode *head, ListNode *pre);
void linked_print_list(ListNode *head);
int linked_get_length(ListNode *head);
ListNode * linked_concat_list(ListNode *head1, ListNode *head2);
ListNode * linked_reverse(ListNode *head);


void poly_error(char * message);
ListType *create();
void insert_last(ListType *plist, int coef, int expon);
void poly_add(ListType *plist1, ListType *plist2, ListType *plist3);
struct List {
    void * data;
    ListOps * list_ops;
};
#endif //DATA_STRUCTURE_LIST_INTERFACE_H
