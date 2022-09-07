#ifndef TRIANGLE_HPP
# define TRIANGLE_HPP

# include <Plane.hpp>

class Triangle: public Object {
    public:
        Vec     p1, p2, p3;
        Plane   plane;

        Triangle(); 
        Triangle( Vec const &p1, Vec const &p2, Vec const &p3, Vec const &c = 0, Num const &br = 0 );
        Triangle( Triangle const &ref );
        ~Triangle();

        Triangle  &operator=( Triangle const &ref );

        bool    intersec( Vec const &origin, Vec const &dir, Num &t ) const;
        bool    getPointInfo( Vec const &point, Vec &normal ) const;
};

#endif
