#include "graphics.h"
#include <Eigen/Dense>

Pipeline::Pipeline(){

}

void Pipeline::Run() {

}

void Pipeline::AddObject(Drawable object) {
  this->objectList.push_back(object);
}
