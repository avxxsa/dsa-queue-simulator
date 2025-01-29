#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for a single vehicle in the queue
typedef struct Vehicle {
    int id;  // Unique ID for the vehicle
    struct Vehicle* next;
} Vehicle;

// Queue structure
typedef struct {
    Vehicle* front;
    Vehicle* rear;
    int size;
} Queue;

// Function prototypes
void initQueue(Queue* q);
bool isQueueEmpty(Queue* q);
void enqueue(Queue* q, int vehicleId);
int dequeue(Queue* q);
int queueSize(Queue* q);

#endif
