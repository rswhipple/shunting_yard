#include "../inc/queue.h"
#include "../inc/stack.h"

queue_t create_queue()
{
  queue_t new_queue = {
    .stack_1 = {.top = -1},
    .stack_2 = {.top = -1},
    .front = NULL,
    .is_empty = is_empty,
    .push = push,
    .pop = pop
  };
  return new_queue;
}

int en_queue(queue_t* queue, char* token)
{
    if (token == NULL) {
        printf("token is null");
        return EXIT_FAILURE;
    }

    // If queue is empty, set front to token
    if (queue->is_empty(&queue->stack_1)) {
        queue->front = token;
    } 

    // Reorder stack_1 to stack_2 to push token    
    while (!queue->is_empty(&queue->stack_1)){
        queue->push(&queue->stack_2, pop(&queue->stack_1));
    }
    
    // Push token to stack_2
    queue->push(&queue->stack_2, token);

    // Reorder stack_2 to stack_1
    while (!queue->is_empty(&queue->stack_2)) {
        queue->push(&queue->stack_1, pop(&queue->stack_2));
    }

    return EXIT_SUCCESS;
}

char* de_queue(queue_t* queue) 
{
    // If queue is empty, return NULL
    if (queue->is_empty(&queue->stack_1)) {
        return NULL;
    }

    // Pop from stack_1
    char* token = queue->pop(&queue->stack_1);

    // Set front to new front
    if (!queue->is_empty(&queue->stack_1)) {
        queue->front = queue->stack_1.data[queue->stack_1.top];
    }

    return token;
}

bool is_queue_empty(queue_t* queue)
{
    return queue->is_empty(&queue->stack_1);
}