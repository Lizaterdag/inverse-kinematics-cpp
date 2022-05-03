//
// Created by Liza Darwesh on 03/03/2022.
//

#ifndef MOTION_AND_VISION_VECT_H
#define MOTION_AND_VISION_VECT_H


class Vect {
private:

public:
    double x;
    double y;
    double z;

    Vect();
    Vect(double, double, double);

    double getX();
    double getY();
    double getZ();
    double length();
    bool equals(Vect other);

    double dot(Vect other);
    double angle(Vect other);
    Vect cross(Vect other);

    Vect operator + (const Vect &other);
    Vect operator - (const Vect &other);
    Vect operator * (const Vect &other);
    Vect operator / (const Vect &other);
};

#endif