#ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H

typedef enum { RED, GREEN } LightState;

typedef struct {
    LightState state;
} TrafficLight;

void setLightState(TrafficLight* light, LightState state);
const char* getLightStateName(LightState state);

#endif
