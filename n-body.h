#include <stdio.h>
#include <omp.h>

#define BODY_COUNT 4
const double PI = 3.141592653589f;
const double G = 6.67e-11f;

typedef struct {
    double x;
    double y;
    double z;
} data3D;


const data3D position[BODY_COUNT] = {
  { 0.0f, 0.0f, -1000.0f },
  { 0.0f, 200.0f, -1000.0f },
  { -200.0f, 0.0f, -1000.0f },
  { 0.0f, 0.0f, -800.0f },
};

const data3D speed[BODY_COUNT] = {
  { 0.0f, 0.0f, 0.0f },
  { -3.0f, -3.0f, -3.0f },
  { 3.0f, 3.0f, 3.0f },
  { 4.0f, -3.0f, 1.0f },
};

const data3D acceleration[BODY_COUNT] = {
  { 0.0f, 0.0f, 0.0f },
  { 0.0f, 0.0f, 0.0f },
  { 0.0f, 0.0f, 0.0f },
  { 0.0f, 0.0f, 0.0f },
};

const double mass[BODY_COUNT] = { 1e16f, 1e1f, 1e1f, 2e1f };

void updatePhysics(float deltaT);
void updateAcceleration(int bodyIndex);
void updateVelocity(int bodyIndex, float deltaT);
void updatePosition(int bodyIndex, float deltaT);