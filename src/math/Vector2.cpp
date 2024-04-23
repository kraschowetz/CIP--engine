#include "Vector2.h"

#include <cmath>

Vector2::Vector2(float x, float y){
    this->x = x;
    this->y = y;
}

Vector2 Vector2::normalized(){
    float len = lenght();
    if(len == 0){
        return Vector2(0.f, 0.f);
    }
    return (Vector2(x/len, y/len));
}

float Vector2::lenght(){
    return sqrt(x*x + y*y);
}

float Vector2::distanceTo(Vector2 v){
    return sqrt((x - v.x) * (x - v.x) + (y - v.y) * (y - v.y));
}

//float operators

Vector2 Vector2::operator+=(const Vector2 & p){   
    x += p.x;
    y += p.y;
    return *this;
}

Vector2 Vector2::operator*=(const Vector2 &p){
    x *= p.x;
    y *= p.y;
    return *this;
}

Vector2 Vector2::operator*=(const float f){
    x *= f;
    y *= f;
    return *this;
}

Vector2 Vector2::operator-=(const Vector2 &p){
    x -= p.x;
    y -= p.y;
    return *this;
}

Vector2 Vector2::operator/=(const Vector2 &p){
    x /= p.x;
    y /= p.y;
    return *this;
}

Vector2 Vector2::operator+(const Vector2 &p){
    Vector2 v = Vector2(this->x, this->y);
    v.x += p.x;
    v.y += p.y;
    return v;
}

Vector2 Vector2::operator*(const Vector2 &p){
    Vector2 v = Vector2(this->x, this->y);
    v.x *= p.x;
    v.y *= p.y;
    return v;
}

Vector2 Vector2::operator*(const float f){
    Vector2 v = Vector2(this->x, this->y);
    v.x *= f;
    v.y *= f;
    return v;
}

Vector2 Vector2::operator-(const Vector2 &p){
    Vector2 v = Vector2(this->x, this->y);
    v.x -= p.x;
    v.y -= p.y;
    return v;
}

Vector2 Vector2::operator/(const Vector2 &p){
    Vector2 v = Vector2(this->x, this->y);
    v.x /= p.x;
    v.y /= p.y;
    return v;
}