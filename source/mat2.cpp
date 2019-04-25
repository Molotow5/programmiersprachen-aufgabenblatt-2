#include "mat2.hpp"

Mat2& Mat2::operator*=(Mat2 const& m){
    float c_00 = e_00;
    float c_01 = e_01;
    float c_10 = e_10;
    float c_11 = e_11;
    e_00 = c_00 * m.e_00 + c_01 * m.e_10;
    e_01 = c_00 * m.e_01 + c_01 * m.e_11;
    e_10 = c_01 * m.e_00 + c_11 * m.e_10;
    e_11 = c_01 * m.e_01 + c_11 * m.e_11;
    return *this;
}

Mat2 operator*(Mat2 const& m1, Mat2 const& m2){
    Mat2 matrix{
        m1.e_00 * m2.e_00 + m1.e_01 * m2.e_10,
        m1.e_00 * m2.e_01 + m1.e_01 * m2.e_11,
        m1.e_01 * m2.e_00 + m1.e_11 * m2.e_10,
        m1.e_01 * m2.e_01 + m1.e_11 * m2.e_11,
    };
    return matrix;
}