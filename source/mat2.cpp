#include <math.h>
#include "mat2.hpp"

// Memberfunktionen

Mat2& Mat2::operator*=(Mat2 const& m){
    float c_00 = e_00;
    float c_01 = e_01;
    float c_10 = e_10;
    float c_11 = e_11;
    e_00 = c_00 * m.e_00 + c_01 * m.e_10;
    e_01 = c_00 * m.e_01 + c_01 * m.e_11;
    e_10 = c_10 * m.e_00 + c_11 * m.e_10;
    e_11 = c_10 * m.e_01 + c_11 * m.e_11;
    return *this;
}

Mat2& Mat2::operator*=(float s){
    e_00 *= s;
    e_01 *= s;
    e_10 *= s;
    e_11 *= s;
    return *this;
}


float Mat2::det() const{
    float determinante = e_00 * e_11 - e_10 * e_01;
    return determinante;
}

// Freie Funktionen

Mat2 operator*(Mat2 const& m1, Mat2 const& m2){
    Mat2 matrix{m1};
    matrix *= m2;
    return matrix;
}

Vec2 operator*(Mat2 const& m, Vec2 const& v){
    Vec2 result{
        m.e_00 * v.x + m.e_01 * v.y,
        m.e_10 * v.x + m.e_11 * v.y,
    };
    return result;
}

Vec2 operator*(Vec2 const& v, Mat2 const& m){
        Vec2 result{
        m.e_00 * v.x + m.e_01 * v.y,
        m.e_10 * v.x + m.e_11 * v.y,
    };
    return result;
}

Mat2 operator*(Mat2 const& m, float lambda){
    Mat2 result{m};
    result *= lambda;
    return result;
}

Mat2 operator*(float lambda, Mat2 const& m){
    Mat2 result{m};
    result *= lambda;
    return result;
}

// Berechnet Inverse einer Matrix
Mat2 inverse(Mat2 const& m){
    float det_m = m.det();
    Mat2 result{};
    result.e_00 = m.e_11;
    result.e_01 = m.e_01 * -1;
    result.e_10 = m.e_10 * -1;
    result.e_11 = m.e_00;
    result *= (1.0f / det_m);
    return result;
}

// Gibt eine Transponierte Matrix zurück
Mat2 transpose(Mat2 const& m){
    Mat2 result{m.e_00, m.e_10, m.e_01, m.e_11};
    return result;
}

// Rotiert eine Matrix
Mat2 make_rotation_mat2(float phi){
    Mat2 rot_m{cos(phi), -sin(phi), sin(phi), cos(phi)};
    return rot_m;
}

