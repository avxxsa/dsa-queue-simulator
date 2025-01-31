#ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H

#include "queue.h"

// Enum for traffic light states
typedef enum { RED, GREEN } TrafficLightState;

// Structure for Traffic Light Control
typedef struct {
    TrafficLightState state;
    int lane_id;
} TrafficLight;

// Function prototypes
void initializeLights(TrafficLight lights[], int size);
void updateLights(TrafficLight lights[], Queue* laneA, Queue* laneB, Queue* laneC, Queue* laneD);
void displayLights(TrafficLight lights[], int size);

#endif