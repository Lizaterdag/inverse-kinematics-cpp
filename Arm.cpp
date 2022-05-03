//
// Created by Liza Darwesh on 03/05/2022.
//

#include "Vect.h"
#include "Arm.h"
#include "ArmSegment.h"
#include <string>
#include <iostream>

#define numSegments 3

/* Creating the segments, in this case, 3 segments*/
Arm::Arm(){
    segments.emplace_back(20.0,0.0,300);
    segments.emplace_back(15.0,0.0,300);
    segments.emplace_back(10.0,0.0,300);
}

/* Updating location of the segments until target is reached */
void Arm::updateArm() {
    ArmSegment mountPoint(0.0,0.0,0) ;
    for(int i=0;i<numSegments;i++){
        segments[i].updateEndpoint(mountPoint);

        std::cout <<  segments[i].toString() + "\n";
        mountPoint = segments[i];
    }
    // Endpoint arm is endpoint last segement.
    endPoint = segments[segments.size()-1].endPoint;
}

/* If the last segment arrived at target, backup to each segment until end destination is notified. */
void Arm::moveEndpointToDest(Vect ep){
    int back = numSegments - 1 ;  // Last arm segment index.
    int loopcount = 0 ;

    while (!ep.equals(endPoint)) {
        if ( loopcount++ == 100 ) break ;
        while ( back >= 0 ) {
            segments[back].rotateMe(ep, endPoint) ;
            updateArm();
            back-- ;
        }

        back = numSegments - 1 ;
    }
}