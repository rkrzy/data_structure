#include "queue_interface.h"

typedef struct{
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
}LinearQueue;


static void error(char * message){
    fprintf(stderr, "%s\n", message);
    exit(1);
}

static void init_queue(Queue * q){
    (*(LinearQueue *)q->data).rear = -1;
    (*(LinearQueue *)q->data).front = -1;
}

static void queue_print(Queue * q){
    LinearQueue *lq = (LinearQueue *)q->data;
    for(int i = 0;i < MAX_QUEUE_SIZE; i++){
        if(i <= lq->front || i > lq->rear){
            printf(" | ");
        }else{
            printf("%d |", lq->data[i]);
        }
    }
    printf("\n");
}

static int is_full(Queue * q)
{
    LinearQueue *lq = (LinearQueue *)q->data;
    if(lq->rear == MAX_QUEUE_SIZE -1)
    {
        return 1;
    }
    else{
        return 0;
    }
}
static int is_empty(Queue * q)
{
    LinearQueue *lq = (LinearQueue *)q->data;
    if(lq->front == lq->rear){
        return 1;
    }
    else{
        return 0;
    }
}
static void en_queue(Queue * q, element item){
    LinearQueue *lq = (LinearQueue *)q->data;
    if(is_full(q)){
        error("큐가 포화상태입니다.");
        return;
    }
    lq->data[++(lq->rear)] = item;
}
static int de_queue(Queue * q){
    LinearQueue *lq = (LinearQueue *)q->data;
    if(is_empty(q)){
        error("큐가 공백상태입니다.");
        return -1;
    }
    int item = lq->data[++(lq->front)];
    return item;
}
static void destroy(Queue *q){
    free(q->data);
    free(q->ops);
    free(q);
}
Queue * create_linear_queue(){
    Queue * queue = malloc(sizeof(Queue));
    queue->data = malloc(sizeof(LinearQueue));
    (*(LinearQueue *)queue->data).rear = -1;
    (*(LinearQueue *)queue->data).front = -1;

    QueueOps * ops = malloc(sizeof(QueueOps));
    ops->init_queue = init_queue;
    ops->is_empty = is_empty;
    ops->is_full = is_full;
    ops->de_queue = de_queue;
    ops->en_queue = en_queue;
    ops->error =error;
    ops->queue_print = queue_print;

    queue->ops = ops;
    return queue;
}