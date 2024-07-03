#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#include <list>
#include <Eigen/Dense>

using Eigen::Matrix4d;
using Eigen::Vector4d;
using Eigen::Vector3d;

using namespace std;

class Drawable;
class Pipeline;
class Lib;
class Triangle;
class Vertex;

class Drawable {
private:
  Matrix4d mLocalTranslationMatrix;
  Matrix4d mLocalRotationMatrix;
  Matrix4d mLocalScaleMatrix;
  
public:
  void setLocalPosition(Vector3d position);
  void setLocalRotation(Vector3d angles);
  void setLocalScale(Vector3d scale);
  Matrix4d ModelMatrix(); 

  virtual list<Triangle> getTriangles();
};



class Pipeline {
private:
  list<Drawable> objectList;

public:
  Pipeline();
  void AddObject(Drawable object);
  void Run();

};

class Lib {
private:

public:
  static Matrix4d CreateTranslationMatrix(Vector3d position);
  static Matrix4d CreateScaleMatrix(Vector3d scale);
  static Matrix4d CreateRotationMatrix(Vector3d rotation);
};

class Vertex {
private:
public:
  Vector4d position;
  Vector3d color;

  Vertex(Vector3d position, Vector3d color);
  void transformVertex(Matrix4d TRS);
};

class Triangle {
private:
public:
  Vertex vertexList[3];

  Triangle(Vertex a, Vertex b, Vertex c);
  void transformTriangle(Matrix4d TRS);
};


#endif
