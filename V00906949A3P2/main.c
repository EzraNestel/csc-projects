/*
 * Name: Ezra Nestel
 * UVicID: V00906949
 * Date: 2018/10/1
 * Assignment: Assignment 3, Part 2
 * File Name: V00906949A3P1.c
 * Description: Functions for solving different shapes
 */
#include <stdio.h>
#include <math.h>

// Computes area of a circle with radius r
// Copy and paste this function from your solution of problem 1 (A2P1)
double areaCircle(double r) {
    return M_PI*r*r;
}//areaCircle

// Computes perimeter of a circle with radius r
double periCircle(double r) {
    return 2*M_PI*r;
}//periCircle

// Computes volume of a sphere with radius r
double volSphere(double r) {
    return (4*M_PI*r*r*r)/3;
}//volSphere

// Computes volume of a cylinder with base radius r and height h
double volCylinder(double r, double h) {
    return h*areaCircle(r);
}//volCylinder

// Computes surface area of a cylinder with base radius r and height h
double surfaceCylinder(double r, double h) {
    return h*periCircle(r)+2*areaCircle(r);
}//surfaceCylinder

// Computes volume of a cone with base radius r and height h
double volCone(double r, double h) {
    return areaCircle(r)*h/3;
}//volCone



int main() {

    printf("%f\n",periCircle(10));
    printf("%f\n",volSphere(10));
    printf("%f\n",volCylinder(10,10));
    printf("%f\n",surfaceCylinder(10,10));
    printf("%f\n",volCone(10,10));

    /*
     * Perimeter of circle: 62.831853
Volume of sphere: 4188.790205
Volume of cylinder: 3141.592654
Surface of cylinder: 1256.637061
Volume of cone: 1047.197551
     */
    return 0;
}