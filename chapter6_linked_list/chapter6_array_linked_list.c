#include "list_interface.h"

typedef struct {
    element array[MAX_LIST_SIZE];
    int size;
}ArrayList;

static void error(char *message){
    fprintf(stderr, "%s\n", message);
    exit(1);
}

static void init(List *l){
    ((ArrayList *)l->data)->size = 0;
}

static int is_empty(List *l){
    return ((ArrayList *)l->data)->size == 0;
}

static int is_full(List *l){
    return ((ArrayList *)l->data)->size == MAX_LIST_SIZE;
}

static element get_entry(List *l, int pos){
    ArrayList al = *(ArrayList *)l;
    if(pos < 0 || pos >= al.size){
        error("위치 오류");
    }
    return al.array[pos];
}

static void print_list(List *l){
    int i;
    ArrayList al = *(ArrayList *)l;
    for(i = 0; i <al.size;i++){
        printf("%d->", al.array[i]);
    }
    printf("\n");
}

static void insert_last(List *l, element item){
    ArrayList al = *(ArrayList *)l;
    if(is_full(l)){
        error("리스트 오버플로우");
    }
    al.array[al.size++] = item;
}
static void insert(List *l, int pos, element item){
    ArrayList al = *(ArrayList *)l;
    if(!is_full(l) && (pos >= 0) && (pos <= al.size))
    {
        for(int i = (al.size-1); i >= pos; i--){
            al.array[i+1] = al.array[i];
        }
        al.array[pos] = item;
        al.size++;
    }
}
static element delete(List *l, int pos){
    element item;
    ArrayList al = *(ArrayList *)l;
    if(pos <0 || pos >= al.size){
        error("위치 오류");
    }
    item = al.array[pos];
    for(int i = pos; i < (al.size - 1); i++){
        al.array[i] = al.array[i+1];
    }
    al.size--;
    return item;
}

static int get_length(List *l){
    return ((ArrayList *)l->data)->size;
}
static void clear(List *l){
    ArrayList * al = (ArrayList *)l;
    for(int i = 0;i < al->size; i++){
        al->array[i] = 0;
    }
    al->size = 0;
}

static void replace(List *l, int pos, element item){
    ArrayList * al = (ArrayList *)l;
    int i =0;
    for(i = 0;i <= pos; i++);
    al->array[i] = item;
}
List * create_array_list(){
    List * list = malloc(sizeof (List));
    list->data = malloc(sizeof(ArrayList));
    ((ArrayList *)list->data)->size = 0;

    ListOps * list_ops = malloc(sizeof(ListOps));
    list_ops->is_empty = is_empty;
    list_ops->is_full = is_full;
    list_ops->error = error;
    list_ops->get_entry = get_entry;
    list_ops->insert_last = insert_last;
    list_ops->print_list = print_list;
    list_ops->insert = insert;
    list_ops->delete = delete;
    list_ops->init = init;
    list_ops->get_length = get_length;
    list_ops->clear = clear;
    list_ops->replace = replace;

    list->list_ops = list_ops;
    return list;
}