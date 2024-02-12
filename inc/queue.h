#ifndef QUEUE_H
#define QUEUE_H

#include "header.h"

/* function prototypes queue.c */
queue_t create_queue();
int en_queue(queue_t* queue, char* token);
char* de_queue(queue_t* queue);
bool is_queue_empty(queue_t* queue);

#endif