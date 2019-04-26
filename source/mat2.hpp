#ifndef MAT2_HPP
#define MAT2_HPP
#include <array>
#include "vec2.hpp"

// Mat2 definition

struct Mat2 {
    // Matrix layout:
    // e_00   e_01
    // e_10   e_11

    float e_00 = 1.0f;
    float e_01 = 0.0f;
    float e_10 = 0.0f;
    float e_11 = 1.0f;

    Mat2& operator*=(Mat2 const& m);

};

Mat2 operator*(Mat2 const& m1, Mat2 const& m2);

Vec2 operator*(Mat2 const& m, Vec2 const& v);
Vec2 operator*(Vec2 const& v, Mat2 const& m);
#endif