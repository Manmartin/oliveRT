#include <Plane.hpp>

Plane::Plane(): point(0), normal(0) {}
Plane::Plane( Vec const &p, Vec const &n, Vec const &c, Num const &br ): point(p), normal(n) { 
    this->normal.normalice();
    this->color = c;
    this->brightness = br;
}
Plane::Plane( Plane const &ref ) { *this = ref; }
Plane::~Plane() {}

Plane  &Plane::operator=( Plane const &ref ) {
    this->point = ref.point;
    this->normal  = ref.normal;
    this->color = ref.color;
    this->brightness = ref.brightness;
    return *this;
}

bool Plane::intersec( Vec const &origin, Vec const &dir, Num &t ) const {
    Num denom = this->normal.dot(dir);
    if (std::abs(denom) > 1e-6) {
        Vec aux = this->point - origin;
        t = aux.dot(this->normal) / denom;
        return t >= 0;
    }
    return false;
}
bool Plane::getPointInfo( Vec const &point, Vec &normal ) const {
    (void)point;
    normal = this->normal;
    return true;
}
