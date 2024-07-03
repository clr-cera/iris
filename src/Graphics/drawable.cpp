#include "graphics.h"
#include <Eigen/Dense>

using Eigen::Matrix4d;
using Eigen::Vector3d;

Matrix4d Drawable::ModelMatrix() {
  return this->mLocalTranslationMatrix * this->mLocalRotationMatrix * this->mLocalScaleMatrix;
}

void Drawable::setLocalPosition(Vector3d position) {
  this->mLocalTranslationMatrix = Lib::CreateTranslationMatrix(position); 
}

void Drawable::setLocalScale(Vector3d scale) {
  this->mLocalScaleMatrix = Lib::CreateScaleMatrix(scale); 
}

void Drawable::setLocalRotation(Vector3d rotation) {
  this->mLocalRotationMatrix = Lib::CreateRotationMatrix(rotation);
}

