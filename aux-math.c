#include "./typos.h"

double magnitude(data3D aVector){
  double squareOfLength = 0.0;
  squareOfLength += aVector.x * aVector.x;
  squareOfLength += aVector.y * aVector.y;
  squareOfLength += aVector.z * aVector.z;
  return sqrt(squareOfLength);
}

void normalize(data3D aVector){
  double length = magnitude(aVector);
  aVector.x = aVector.x / length;
  aVector.y = aVector.y / length;
  aVector.z = aVector.z / length;
}

void invert(data3D aVector) {
  aVector.x *= -1.0;
  aVector.y *= -1.0;
  aVector.z *= -1.0;
}

void direction(data3D fromVector,data3D toVector, data3D resultVector) {
  resultVector.x = toVector.x - fromVector.x;
  resultVector.y = toVector.y - fromVector.y;
  resultVector.z = toVector.z - fromVector.z;
  normalize(resultVector);
}

double forceNewtonianGravity3D(double onMass, double becauseOfMass, data3D onPosition, data3D becauseOfPosition){
  double deltaX = becauseOfPosition.x - onPosition.x;
  double deltaY = becauseOfPosition.y - onPosition.y;
  double deltaZ = becauseOfPosition.z - onPosition.z;
  double distance = sqrt(deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ);

  if( distance == 0 ) {
    return 0;
  }

  double result = G * (onMass * becauseOfMass) /  (distance * distance);
  return result;
}

double computeAccel(double mass, double force ) 
{
  if( force == 0 ) 
  {
    return 0;
  }

  double result = force / mass;
  return result;
}

double computeVelo(double current, double previous, float deltaT) 
{
  return previous + (current * deltaT);
}

double computePos(double current, double previous, float deltaT) {
  return previous + (current * deltaT);
}

data3D computeAccel3D(double mass, data3D force) 
{
  data3D anAccelVector = {0, 0, 0};
  anAccelVector.x = computeAccel(mass, force.x);
  anAccelVector.y = computeAccel(mass, force.y);
  anAccelVector.z = computeAccel(mass, force.z);
  return anAccelVector;
}

data3D computeVelo3D(data3D accel, data3D prevVelo, float deltaT) 
{
  data3D adoubleVector = {0, 0, 0};
  adoubleVector.x = computeVelo( accel.x, prevVelo.x, deltaT );
  adoubleVector.y = computeVelo( accel.y, prevVelo.y, deltaT );
  adoubleVector.z = computeVelo( accel.z, prevVelo.z, deltaT );
  return adoubleVector;
}

data3D computePos3D(data3D velo, data3D prevPos, float deltaT) 
{
  data3D anPositionVector = {0, 0, 0};
  anPositionVector.x = computePos(velo.x, prevPos.x, deltaT);
  anPositionVector.y = computePos(velo.y, prevPos.y, deltaT);
  anPositionVector.z = computePos(velo.z, prevPos.z, deltaT);
  return anPositionVector;
}