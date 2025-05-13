
#include <time.h>
#include "chapter5_queue/queue_interface.h"

extern Queue *create_circular_queue();
extern Queue *create_linear_queue();
int main() {
    Queue * queue = create_linear_queue();

    srand(time(NULL));
    for(int i = 0; i < 100; i++){
        if(i % 5 == 0){
            queue->ops->en_queue(queue, rand()%100);
        }
        queue->ops->queue_print(queue);
        if(i%10 == 0){
            queue->ops->de_queue(queue);
        }
        queue->ops->queue_print(queue);
    }


}
