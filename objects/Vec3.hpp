#ifndef VEC3_HPP
# define VEC3_HPP

# include <iostream>
# include <cmath>

template < typename T >
class Vec3 {
    public:
        T x, y, z; 

        Vec3(): x(0), y(0), z(0) {}
        Vec3( T const value ): x(value), y(value), z(value) {}
        Vec3( T const x , T const y, T const z ): x(x), y(y), z(z) {}
        Vec3( Vec3 const &ref ) { *this = ref; }
        ~Vec3() {};

        Vec3    &operator=( Vec3 const &ref ) {
            this->x = ref.x;
            this->y = ref.y;
            this->z = ref.z;
            return *this;
        }
        Vec3    operator+( Vec3 const &ref ) const { return Vec3(x + ref.x, y + ref.y, z + ref.z); }
        Vec3    operator-( Vec3 const &ref ) const { return Vec3(x - ref.x, y - ref.y, z - ref.z); }
        Vec3    operator*( T const &n ) const { return Vec3(x * n, y * n, z * n); }
        
        T       length2( void ) const { return x * x + y * y + z * z; }
        T       length( void ) const { return std::sqrt(this->length2()); }
        Vec3    &normalice( void ) {
            T nor2 = this->length2(); 
            if (nor2 > 0) {
                T invNor = 1 / std::sqrt(nor2);
                x *= invNor, y *= invNor, z *= invNor;
            }
            return *this;
        }
        T       dot( Vec3 const &ref ) const { return x * ref.x + y * ref.y + z * ref.z; }
        Vec3    cross( Vec3 const &v ) const { return Vec3( y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x); }

        friend std::ostream &operator<<( std::ostream &o, Vec3 const &ray ) {
            o << ray.x << ' ' << ray.y << ' ' << ray.z;
            return o;
        }
};

#endif
