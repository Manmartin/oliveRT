#ifndef SPHERE_HPP
# define SPHERE_HPP

# include <Object.hpp>

class Sphere: public Object {
    public:
        Vec center;
        Num r, r2;

        Sphere(); 
        Sphere( Vec const &center, Num const &r, Vec const &c, Num const &br = 0 );
        Sphere( Sphere const &ref );
        ~Sphere();

        Sphere  &operator=( Sphere const &ref );

        bool intersec( Vec const &origin, Vec const &dir, Num &t ) const;
        bool getPointInfo( Vec const &point, Vec &normal ) const;
};

/* Debug Function */
std::ostream &operator<<( std::ostream &o, Sphere const &sphere );

#endif
