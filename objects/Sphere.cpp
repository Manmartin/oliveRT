#include <Sphere.hpp>

static bool solveQuadratic( Num const &a, Num const &b, Num const &c, Num  &x0, Num &x1) {
    Num discr = b * b - 4 * a * c;
    if (discr < 0)
        return false;
    else if (discr == 0)
        x0 = x1 = -0.5 * b / a;
    else {
        Num q = (b > 0) 
            ? -0.5 * (b + std::sqrt(discr))
            : -0.5 * (b - std::sqrt(discr));
        x0 = q / a;
        x1 = c / q;
    }
    return true;
}

Sphere::Sphere(): center(0), r(0), r2(0) {}
Sphere::Sphere( Vec const &center, Num const &r, Vec const &c, Num const &br ): center(center), r(r), r2(r * r) { 
    this->color = c;
    this->brightness = br;
}
Sphere::Sphere( Sphere const &ref ) { *this = ref; }
Sphere::~Sphere() {}

Sphere  &Sphere::operator=( Sphere const &ref ) {
    this->center = ref.center;
    this->r = ref.r;
    this->r2 = ref.r2;
    this->color = ref.color;
    this->brightness = ref.brightness;
    return *this;
}

/* Using analytic solution */ 

bool Sphere::intersec( Vec const &origin, Vec const &dir, Num &t ) const {
    Num t0, t1;
    Vec     len = origin - this->center;
    Num     a = 1; // a = dir.dot(dir), if dir is normaliced, then a = 1
    Num     b = 2 * dir.dot(len);
    Num     c = len.dot(len) - this->r2; 
    if (!solveQuadratic(a, b, c, t0, t1)) return false;
    if (t0 > t1) std::swap(t0, t1);
    if (t0 < 0) {
        t0 = t1;
        if (t0 < 0) return false;
    }
    t = t0;
    return true;
}
bool Sphere::getPointInfo( Vec const &point, Vec &normal ) const {
    normal = point - this->center;
    normal.normalice();
    return true;
}

/* Debug Function */
std::ostream &operator<<( std::ostream &o, Sphere const &sp ) {
    o << "center: " << sp.center << ", r: " << sp.r << ", color: " << sp.color; 
    return o;
}
