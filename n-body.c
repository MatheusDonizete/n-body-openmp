#include "aux-math.c"

void updateAcceleration(int bodyIndex){
     data3D netForce = { 0, 0, 0 };

  for(int i = 0; i < BODY_COUNT; i++) 
  {
    data3D vectorForceToOther = {0, 0, 0};
    double scalarForceBetween = forceNewtonianGravity3D(mass[bodyIndex], mass[i], position[bodyIndex], position[i]);
    direction(position[bodyIndex], position[i], vectorForceToOther);

    vectorForceToOther.x *= scalarForceBetween;
    vectorForceToOther.y *= scalarForceBetween;
    vectorForceToOther.z *= scalarForceBetween;
    netForce.x += vectorForceToOther.x;
    netForce.y += vectorForceToOther.y;
    netForce.z += vectorForceToOther.z;
  }

  acceleration[bodyIndex] = computeAccel3D(mass[bodyIndex], netForce);
}

void updateVelocity(int bodyIndex, float deltaT){
      speed[bodyIndex] = computeVelo3D(acceleration[bodyIndex], speed[bodyIndex], deltaT);
}

void updatePosition(int bodyIndex, float deltaT){
    position[bodyIndex] = computePos3D(speed[bodyIndex], position[bodyIndex], deltaT);
}

void updatePhysics(float deltaT){
  for(int i = 0; i < BODY_COUNT; i++) {
    updateAcceleration(i);
    updateVelocity(i, deltaT);
    updatePosition(i, deltaT);
  }
}