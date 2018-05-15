#include "n-body.h"

void updateAcceleration(int bodyIndex){
    //@TODO 
}

void updateVelocity(int bodyIndex, float deltaT){
    //@TODO
}

void updatePosition(int bodyIndex, float deltaT){
    //@TODO
}

void updatePhysics(float deltaT){
  for(int i = 0; i < BODY_COUNT; i++) {
    updateAcceleration(i);
    updateVelocity(i, deltaT );
    updatePosition(i, deltaT );
  }
}