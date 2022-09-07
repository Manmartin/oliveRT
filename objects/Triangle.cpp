#include <Triangle.hpp>

Triangle::Triangle(): p1(0), p2(0), p3(0), plane(0, 0) {}
Triangle::Triangle( Vec const &p1, Vec const &p2, Vec const &p3, Vec const &c, Num const &br ): p1(p1), p2(p2), p3(p3) {
   this->color = c;
   this->brightness = br;
   Vec v1 = p2 - p1;
   Vec v2 = p3 - p1;
   this->plane.point = this->p1;
   this->plane.normal = v1.cross(v2).normalice();
}
Triangle::Triangle( Triangle const &ref ) { *this = ref; }
Triangle::~Triangle() {}


Triangle    &Triangle::operator=( Triangle const &ref ) {
   this->p1 = ref.p1;
   this->p2 = ref.p2;
   this->p3 = ref.p3;
   this->plane = ref.plane;
   this->color = ref.color;
   this->brightness = ref.brightness;
   return *this;
}

bool  Triangle::intersec( Vec const &origin, Vec const &dir, Num &t ) const {

   if (this->plane.intersec(origin, dir, t)) {
      Vec p = origin + dir * t;
      
      Vec s1 = p2 - p1;
      Vec s2 = p3 - p2;
      Vec s3 = p1 - p3;
      
      Vec pv1 = p - p1;
      Vec pv2 = p - p2;
      Vec pv3 = p - p3;

      Num r1 = plane.normal.dot(s1.cross(pv1));
      Num r2 = plane.normal.dot(s2.cross(pv2));
      Num r3 = plane.normal.dot(s3.cross(pv3));
      return (r1 > 0 && r2 > 0 && r3 > 0) || (r1 < 0 && r2 < 0 && r3 < 0); 
   }
   return false;
}

bool  Triangle::getPointInfo( Vec const &point, Vec &normal ) const {
   (void)point;
   (void)normal;
   return false;
}
