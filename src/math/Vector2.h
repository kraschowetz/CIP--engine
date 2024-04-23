#pragma once

struct Vector2 
{
    //members
    public:
        float x, y;
    //methods
    public:
        Vector2() : x(0), y(0) {}
        Vector2(float x, float y);
        float lenght();
        float distanceTo(Vector2 v);
        Vector2 normalized();
    //operators
    public:
        Vector2 operator+=(const Vector2 &p);
        Vector2 operator*=(const Vector2 &p);
        Vector2 operator-=(const Vector2 &p);
        Vector2 operator/=(const Vector2 &p);
        Vector2 operator+(const Vector2 &p);
        Vector2 operator*(const Vector2 &p);
        Vector2 operator-(const Vector2 &p);
        Vector2 operator/(const Vector2 &p);

        Vector2 operator*=(const float f);
        Vector2 operator*(const float f);
};