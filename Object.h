#pragma once

#include "Ray.h"

class Material {
  public:
    Material();
    glm::vec3 ambient; //Reflectivity in r/g/b channels
    glm::vec3 diffuse;   
    glm::vec3 specular;	
    float glossiness; //Specular intensity
    float reflection;
};

// The father class of all the objects displayed. Some features would be shared between objects, others will be overloaded.
class Object {
  public:
    Object(const glm::mat4 &transform = glm::mat4(1.0f), const Material &material = Material());
    //  The keyword const here will check the type of the parameters and make sure no changes are made
    //  to them in the function. It's not necessary but better for robustness

    virtual double Intersect(const Ray &ray, IntersectInfo &info) const { return 1; }
    glm::vec3 Position() const { return glm::vec3(transform[3][0], transform[3][1], transform[3][2]); }
    const Material *MaterialPtr() const { return &material; }

  protected:  //  The difference between protected and private is that the protected members will still be available in subclasses.
    glm::mat4 transform;  // Usually a transformation matrix is used to decribe the position from the origin.
    Material material;
};

//  For all those objects added into the scene. Describing them in proper ways and the implement of function Intersect() is what needs to be done.
//  Actually, it's also possible to use some other objects, but those geometries are easy to describe and the intersects are easier to calculate.
//  Try something else if you like, for instance, a box?

/* TODO: Implement */
class Sphere : public Object {
  private:
    glm::vec3   center;
    glm::vec3   color;
    double      radius;
    Material    material;
    
    
  public:
    virtual double Intersect(const Ray &ray, IntersectInfo &info) const;  //  To figure out if the Ray hit this object.
    glm::vec3 getCenter();
    glm::vec3 getColor();
    double getRadius();
    glm::vec3 getNormalAt(glm::vec3 coord);
    
    Sphere(glm::vec3, double, glm::vec3);
    Sphere();
    
};

/* TODO: Implement */
class Plane : public Object {
  private:
      glm::vec3  normal;
      double     distance; 
      glm::vec3  color;
      Material   material;
      
  public:
    virtual double Intersect(const Ray &ray, IntersectInfo &info) const;
    glm::vec3 getNormal();
    double getDistance(); 
    glm::vec3 getColor();
    const Material *MaterialPtr() const { return &material; }
    
    Plane(glm::vec3, double, glm::vec3);
    Plane();
    
    
};

/* TODO: Implement */
class Triangle : public Object {
  public:
    virtual double Intersect(const Ray &ray, IntersectInfo &info) const;
};
