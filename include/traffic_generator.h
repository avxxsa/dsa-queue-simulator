#ifndef TRAFFIC_GENERATOR_H
#define TRAFFIC_GENERATOR_H

#include "queue.h"

// Function prototype for generating traffic
void generateTraffic(Queue* laneA, Queue* laneB, Queue* laneC, Queue* laneD, int numVehicles);

#endif