#include "list_interface.h"
void poly_error(char * message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

ListType *create()
{
    ListType *plist = (ListType *) malloc(sizeof(ListType));
    plist->size = 0;
    plist->head = plist->tail = NULL;
    return plist;
}

void insert_last(ListType *plist, int coef, int expon)
{
    PolyList *temp = (PolyList *) malloc(sizeof(PolyList));
    if(temp ==NULL){
        poly_error("메모리 할당 에러");
    }
    temp->coef = coef;
    temp->expon = expon;
    temp->link = NULL;
    if(plist->tail == NULL){
        plist->head = plist->tail = temp;
    }
    else{
        plist->tail->link = temp;
        plist->tail = temp;
    }
    plist->size++;
}
void poly_add(ListType * plist1, ListType* plist2, ListType* plist3){
    PolyList * a = plist1->head;
    PolyList * b = plist2->head;
    int sum;
    while (a && b){
        if(a->expon == b->expon){
            sum = a->coef + b->coef;
            if(sum != 0) insert_last(plist3, sum, a->expon);
            a = a->link;
            b = b->link;
        }
        else if(a->expon > b->expon){
            insert_last(plist3,a->coef, b->coef);
            a = a->link;
        }
        else{
            insert_last(plist3, b->coef, b->expon);
            b = b->link;
        }
    }
    for(; a != NULL; a = a->link){
        insert_last(plist3, a->coef, a->expon);
    }
    for(; b != NULL; b = b->link){
        insert_last(plist3, b->coef, b->expon);
    }
}

void poly_list(ListType * plist)
{
    PolyList *p = plist->head;

    printf("polynomial = ");
    for(;p; p= p->link){
        printf("%d %d + ", p->coef, p->expon);
    }
    printf("\n");
}

