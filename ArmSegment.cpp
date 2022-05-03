//
// Created by Liza Darwesh on 03/05/2022.
//
#include <string>
#include <cmath>
#include "Vect.h"
#include "ArmSegment.h"

/* Arise of the segments :), with default values */
ArmSegment::ArmSegment(double length, double angle, double maxAngle) {

    Vect default_val(0,0,0);
    endPoint = default_val;

    Vect default_mount(0,0,0);
    mountPoint = default_mount;
    calculatedAngle=0;

    this->angle = angle;
    this->length = length;
    this->maxAngle = maxAngle;
}

/* Translation of the segment position*/
void ArmSegment::updateEndpoint(ArmSegment mountedOnArm) {
    calculatedAngle = mountedOnArm.calculatedAngle + angle;

    /* Angle is 90 degrees shifted counterclockwise*/
    endPoint.x = mountedOnArm.endPoint.x + (length * cos(toRadians(calculatedAngle)));
    endPoint.y = mountedOnArm.endPoint.y + (length * sin(toRadians(calculatedAngle)));

    mountPoint.x = mountedOnArm.endPoint.x;
    mountPoint.y = mountedOnArm.endPoint.y;
    mountPoint.z = mountedOnArm.endPoint.z;
}

/* never sure which one to use, so I created both Rad and Deg*/
double ArmSegment::toRadians(double angleInDegrees){
    return (angleInDegrees * M_PI)  / 180.0;
}

double ArmSegment::toDegrees(double radians) {
    return radians * (180.0 / M_PI);
}

/* Print the coordinates*/
std::string ArmSegment::toString() {
    return "start point: " + std::to_string(mountPoint.x) + ", " +
            std::to_string(mountPoint.y) +
           " end point :" + std::to_string(endPoint.x) + ", " + std::to_string(endPoint.y);
}

void ArmSegment::setAngle(double d) {
    this->angle = d;
}


/* Rotate current segment in direction of the endpoint. */
void ArmSegment::rotateMe(Vect targetEndpoint, Vect armEndpoint) {
    Vect r;//target
    Vect p;//current
    Vect cross;

    r.x = targetEndpoint.x - mountPoint.x;
    r.y = targetEndpoint.y - mountPoint.y;
    r.z = targetEndpoint.z - mountPoint.z;

    p.x = armEndpoint.x - mountPoint.x;
    p.y = armEndpoint.y - mountPoint.y;
    p.z = armEndpoint.z - mountPoint.z;

    double ang = toDegrees(p.angle(r));

    cross = r.cross(p);

    /* Which way to rotate */
    if ( ang < 10 ) {
        ang /= 1 ;
    }
    else if ( ang < 30 ) {
        ang /= 2 ;
    }
    else if ( ang < 60 ) {
        ang /= 3 ;
    }
    else {
        ang /= 4 ;
    }

    if (cross.z > 0) {
        angle = angle - ang;
    }
    else {
        angle = angle + ang;
    }
    if ( angle > maxAngle ) angle = maxAngle ;
    if ( angle < -maxAngle ) angle = -maxAngle ;
}