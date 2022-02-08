/* Author: Liza Darwesh
* Repositor not yet finished
*/

#include <iostream>
#include <vector>
#include <cstdlib>   // rand and srand
#include <ctime>
#include <cmath>
#include <math.h>
#include <sstream>
#include <fstream>

using namespace std;

#define constraint_a 20
#define constraint_b 15
#define constraint_c 10

/* Calculate the angle between the segment and the target vector*/
double dotProduct(vector<double> vect, vector<double> target_vec) {
    double dot = ((vect[0]*target_vec[0]) + (vect[1]*target_vec[1]));
    double angle = acos(dot);
    cout << "angle =  " << angle<< "\n";
    return angle;
}
/* Take the normalized vector,
 * Calculate the rotated endpoint
 * Extend the vector to its own segment length
 * Move the new coordinate to its segment end, instead of the origin
 * If cross is negative, rotate clockwise
 * If cross is positive, rotate counterclockwise
 * */
vector<double> rotate(vector<double> vect, double dot, double length, vector<double> begin_vec, double cross){

    dot = (dot * 180 / M_PI);
    if (cross == 0){
        cout << "already there";
        return vect;
    }
    else if (cross > 0){

        double new_x = (begin_vec[0]) + (length * sin(dot));
        double new_y = (begin_vec[1]) + (length * cos(dot));

        vect[0] = new_x;
        vect[1] = new_y;

//        for (auto i = vect.begin(); i != vect.end(); ++i)
//            cout << *i << " ";
        return vect;

    } else{
        dot =  (2*M_PI) - dot;
        double new_x = (begin_vec[0]) + (length * sin(dot));
        double new_y = (begin_vec[1]) + (length * cos(dot));

        vect[0] = new_x;
        vect[1] = new_y;

//        for (auto i = vect.begin(); i != vect.end(); ++i)
//            cout << *i << " ";

        return vect;
    }
}

/* Generate random targetvector */
//TODO: fix it to vector
double* targetPoint(){
    int upper = 45;
    int lower = -45;

    double x = (rand() % (upper * 2)) + lower;
    double y = (rand() % 46);
    cout << x<< "\n";
    cout << y<< "\n";
    double vect_Target[] = {x,y};
    return vect_Target;
}

/*
 * Normalize the vectors to one
 * */
vector<double> normalize(vector<double> vect){
   double x = vect[0];
   double y = vect[1];
   double z = vect[2];

   double length = sqrt((x * x) + (y * y) + (z * z));
   x = x / length;
   y = y / length;
   z = z / length;

   vect[0] = x;
   vect[1] = y;
   vect[2] = z;

   return vect;
}

/* if cross is negative, rotate right,
 * if positive, rotate left,
 * if zero, dont rotate */
double crossProduct(vector<double> vect, vector<double> target_vec)
{
    /* if cross is negative, rotate right,
     * if positive, rotate left,
     * if zero, dont rotate */
    double cross = ((vect[0]*target_vec[1]) - (vect[1]*target_vec[0]));
    cout << "cross z =  " << cross<< "\n";
    return cross;
}

int main() {
    srand(time(NULL));
    int length_a = 20;
    int length_b = 15;
    int length_c = 10;

    vector<double> beginpos_A{0.0, 0.0, 0.0};
    vector<double> beginpos_B{0.0, 20.0, 0.0};
    vector<double> beginpos_C{0.0, 35.0, 0.0};
    vector<double> eindpos_C{0.0,45.0,0.0};

    vector<double> target{10.0,4.0,0.0};

    vector<double> target_norm = normalize(target);
    vector<double> eindC_norm = normalize(eindpos_C);

    double dot = dotProduct(eindC_norm,target_norm);
    double cross = crossProduct(eindpos_C,target);
    eindpos_C = rotate(eindpos_C, dot, length_c, beginpos_C, cross );

    for (auto i = eindpos_C.begin(); i != eindpos_C.end(); ++i)
        cout << *i << " ";

    vector<double> beginC_norm = normalize(beginpos_C);

    dot = dotProduct(beginC_norm, target_norm);
    cross = crossProduct(beginC_norm,target);

    beginpos_C = rotate(beginpos_C, dot, length_b, beginpos_B, cross );
    for (auto i = beginpos_C.begin(); i != beginpos_C.end(); ++i)
        cout << *i << " ";


    return 0;
}
