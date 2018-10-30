#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXNUMSHAPES (10)

#define WINWIDTH (800)
#define WINHEIGHT (320)

#define SHAPEMIN (0)
#define SHAPEMAX (2)
#define XMIN (0)
#define XMAX (WINWIDTH)
#define YMIN 0
#define YMAX (WINHEIGHT)
#define RADMIN (10)
#define RADMAX (50)
#define RXMIN (10)
#define RXMAX (30)
#define RYMIN (10)
#define RYMAX (30)
#define WMIN (10)
#define WMAX (40)
#define HMIN (10)
#define HMAX (40)

#define REDMIN (0)
#define REDMAX (255)
#define GREENMIN (0)
#define GREENMAX (255)
#define BLUEMIN (0)
#define BLUEMAX (255)

#define OPMIN (0.6)
#define OPMAX (1.0)
#define PRECISION (100.0)

//prototypes
int main(void);
int prngInt(int iLow, int iHigh);
float prngIntFloat(float fLow, float fLigh, float precision);
void genRandomArtNumbers(int n);

int prngInt(int iLow, int iHigh) {
    int diff = (iHigh - iLow) + 1; // + 1 fixes rand()%MAX-1 issue
    return rand()%diff + iLow;
}//prngInt

float prngIntFloat(float fLow, float fHigh, float precision) {
    int iLow = (int)(fLow * precision);
    int iHigh = (int)(fHigh * precision);
    int diff = iHigh - iLow + 1;
    int random = rand()%diff + iLow;
    return (float)(random)/precision;
}//prngFloat

void genRandomArtNumbers(int n) {
    // Use functions prngInt and prngIntFloat, and the constants
    // declared above to print out random data as specified in the instructions.
    printf("%4s%4s%4s%4s%4s%4s%4s%4s%4s%4s%4s%4s%4s\n","CNT","SHA","X","Y","RAD","RX","RY","W","H","R","G","B","OP");
    for(int i = 0; i < n; i ++) {
        int sha = prngInt(SHAPEMIN,SHAPEMAX);
        int x = prngInt(XMIN,XMAX);
        int y = prngInt(YMIN,YMAX);
        int rad = prngInt(RADMIN,RADMAX);
        int rx = prngInt(RXMIN,RXMAX);
        int ry = prngInt(RYMIN,RYMAX);
        int w = prngInt(WMIN,WMAX);
        int h = prngInt(HMIN,HMAX);
        int r = prngInt(REDMIN,REDMAX);
        int g = prngInt(GREENMIN,GREENMAX);
        int b = prngInt(BLUEMIN, BLUEMAX);
        float op = prngIntFloat(OPMIN, OPMAX, PRECISION);

        printf("%4d",i);    // Print shape counter "CNT"
        printf("%4d",sha);  // Print shape "SHA"
        printf("%4d",x);    // Print shape counter "X"
        printf("%4d",y);    // Print shape "Y"
        printf("%4d",rad);  // Print circle radius "RAD"
        printf("%4d",rx);   // Print ellipse c radius "RX"
        printf("%4d",ry);   // Print ellipse y radius "RY"
        printf("%4d",w);    // Print rect width "W"
        printf("%4d",h);    // Print rect height "H"
        printf("%4d",r);    // Print colour "RED"
        printf("%4d",g);    // Print colour "GREEN"
        printf("%4d",b);    // Print colour "BLUE"
        printf("%4.1f",op);   // Print opacity "OP"
        printf("\n");
    }
}//genRandomArtNumbers

int main(void){
    genRandomArtNumbers(MAXNUMSHAPES);
    return EXIT_SUCCESS;
}//main