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
        x = x / s;
        y = y / s;
        return *this;
    }

    Vec2 operator+(Vec2 const& u, Vec2 const& v){
        Vec2 ergebnis{u.x + v.x, u.y + u.y};
        return ergebnis;
    }

    Vec2 operator-(Vec2 const& u, Vec2 const& v){
        Vec2 ergebnis{u.x - v.x, u.y - v.y};
        return ergebnis;
    }

    Vec2 operator*(Vec2 const& u, float s){
        Vec2 ergebnis{u.x * s, u.y * s};
        return ergebnis;
    }

    Vec2 operator/(Vec2 const& u, float s){
        Vec2 ergebnis{u.x / s, u.y / s};
        return ergebnis;
    }

    Vec2 operator*(float s, Vec2 const& v){
        Vec2 ergebnis{s * v.x, s * v.y};
        return ergebnis;
    }