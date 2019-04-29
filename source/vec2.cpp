#include <iostream>
#include <math.h>
#include "vec2.hpp"

    Vec2& Vec2::operator+=(Vec2 const& v){
        x += v.x;
        y += v.y;
        return *this; 
    }

    Vec2& Vec2::operator-=(Vec2 const& v){
        x = x - v.x;
        y = y - v.y;
        return *this; 
    }

    Vec2& Vec2::operator*=(float s){
        x = x * s;
        y = y * s;
        return *this;
    }

    Vec2& Vec2::operator/=(float s){
        if (s == 0){
            std::cout << "illegal acion, division by zero. \n";
            return *this;
        } else {
        x = x / s;
        y = y / s;
        return *this;    
        }
    }

    float Vec2::norm() const{
        float result = sqrtf(x * x + y * y);
        return result;
    }

    Vec2 operator+(Vec2 const& u, Vec2 const& v){
        Vec2 ergebnis{u};
        ergebnis += v;
        return ergebnis;
    }

    Vec2 operator-(Vec2 const& u, Vec2 const& v){
        Vec2 ergebnis{u};
        ergebnis -= v;
        return ergebnis;
    }

    Vec2 operator*(Vec2 const& u, float s){
        Vec2 ergebnis{u};
        ergebnis *= s;
        return ergebnis;
    }

    Vec2 operator/(Vec2 const& u, float s){
        Vec2 ergebnis{u};
        ergebnis /= s;
        return ergebnis;
    }

    Vec2 operator*(float s, Vec2 const& v){
        Vec2 ergebnis{v};
        ergebnis *= s;
        return ergebnis;
    }