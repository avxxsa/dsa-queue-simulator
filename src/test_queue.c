#include <stdio.h>
#include "queue.h"

int main() {
    Queue* q = createQueue();

    printf("Adding vehicles to queue...\n");
    enqueue(q, 101);
    enqueue(q, 102);
    enqueue(q, 103);

    printf("Current Queue: ");
    displayQueue(q);

    printf("Dequeueing a vehicle...\n");
    int vehicle = dequeue(q);
    printf("Vehicle %d has left the queue.\n", vehicle);

    printf("Updated Queue: ");
    displayQueue(q);

    return 0;
}