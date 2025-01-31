#include "queue.h"

// Function to create a queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}

// Function to add a vehicle to the queue
void enqueue(Queue* q, int vehicle_id) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vehicle_id = vehicle_id;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

// Function to remove a vehicle from the queue
int dequeue(Queue* q) {
    if (q->front == NULL) return -1; // Queue is empty

    Node* temp = q->front;
    int vehicle_id = temp->vehicle_id;
    q->front = q->front->next;

    if (q->front == NULL) q->rear = NULL;
    free(temp);
    q->size--;
    return vehicle_id;
}

// Function to check if the queue is empty
int isQueueEmpty(Queue* q) {
    return q->front == NULL;
}

// Function to display the queue
void displayQueue(Queue* q) {
    Node* temp = q->front;
    while (temp != NULL) {
        printf("Vehicle %d -> ", temp->vehicle_id);
        temp = temp->next;
    }
    printf("NULL\n");
}