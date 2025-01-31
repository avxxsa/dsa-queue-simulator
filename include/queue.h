#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

// Structure for a Queue Node
typedef struct Node {
    int vehicle_id; // Each vehicle has a unique ID
    struct Node* next;
} Node;

// Queue structure
typedef struct Queue {
    Node* front;
    Node* rear;
    int size; // Keep track of the number of vehicles
} Queue;

// Function prototypes
Queue* createQueue();
void enqueue(Queue* q, int vehicle_id);
int dequeue(Queue* q);
int isQueueEmpty(Queue* q);
void displayQueue(Queue* q);

#endif
