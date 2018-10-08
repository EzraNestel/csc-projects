/*
 * Name: Ezra Nestel
 * UVicID: V00906949
 * Date: 2018/10/1
 * Assignment: Assignment 3, Part 2
 * File Name: V00906949A3P1.c
 * Description: Functions for solving different shapes
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define RADIUS (7.6)
#define HEIGHT (8.2)
//shape numbers
#define CIRCLE (0)
#define SPHERE (1)
#define CYLINDER (2)
#define CONE (3)
#define NOSHAPES (4)
#define MAXGEN (5)
#define FORMAT ("%d %-8s_%-9s=%7.1lf\n")
#define ERRMSG ("%d is not a recognized shape number\n")
//prototypes
int main(void);
double areaCircle(double);
double periCircle(double);
double volSphere(double);
double surfaceSphere(double);
double volCylinder(double, double);
double surfaceCylinder(double, double);
double volCone(double, double);
double surfaceCone(double, double);

// Your functions from A3P1 and A3P2 go here, but they shouldn't be submitted!
// Computes area of a circle with radius r
double areaCircle(double r) {
    return M_PI*r*r;
}//areaCircle

// Computes volume of a sphere with radius r
double surfaceSphere(double r) {
    return 4*M_PI*r*r;
}//surfaceSphere

// Computes volume of a cone with base radius r and height h
double surfaceCone(double r, double h) {
    return M_PI*r*(r+sqrt(r*r+h*h));
}//surfaceCone


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


// YOUR CODE STARTS HERE
// Modify this function according to the specification
void shapeCalculator(int shape) {
    if (shape == CIRCLE) {
        double aCircle = areaCircle(RADIUS);
        double pCircle = periCircle(RADIUS);

        printf(FORMAT, shape, "Circle", "Area", aCircle);
        printf(FORMAT, shape, "Circle", "Perimeter", pCircle);
    } else if(shape == SPHERE){
        double sSphere = surfaceSphere(RADIUS);
        double vSphere = volSphere(RADIUS);

        printf(FORMAT, shape, "Sphere", "Volume", vSphere);
        printf(FORMAT, shape, "Sphere", "Surface", sSphere);

    } else if(shape == CYLINDER){
        double sCylinder = surfaceCylinder(RADIUS,HEIGHT);
        double vCylinder = volCylinder(RADIUS,HEIGHT);

        printf(FORMAT, shape, "Cylinder", "Volume", vCylinder);
        printf(FORMAT, shape, "Cylinder", "Surface", sCylinder);

    } else if(shape == CONE){
        double sCone = surfaceCone(RADIUS,HEIGHT);
        double vCone = volCone(RADIUS,HEIGHT);

        printf(FORMAT, shape, "Cone", "Volume", vCone);
        printf(FORMAT, shape, "Cone", "Surface", sCone);

    } else {
        printf(ERRMSG, shape);
    }//cascaded if
}// shapeCalculator
// YOUR CODE ENDS HERE

int main(void) {
    int shape = 1;
    for (int k=0; k<MAXGEN; k++) {
        shape = rand() % NOSHAPES;
        shapeCalculator(shape);
    }//for
    return EXIT_SUCCESS;
}//main