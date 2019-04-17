#ifndef VEC2_HPP
#define VEC2_HPP

// Für Vektor im 2 Dimensionalen Raum
struct Vec2{

    float x = 0.0f;
    float y = 0.0f;

    Vec2& operator+=(Vec2 const& v);
    Vec2& operator-=(Vec2 const& v);
    Vec2& operator*=(float const s);
    Vec2& operator/=(float const s);

};

#endif //END_VEC2
