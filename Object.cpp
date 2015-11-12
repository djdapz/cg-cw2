#include "Object.h"

Material::Material():
    ambient(1.0f),
    diffuse(1.0f),
    specular(1.0f),
    glossiness(10.0f)
  {}

Object::Object(const glm::mat4 &transform, const Material &material):
    transform(transform),
    material(material)
  {}

/* TODO: Implement */
double Sphere::Intersect(const Ray &ray, IntersectInfo &info) const { return -1.0f; 
   glm::vec3 origin = ray.origin;
   glm::vec3 direction = ray.direction;
   
   double a = 1;
   double b = (2*(origin.x - center.x)*direction.x) + (2*(origin.y - center.y)*direction.y) + (2*(origin.z - center.z)*direction.z);
   double c = pow(origin.x-center.x, 2) + pow(origin.y-center.y, 2) + pow(origin.z-center.z, 2);

   double disc = b*b - 4*c;
   
   if(disc > 0){
       //intersection
       double r1 = ((-1*b - sqrt(disc))/2)-.00001;
       double dist;
       if(r1 > 0){
           dist = r1;
       }else{
           dist = ((sqrt(disc)-b)/2)-.00001;
       }
       return dist;
   }else{
       double dist = -1;
       return dist;
       
   }
   
}
// Function glm::dot(x,y) will return the dot product of parameters. (It's the inner product of vectors)

glm::vec3 Sphere::getCenter(){
    return center;
};

glm::vec3 Sphere::getColor(){
    return color;
};

double Sphere::getRadius(){
    return radius;
};

glm::vec3 Sphere::getNormalAt(glm::vec3 coord){
    glm::vec3 normal = glm::normalize(coord + glm::vec3(center.x*-1, center.y*-1, center.z*-1));
    return normal;
};

Sphere::Sphere(){
    center = glm::vec3(0,0,0);
    radius = 1.0;
    color = glm::vec3(.5,.6,.7);
};

Sphere::Sphere(glm::vec3 ct, double r, glm::vec3 cl){
    center = ct;
    radius = r;
    color = cl;
    
};



/* TODO: Implement */
double Plane::Intersect(const Ray &ray, IntersectInfo &info) const {
    glm::vec3 direction = ray.direction;
    double a = glm::dot(direction, normal);
    
    if(a == 0){
        //ray parallel
        return -1;
    }else{
        double negDist = distance * -1;
        glm::vec3 test = glm::vec3(normal.x*negDist, normal.y*negDist, normal.z*negDist);
        double val = glm::dot(normal, (ray.origin+test));
        val = -1*val/a;
        return val; 
     
        //info.hitPoint=ray.operator(val);
    }
};

glm::vec3 Plane::getNormal(){
    return normal;
};
double Plane::getDistance(){
    return distance;
}; 
glm::vec3 Plane::getColor(){
    return color;
};

Plane::Plane(){
    normal = glm::vec3(0,0,0);
    distance = 1.0;
    color = glm::vec3(.5,.6,.7);
};

Plane::Plane(glm::vec3 ct, double r, glm::vec3 cl){
    normal = ct;
    distance = r;
    color = cl;
};

/* TODO: Implement */
double Triangle::Intersect(const Ray &ray, IntersectInfo &info) const { return -1.0f; }
