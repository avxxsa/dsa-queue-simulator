#include "queue.h"

// Initialize queue
void initQueue(Queue* q) {
    q->front = q->rear = NULL;
    q->size = 0;
}

// Check if queue is empty
bool isQueueEmpty(Queue* q) {
    return (q->front == NULL);
}

// Add vehicle to queue
void enqueue(Queue* q, int vehicleId) {
    Vehicle* newVehicle = (Vehicle*)malloc(sizeof(Vehicle));
    if (!newVehicle) {
        printf("Memory allocation failed\n");
        return;
    }
    newVehicle->id = vehicleId;
    newVehicle->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newVehicle;
    } else {
        q->rear->next = newVehicle;
        q->rear = newVehicle;
    }
    q->size++;
}

// Remove and return vehicle from queue
int dequeue(Queue* q) {
    if (isQueueEmpty(q)) {
        return -1;  // Indicates queue is empty
    }
    
    Vehicle* temp = q->front;
    int id = temp->id;
    
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    q->size--;
    return id;
}

// Get queue size
int queueSize(Queue* q) {
    return q->size;
}
