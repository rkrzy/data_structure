#include <stdio.h>
#include <stdlib.h>
#include "list_interface.h"
typedef int element;



ListNode * linked_search_list(ListNode *head, element x){
    ListNode *p = head;
    while(p->link != NULL){
        if(p->data == x){
            return p;
        }
        p = p->link;
    }
    return NULL;
}
ListNode* linked_insert_first(ListNode *head, int value){
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}

ListNode* linked_insert(ListNode *head, ListNode *pre, element value){
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value;
    p->link = pre->link;
    pre->link = p;
    return head;
}

ListNode * linked_delete_first(ListNode * head){
    ListNode *removed;
    if(head == NULL) return NULL;
    removed = head;
    head = removed->link;
    free(removed);
    return head;
}

ListNode * linked_delete(ListNode *head, ListNode *pre)
{
    ListNode *removed;
    removed = pre->link;
    pre->link = removed->link;
    free(removed);
    return head;
}

void linked_print_list(ListNode *head)
{
    for(ListNode *p = head; p != NULL; p = p->link)
    {
        printf("%d->", p->data);
    }
    printf("NULL \n");
}
int linked_get_length(ListNode *head)
{
    int count = 1;
    for(ListNode *p = head; p != NULL; p = p->link)
    {
        count++;
    }
    return count;
}
ListNode * linked_concat_list(ListNode *head1, ListNode *head2){
    if(head1 == NULL) return head2;
    else if(head2 == NULL) return head1;
    else{
        ListNode  *p;
        p = head1;
        while(p->link != NULL){
            p = p->link;
        }
        p->link = head2;
        return head1;
    }
}

ListNode * linked_reverse(ListNode *head){
    ListNode *p, *q, *r;
    p = head;
    q = NULL;
    while (p != NULL){
        r = q;
        q = p;
        p = p->link;
        p->link = r;
    }
    return p;
}