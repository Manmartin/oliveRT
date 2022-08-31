#ifndef OBJECT_HPP
# define OBJECT_HPP

# include <Vec3.hpp>
# include <cmath> //sqrt, INFINITY

typedef double Num;
typedef Vec3<Num>   Vec;

class Object {
    public:
        Vec color = 0;
        Num brightness = 0;    
        
        virtual bool getPointInfo( Vec const &point, Vec &normal ) const = 0;
        virtual bool intersec( Vec const &origin, Vec const &dir, Num &t ) const = 0;
        virtual ~Object() {};
};

#endif
