#ifndef PLANE_HPP 
# define PLANE_HPP

# include <Object.hpp>

class Plane: public Object {
    public:
        Vec point;
        Vec normal;

        Plane(); 
        Plane( Vec const &p, Vec const &n, Vec const &c = 0, Num const &br = 0 );
        Plane( Plane const &ref );
        ~Plane();

        Plane  &operator=( Plane const &ref );

        bool intersec( Vec const &origin, Vec const &dir, Num &t ) const;
        bool getPointInfo( Vec const &point, Vec &normal ) const;
};

#endif
