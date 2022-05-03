//
// Created by Liza Darwesh on 03/05/2022.
//

#ifndef MOTION_AND_VISION_ARM_H
#define MOTION_AND_VISION_ARM_H


#include <string>
#include <vector>
#include "Vect.h"
#include "ArmSegment.h"



class Arm {

public:
    std::vector<ArmSegment> segments;
    Vect endPoint;

    Arm();
    void reset();

    void updateArm();
    void setArmAngle(double d, int armIndex);
    void moveEndpointToDest(Vect ep);

};

#endif