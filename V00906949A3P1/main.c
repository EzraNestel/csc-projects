/*
 * Name: Ezra Nestel
 * UVicID: V00906949
 * Date: 2018/10/1
 * Assignment: Assignment 3, Part 1
 * File Name: V00906949A3P1.c
 * Description: Functions for solving area of different shapes
 */
#include <stdio.h>
#include <math.h>
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



int main() {
    printf("%f\n",areaCircle(7.6));
    printf("%f\n",surfaceSphere(7.6));
    printf("%f\n",surfaceCone(7.6,8.2));


    return 0;
}