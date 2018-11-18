/*  Name: Ezra Nestel
    UVicID: V00906949
    Date: 2018/11/14
    Assignment: Assignment 6, Part 4
    File name: V00906949A6P4
    Description: Creates 3d Animations
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define TEAPOT (1)
#define SOCCER (2)
#define SPACE (3)
#define APPLE (4)
#define CUBE (5)

#define FRAME (TEAPOT)

#if FRAME == SPACE
#define WIREFRAME_INP_FNAM ("A6spaceStation.txt")
#define WIREFRAME_OUT_FNAM ("A6spaceStation.html")
#define FRAMECENTERX (235)
#define FRAMECENTERY (235)
#define FRAMECOLOR ("magenta")
#define TRANSLATEX (50)
#define TRANSLATEY (400)
#define SCALEFACTOR (0.7)
#define REVOLUTIONDURATION (10)
#elif FRAME == TEAPOT
#define WIREFRAME_INP_FNAM ("A6teapot.txt")
#define WIREFRAME_OUT_FNAM ("A6teapot.html")
#define FRAMECENTERX (235)
#define FRAMECENTERY (235)
#define FRAMECOLOR ("cyan")
#define TRANSLATEX (50)
#define TRANSLATEY (400)
#define SCALEFACTOR (1.0)
#define REVOLUTIONDURATION (5)
#elif FRAME == SOCCER
#define WIREFRAME_INP_FNAM ("A6soccerBall.txt")
#define WIREFRAME_OUT_FNAM ("A6soccerBall.html")
#define FRAMECENTERX (235)
#define FRAMECENTERY (235)
#define FRAMECOLOR ("purple")
#define TRANSLATEX (50)
#define TRANSLATEY (400)
#define SCALEFACTOR (0.7)
#define REVOLUTIONDURATION (5)
#elif FRAME == CUBE
#define WIREFRAME_INP_FNAM ("A6cube.txt")
#define WIREFRAME_OUT_FNAM ("A6cube.html")
#define FRAMECENTERX (235)
#define FRAMECENTERY (235)
#define FRAMECOLOR ("red")
#define TRANSLATEX (50)
#define TRANSLATEY (400)
#define SCALEFACTOR (1.0)
#define REVOLUTIONDURATION (5)
#elif FRAME == APPLE
#define WIREFRAME_INP_FNAM ("A6apple.txt")
#define WIREFRAME_OUT_FNAM ("A6apple.html")
#define FRAMECENTERX (235)
#define FRAMECENTERY (235)
#define FRAMECOLOR ("limegreen")
#define TRANSLATEX (50)
#define TRANSLATEY (250)
#define SCALEFACTOR (0.4)
#define REVOLUTIONDURATION (5)
#endif //FRAME

#define FRAMECENTERRAD (5)
#define RSX (500.0)
#define RSY (500.0)
#define TX (250.0)
#define TY (250.0)
#define NO3DSEGMENTCOORDINATES (6)

#define ID0 ("")
#define ID1 ("   ")
#define ID2 ("     ")

#define FOPENERR ("fopen error file not found")
#define FCREATEERR ("fcreate error")
#define TITLE ("Welcome to my CSC 111 Wireframe")
#define CLOSING ("3-D wireframe")
#define TABTITLE ("CSC 111 Wireframe")

#define SVGWIDTH (500)
#define SVGHEIGHT (500)

#define SIZE2 (2)
#define SIZE3 (3)
typedef int Index;
typedef float Item;
typedef Item Vector2[SIZE2];
typedef Item Vector3[SIZE3];
typedef Item Matrix2[SIZE2][SIZE2];
typedef Item Matrix3[SIZE3][SIZE3];

int main(void);
FILE *createFile(char *fnam);
void prologue(FILE *ofp, char *winTabTitle, char *opening, char *col);
void epilogue(FILE *ofp, char *closing, char *col);
void openSVG(FILE *ofp, char *id, int w, int h);
void closeSVG(FILE *ofp, char *id);
void commentSVG(FILE *ofp, char *id, char *cmt);
void drawHeader1HTML5(FILE *ofp, char *id, char *text, char *col);
void drawParaHTML5(FILE *ofp, char *id, char *text, char *col);
void fillCircleSVG(FILE *ofp, char *id, int cx, int cy, int rad, int r, int g, int b, float op);
void fillRectSVG(FILE *ofp, char *id, int x, int y, int w, int h, int r, int g, int b, float op);
void fillEllipseSVG(FILE *ofp, char *id, int cx, int cy, int rx, int ry, int r, int g, int b, float op);

bool readCoordinates3DlineSegment(Vector3 pA, Vector3 pB);
void projectP3toP2(Index len, Matrix3 pm, Vector3 p3, Vector2 p2);
void initProjectionMatrix(Index size, Matrix3 pm);
void printMatrix(Index size, Matrix3 m);
void printVector(Index size, Vector3 v);
void mulMatrixVector(Index size, const Matrix3 m, const Vector3 vin, Vector3 vout);

void generateSVGLineSegments(FILE *ofp, char *id);
void lineSegmentSVG(FILE *ofp, char *id, Vector2 p2A, Vector2 p2B, char *col);
void transformSVG(FILE *ofp, char *id);

int main(void) {
    FILE *ofp = createFile(WIREFRAME_OUT_FNAM);
    printf("Generated wireframe %s\n", WIREFRAME_OUT_FNAM);
    prologue(ofp, TABTITLE, TITLE, "red");
    generateSVGLineSegments(ofp, ID2);
    epilogue(ofp, CLOSING, "blue");
    fclose(ofp);
    return EXIT_SUCCESS;
}//main

void generateSVGLineSegments(FILE *ofp, char *id) {
    Vector3 pA3, pB3; // 3D line segment from A to B
    Vector2 pA2, pB2; // 2D line segment from A to B
    Matrix3 pm;
    initProjectionMatrix(SIZE3, pm);
    while (readCoordinates3DlineSegment(pA3, pB3)) {
        projectP3toP2(SIZE3, pm, pA3, pA2);
        projectP3toP2(SIZE3, pm, pB3, pB2);
        lineSegmentSVG(ofp, id, pA2, pB2, FRAMECOLOR);
    }//while
}//generateSVGLineSegments

void initProjectionMatrix(Index size, Matrix3 pm){
    for (Index row = 0; row < size; row++) {
        for (Index col = 0; col < size; col++) {
            pm[row][col] = 0.0;
        }//for
    }//for
    pm[0][0] = RSX;
    pm[1][1] = RSY;
    pm[0][2] = TX;
    pm[1][2] = TY;
}//initProjectionMatrix

bool readCoordinates3DlineSegment(Vector3 pA, Vector3 pB) {
    // Read six floating point values in the form
    // x1 y1 z1 x2 y2 z2 from the standard input
    // into vectors (3D points) pA and pB
    // If all 6 values are read successfully, return true
    // If not all 6 values are read, returns false

    float x1 = 0;
    float y1 = 0;
    float z1 = 0;
    float x2 = 0;
    float y2 = 0;
    float z2 = 0;
    fflush(stdin);

    //printf("%d",scanf("%f %f %f %f %f %f",&x1,&y1,&z1,&x2,&y2,&z2));
    if (scanf("%f %f %f %f %f %f",&x1,&y1,&z1,&x2,&y2,&z2)) {
        pA[0] = x1;
        pA[1] = y1;
        pA[2] = z1;

        pB[0] = x2;
        pB[1] = y2;
        pB[2] = z2;
        return true;
    } else {
        return false;
    }



}//readCoordinates13DlineSegment

void mulMatrixVector(Index size, const Matrix3 m, const Vector3 v1, Vector3 v2) {


    v2[0] = m[0][0]*v1[0] + m[0][1]*v1[1] + m[0][2]*v1[2];
    v2[1] = m[1][0]*v1[0] + m[1][1]*v1[1] + m[1][2]*v1[2];
    v2[2] = m[2][0]*v1[0] + m[2][1]*v1[1] + m[2][2]*v1[2];

}//mulMatrixVector

void printMatrix(Index size, Matrix3 m){
    for (Index row = 0; row < size; row++) {
        for (Index col = 0; col < size; col++) {
            printf("%5.1f ", m[row][col]);
        }//for
        printf("\n");
    }//for
}//printMatrix

void printVector(Index size, Vector3 v) {
    for (Index k = 0; k < size; k++) printf("%5.1f ", v[k]);
    printf("\n");
}//printVector

void projectP3toP2(Index size, Matrix3 pm, Vector3 vi, Vector2 vo) {
    Vector3 vt;
    vi[2] = 1.0; // drop z-coordinate to project onto 2D
    mulMatrixVector(size, pm, vi, vt);
    vo[0] = vt[0];
    vo[1] = vt[1];
}//projectP3toP2

void lineSegmentSVG(FILE *ofp, char *id, Vector2 p2A, Vector2 p2B, char *col) {
    fprintf(ofp, "%s<line x1=\"%.1f\" y1=\"%.1f\" x2=\"%.1f\" y2=\"%.1f\" style=\"stroke: %s;\"></line>\n",
            id, p2A[0], p2A[1], p2B[0], p2B[1], col);
}//lineSegmentSVG

void print3DPoints(Vector3 pA3, Vector3 pB3) {
    printf("pA3 = (%.3f,%.3f,%.3f)\n", pA3[0], pA3[1], pA3[2]);
    printf("pB3 = (%.3f,%.3f,%.3f)\n", pB3[0], pB3[1], pB3[2]);
}//print3DPoints

void print2DPoints(Vector2 pA2, Vector2 pB2) {
    printf("pA2 = (%.3f,%.3f)\n", pA2[0], pA2[1]);
    printf("pB2 = (%.3f,%.3f)\n", pB2[0], pB2[1]);
}//print2DPoints

void transformSVG(FILE *ofp, char *id) {
    //draw approximate frame center to have a reference point
    //fillCircleSVG(ofp, id, FRAMECENTERX, FRAMECENTERY, FRAMECENTERRAD, 255, 0, 0, 1.0);
    // transform frame
    fprintf(ofp, "%s<g transform=\"translate(%d %d)\">\n", id, TRANSLATEX, TRANSLATEY);
    fprintf(ofp, "%s<g transform=\"scale(%.1f %.1f)\">\n", id, SCALEFACTOR, -SCALEFACTOR);
    fprintf(ofp, "%s<g transform=\"rotate(180, %d, %d)\">\n", id, FRAMECENTERX, FRAMECENTERY);
    fprintf(ofp, "%s<animateTransform attributeName=\"transform\"\n", id);
    fprintf(ofp, "%sbegin=\"0s\" dur=\"%ds\"\n", id, REVOLUTIONDURATION);
    fprintf(ofp, "%stype=\"rotate\" from=\"0 %d %d\" to=\"360 %d %d\"\n", id, FRAMECENTERX, FRAMECENTERY, FRAMECENTERX, FRAMECENTERY);
    fprintf(ofp, "%srepeatCount=\"indefinite\">\n", id);
    fprintf(ofp, "%s</animateTransform>\n", id);
}//transformSVG

void prologue(FILE *ofp, char *winTabTitle, char *title, char *col) {
    fprintf(ofp, "%s<!DOCTYPE html>\n", ID0);
    fprintf(ofp, "%s<html>\n", ID0);
    fprintf(ofp, "%s<head>\n", ID0);
    fprintf(ofp, "%s<title>\n", ID1);
    fprintf(ofp, "%s%s\n", ID2, winTabTitle);
    fprintf(ofp, "%s</title>\n", ID1);
    fprintf(ofp, "%s</head>\n", ID0);
    fprintf(ofp, "%s<body>\n", ID0);
    commentSVG(ofp, ID1, WIREFRAME_OUT_FNAM);
    //drawHeader1HTML5(ofp, ID1, title, col);
    openSVG(ofp, ID1, SVGWIDTH, SVGHEIGHT);
    transformSVG(ofp, ID2);
}//prologue

void epilogue(FILE *ofp, char *closing, char *col) {
    fprintf(ofp, "%s</g>\n", ID1);
    fprintf(ofp, "%s</g>\n", ID1);
    fprintf(ofp, "%s</g>\n", ID1);
    closeSVG(ofp, ID0);
    fprintf(ofp, "%s</body>\n", ID0);
    fprintf(ofp, "%s</html>\n", ID0);
}//epilogue

void openSVG(FILE *ofp, char *id, int w, int h) {
    fprintf(ofp, "%s<svg width=\"%d\" height=\"%d\">\n", id, w, h);
}//openSVG

void closeSVG(FILE *ofp, char *id) {
    fprintf(ofp, "%s</svg>\n", id);
}//closeSVG

void commentSVG(FILE *ofp, char *id, char *cmt) {
    fprintf(ofp, "%s<!--%s-->\n", id, cmt);
}//commentSVG

void drawHeader1HTML5(FILE *ofp, char *id, char *text, char *col) {
    fprintf(ofp, "%s<h1 style=\"color:%s\">%s</h1>\n", id, col, text);
}//drawHeader1HTML5

void drawParaHTML5(FILE *ofp, char *id, char *text, char *col) {
    fprintf(ofp, "%s<p style=\"color:%s\">%s</p>\n", id, col, text);
}//drawParaHTML5

void fillRectSVG(FILE *ofp, char *id, int x, int y, int w, int h, int r, int g, int b, float op) {
    fprintf(ofp,
            "%s<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"rgb(%d, %d, %d)\" fill-opacity=\"%.1f\"></rect>\n",
            id, x, y, w, h, r, g, b, op);
}//fillRectSVG

void fillCircleSVG(FILE *ofp, char *id, int cx, int cy, int rad, int r, int g, int b, float op) {
    fprintf(ofp, "%s<circle cx=\"%d\" cy=\"%d\" r=\"%d\" fill=\"rgb(%d, %d, %d)\" fill-opacity=\"%.1f\"></circle>\n",
            id, cx, cy, rad, r, g, b, op);
}//fillCircleSVG

void fillEllipseSVG(FILE *ofp, char *id, int cx, int cy, int rx, int ry, int r, int g, int b, float op) {
    fprintf(ofp,
            "%s<ellipse cx=\"%d\" cy=\"%d\" rx=\"%d\" ry=\"%d\" fill=\"rgb(%d, %d, %d)\" fill-opacity=\"%.1f\"></ellipse>\n",
            id, cx, cy, rx, ry, r, g, b, op);
}//fillEllipseSVG

FILE *createFile(char *fnam) {
    FILE *ofp = fopen(fnam, "w");
    if (ofp == NULL) {
        printf("%s %s", FCREATEERR, fnam);
        exit(EXIT_FAILURE);
    }//if
    return ofp;
}//createFile