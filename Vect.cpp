//
// Created by Liza Darwesh on 03/03/2022.
//

#include "Vect.h"
#include <math.h>

Vect::Vect() {
    x = 0;
    y = 0;
    z = 0;
}

Vect::Vect(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

double Vect::getX() { return x; }
double Vect::getY() { return y; }
double Vect::getZ() { return z; }

/* Calculate the length of the segment with pythagoras :)*/
double Vect::length() {
    return sqrt((x * x) + (y * y) + (z * z));
}

/* Dot product necessary for the angle calculation*/
double Vect::dot(Vect other) {
    return x * other.getX() + y * other.getY() + z * other.getZ();
}

/* Calculate the angle between the segment and the target vector */
double Vect::angle(Vect other) {
    double dot = this->dot(other);
    double vDot = (dot/ (this->length()*other.length()));

    if(vDot < -1.0) vDot = -1.0;
    if(vDot > 1.0) vDot = 1.0;
    return (acos(vDot));
}

/* Cross product to decide what direction to rotate in */
Vect Vect::cross(Vect other) {
    double x_ = y * other.getZ() - z * other.getY();
    double y_ = z * other.getX() - x * other.getZ();
    double z_ = x * other.getY() - y * other.getX();

    return Vect(x_, y_, z_);
}

/* Operation for vector/matrix calculations,
 * taken from a Github matrix calculation repository */

Vect Vect::operator + (const Vect &other) {
    return Vect(x + other.x, y + other.y, z + other.z);
}

Vect Vect::operator - (const Vect &other) {
    return Vect(x - other.x, y - other.y, z - other.z);
}

Vect Vect::operator * (const Vect &other) {
    return Vect(x * other.x, y * other.y, z * other.z);
}

Vect Vect::operator / (const Vect &other) {
    return Vect(x / other.x, y / other.y, z / other.z);
}

bool Vect::equals(Vect other) { //doublecheck if works
    if(other.x == x && other.y == y && other.z == z){
        return true;
    }

    return false;
}
