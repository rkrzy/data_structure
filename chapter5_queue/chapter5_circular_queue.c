#include "queue_interface.h"

typedef struct{
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
}CircularQueue;


static void error(char * message){
    fprintf(stderr, "%s\n", message);
    exit(1);
}

static void init_queue(Queue * q){
    (*(CircularQueue *)q->data).rear = 0;
    (*(CircularQueue *)q->data).front = 0;
}



static int is_full(Queue * q)
{
    CircularQueue *cq = (CircularQueue *)q->data;
    return((cq->rear + 1) % MAX_QUEUE_SIZE == cq->front);
}
static int is_empty(Queue * q)
{
    CircularQueue *cq = (CircularQueue *)q->data;
    return (cq->front == cq->rear);
}
static void queue_print(Queue * q){
    CircularQueue *cq = (CircularQueue *)q->data;
    printf("QUEUE(front=%d rear=%d = ", cq->front, cq->rear);
    if(!is_empty(q)){
        int i = cq->front;
        do{
            i = (i+1) % (MAX_QUEUE_SIZE);
            printf("%d | ", cq->data[i]);
            if(i == cq->rear)
                break;
        } while (i != cq->front);
    }
    printf("\n");
}
static void en_queue(Queue * q, element item){
    CircularQueue *cq = (CircularQueue *)q->data;
    if(is_full(q)){
        error("큐가 포화상태입니다.");
        return;
    }
    cq->rear = (cq->rear+1)%MAX_QUEUE_SIZE;
    cq->data[cq->rear] = item;
}
static int de_queue(Queue * q){
    CircularQueue *cq = (CircularQueue *)q->data;
    if(is_empty(q)){
        error("큐가 공백상태입니다.");
        return -1;
    }
    cq->front = (cq->front+1)%MAX_QUEUE_SIZE;
    return cq->data[cq->front];
}

static void destroy(Queue *q){
    free(q->data);
    free(q->ops);
    free(q);
}
Queue * create_circular_queue(){
    Queue * queue = malloc(sizeof(Queue));
    queue->data = malloc(sizeof(CircularQueue));
    (*(CircularQueue *)queue->data).rear = 0;
    (*(CircularQueue *)queue->data).front = 0;

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