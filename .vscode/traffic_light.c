#include "traffic_light.h"

void setLightState(TrafficLight* light, LightState state) {
    light->state = state;
}

const char* getLightStateName(LightState state) {
    return (state == GREEN) ? "GREEN" : "RED";
}
