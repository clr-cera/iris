#include "graphics.h"
#include <Eigen/Dense>
#include <cmath>

using Eigen::Matrix4d;
using Eigen::Vector3d;
using Eigen::Vector4d;

Matrix4d Lib::CreateTranslationMatrix(Vector3d position) {
  Matrix4d m(4,4);
  m << 1,           0,           0,           position[0],
       0,           1,           0,           position[1],
       0,           0,           1,           position[2],
       0,           0,           0,                     1;

  return m;
}

Matrix4d Lib::CreateScaleMatrix(Vector3d scale) {
  Matrix4d m(4,4);
  m << scale[0],    0,           0,           0,
       0,           scale[1],    0,           0,
       0,           0,           scale[2],    0,
       0,           0,           0,           1;

  return m;
}

Matrix4d Lib::CreateRotationMatrix(Vector3d rotation) {
  Matrix4d rX(4,4), rY(4,4), rZ(4,4);

  rX << 1,    0,                   0,                  0,
        0,    cos(rotation[0]),    -sin(rotation[0]),  0,
        0,    sin(rotation[0]),    cos(rotation[0]),   0,
        0,    0,                   0,                  1;

  rY << cos(rotation[1]),    0,    sin(rotation[1]),   0,
        0,                   1,    0,                  0,
        -sin(rotation[1]),   0 ,   cos(rotation[1]),   0,
        0,                   0,    0,                  1;

  rZ << cos(rotation[2]),    -sin(rotation[2]),  0,    0,
        sin(rotation[2]),    cos(rotation[2]),   0,    0,
        0,                   0,                  1,    0,
        0,                   0,                  0,    1;

  return rZ*rY*rX;
}
Vertex::Vertex(Vector3d position, Vector3d color):
  color(color), 
  position(Vector4d(position,1)) {}

void Vertex::transformVertex(Matrix4d TRS) {
  this->position = TRS * this->position;
}

Triangle::Triangle(Vertex a, Vertex b, Vertex c): vertexList{a,b,c} {}

void Triangle::transformTriangle(Matrix4d TRS) {
  for(int i = 0; i < 3; i++) {
    vertexList[i].transformVertex(TRS);
  } 
}
