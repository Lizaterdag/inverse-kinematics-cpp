//
// Created by Liza Darwesh on 01/12/2021.
//


#include "Arm.h"
#include "Vect.h"
#include <iostream>

using namespace std;

int main() {
    Arm a;
    cout << "CCD Inverse Kinematics has started\n";

   /* Target value*/
    Vect newDest(10.0, 10.0, 0.0);

    cout << "Target is: " + to_string(newDest.x) + ", " + to_string(newDest.y) + "\n";

    /* Move arm to new destination*/
    a.updateArm();

    a.moveEndpointToDest(newDest);

    cout << "\n Target Reached";
    return 0;

}
