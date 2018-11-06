#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ID0 ("")
#define ID1 ("   ")
#define ID2 ("     ")

#define FILENAME ("A5P4.html")
#define FOPENERR ("fopen error %s")
#define TABTITLE ("My CSC 111 Art")
#define WELCOME ("Welcome to my CSC 111 Webpage")
#define RESUME ("SVG is a great skill for my co-op job resume")
#define ANIMATIONTEXT ("To MOM")

#define WINWIDTH (800)
#define WINHEIGHT (320)

// helper macro to convert a value into a string
#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

#define MAXNUMSHAPES 100
#define STRSH (STR(MAXNUMSHAPES) " shapes generated")

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
#define FALLSHADE (1)
#define REDSHADE (2)
#define GREENSHADE (3)
#define BLUESHADE (4)
#define PURPLESHADE (5)
#define FAVORITESHADE (2)

#define SHADE (FAVORITESHADE)

#if SHADE == FALLSHADE
#define REDMIN (100)
#define REDMAX (255)
#define GREENMIN (100)
#define GREENMAX (255)
#define BLUEMIN (0)
#define BLUEMAX (100)
#elif SHADE == REDSHADE
#define REDMIN (200)
#define REDMAX (255)
#define GREENMIN (50)
#define GREENMAX (120)
#define BLUEMIN (0)
#define BLUEMAX (50)
#elif SHADE == GREENSHADE
#define REDMIN (0)
#define REDMAX (50)
#define GREENMIN (150)
#define GREENMAX (255)
#define BLUEMIN (50)
#define BLUEMAX (150)
#elif SHADE == BLUESHADE
#define REDMIN (0)
#define REDMAX (50)
#define GREENMIN (50)
#define GREENMAX (150)
#define BLUEMIN (150)
#define BLUEMAX (250)
#elif SHADE == PURPLESHADE
#define REDMIN (75)
#define REDMAX (150)
#define GREENMIN (50)
#define GREENMAX (130)
#define BLUEMIN (170)
#define BLUEMAX (255)
#elif SHADE == FAVORITESHADE
#define REDMIN (163)
#define REDMAX (255)
#define GREENMIN (68)
#define GREENMAX (178)
#define BLUEMIN (4)
#define BLUEMAX (42)
#endif //SHADE

#define OPMIN (0.6)
#define OPMAX (1.0)
#define PRECISION (100.0)

//prototypes
int main(void);
int prngInt(int iLow, int iHigh);
float prngFloat(float fLow, float fHigh, float precision);
FILE* createFile(char* fnam);
void prologue(FILE* ofp, char* winTabTitle, char* opening, char* col);
void epilogue(FILE* ofp, char* closing, char* col);
void drawHeader1HTML5(FILE* ofp, char* id, char* text, char* col);
void drawParaHTML5(FILE* ofp, char* id, char* text, char* col);
void openSVG(FILE* ofp, char* id, int w, int h);
void closeSVG(FILE* ofp, char* id);
void commentSVG(FILE* ofp, char* id, char* cmt);
void fillRectSVG(FILE* ofp, char* id, int x, int y, int w, int h, int r, int g, int b, float op);
void fillCircleSVG(FILE* ofp, char* id, int cx, int cy, int rad, int r, int g, int b, float op);
void fillEllipseSVG(FILE* ofp, char* id, int cx, int cy, int rx, int ry, int r, int g, int b, float op);
void textSwipeAnimateSVG(FILE* ofp, char* id, char* txt, int fsz, int x, int y, int r, int g, int b, float op);
void genRandomArtNumSet(int *sh, int *x, int *y, int *rad, int *rx, int *ry, int *w, int *h, int *r, int *g, int *b, float *op) ;
void genRandomArt(FILE *ofp, char *id, int nShapes);

int main(void){
    FILE *ofp = createFile(FILENAME);
    if (ofp == NULL){
        printf("createFile function not written yet\n");
    } else {
        prologue(ofp, TABTITLE, WELCOME, "red");
        genRandomArt(ofp, ID2, MAXNUMSHAPES);
        epilogue(ofp, RESUME, "blue");
    }//if
    return EXIT_SUCCESS;
}//main

int prngInt(int iLow, int iHigh) {
    int diff = (iHigh - iLow) + 1; // + 1 fixes rand()%MAX-1 issue
    return rand()%diff + iLow;
}//prngInt

float prngFloat(float fLow, float fHigh, float precision) {
    int iLow = (int)(fLow * precision);
    int iHigh = (int)(fHigh * precision);
    int diff = iHigh - iLow + 1;
    int random = rand()%diff + iLow;
    return (float)(random)/precision;
}//prngFloat


void genRandomArtNumSet(int *sh, int *x, int *y, int *rad, int *rx, int *ry, int *w, int *h, int *r, int *g, int *b, float *op) {

    *sh = *x = *y = *rad = *rx = *ry = *w = *h = *r = *g = *b = 0;
    *op = 1.0;

    *sh = prngInt(SHAPEMIN,SHAPEMAX);
    *x = prngInt(XMIN,XMAX);
    *y = prngInt(YMIN,YMAX);
    *rad = prngInt(RADMIN,RADMAX);
    *rx = prngInt(RXMIN,RXMAX);
    *ry = prngInt(RYMIN,RYMAX);
    * w = prngInt(WMIN,WMAX);
    *h = prngInt(HMIN,HMAX);
    *r = prngInt(REDMIN,REDMAX);
    *g = prngInt(GREENMIN,GREENMAX);
    *b = prngInt(BLUEMIN, BLUEMAX);
    *op = prngFloat(OPMIN, OPMAX, PRECISION);

}//genRandomArtNumbers

void genRandomArt(FILE *ofp, char *id, int nShapes) {
    int x, y, rad, rx, ry, w, h, r, g, b;
    float op;
    commentSVG(ofp, ID1, "Outline SVG viewbox");
    openSVG(ofp, ID1, WINWIDTH, WINHEIGHT);
    commentSVG(ofp, ID2, "Define and paint SVG view box");
    fillRectSVG(ofp, ID2, 0, 0, WINWIDTH, WINHEIGHT, 245, 245, 220, 1.0);
    commentSVG(ofp, ID2, "Draw SVG shapes");
    for (int k = 1; k <= nShapes; k++) {
        // Use the function genRandomArtNumSet to generate the random numbers
        // Use the function fillCircleSVG to create the SVG shapes
        int shape;
        genRandomArtNumSet(&shape, &x, &y, &rad, &rx, &ry, &w, &h, &r, &g, &b, &op);

        if(shape == 0) { // Circle
            fillCircleSVG(ofp, id, x, y, rad, r, g, b, op);
        } else if (shape == 1) { // Rectangle
            fillRectSVG(ofp, id, x, y, w, h, r, g, b, op);
        } else { // shape == 2 Ellipse
            fillEllipseSVG(ofp, id, x, y, rx, ry, r, g, b, op);
        }
    }//for
    commentSVG(ofp, ID2, "SVG animation");
    // Use the function textSwipeAnimateSVG to create the animated text
    textSwipeAnimateSVG(ofp, id, ANIMATIONTEXT, 40, 50, 250,255,255,255,1.0);
    closeSVG(ofp, ID1);
}// genRandomArt

FILE *createFile(char *fnam) {
    FILE* newFile = fopen(fnam,"w");
    if (newFile == NULL) {
        printf(FOPENERR);
    }
    return newFile;
    // Create a new file and return a real file pointer.
    // The name of the file is given in the parameter fnam

}//createFile

void prologue(FILE *ofp, char *winTabTitle, char *opening, char *col) {
    fprintf(ofp, "%s%s\n", ID0, "<!DOCTYPE html>");
    fprintf(ofp, "%s%s\n", ID0, "<html>");
    fprintf(ofp, "%s%s\n", ID0, "<head>");
    fprintf(ofp, "%s%s\n", ID1, "<title>");
    fprintf(ofp, "%s%s\n", ID2, winTabTitle);
    fprintf(ofp, "%s%s\n", ID1, "</title>");
    fprintf(ofp, "%s%s\n", ID0, "</head>");
    fprintf(ofp, "%s%s\n", ID0, "<body>");
    drawHeader1HTML5(ofp, ID1, opening, col);
}//prologue

void epilogue(FILE *ofp, char *closing, char *col) {
    drawParaHTML5(ofp, ID1, STRSH, col);
    drawParaHTML5(ofp, ID1, closing, col);
    fprintf(ofp, "%s%s\n", ID0, "</body>");
    fprintf(ofp, "%s%s\n", ID0, "</html>");
}//epilogue

void openSVG(FILE *ofp, char *id, int w, int h) {
    fprintf(ofp, "%s<svg width=\"%d\" height=\"%d\">\n", id, w, h);
}//openSVG

void closeSVG(FILE *ofp, char *id) {
    fprintf(ofp, "%s</svg>\n", id);
}//closeSVG

void fillRectSVG(FILE *ofp, char *id, int x, int y, int w, int h, int r, int g, int b, float op) {
    fprintf(ofp,
            "%s<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"rgb(%d, %d, %d)\" fill-opacity=\"%.1f\"></rect>\n",
            id, x, y, w, h, r, g, b, op);
}//fillRectSVG

void fillCircleSVG(FILE *ofp, char *id, int cx, int cy, int rad, int r, int g, int b, float op) {
    fprintf(ofp, "%s<circle cx=\"%d\" cy=\"%d\" r=\"%d\" fill=\"rgb(%d, %d, %d)\" fill-opacity=\"%.1f\"></circle>\n",
            id, cx, cy, rad, r, g, b, op);
}//fillCircleSVG

void fillEllipseSVG(FILE* ofp, char* id, int cx, int cy, int rx, int ry, int r, int g, int b, float op) {
    fprintf(ofp, "%s<ellipse cx=\"%d\" cy=\"%d\" rx=\"%d\" ry=\"%d\" fill=\"rgb(%d, %d, %d)\" fill-opacity=\"%.1f\"></ellipse>\n", id, cx, cy, rx, ry, r, g, b, op);
}//fillEllipseSVG

void defAnimateSwipeSVG(FILE *ofp, char *id, char *link, int f, int t, int b, int d) {
    fprintf(ofp, "%s<defs>\n", id);
    fprintf(ofp,
            "%s<animate xlink:href=\"#%s\" id=\"swipe\" attributeName=\"x\" from=\"%d\" to=\"%d\" begin=\"%ds\" dur=\"%ds\" />\n",
            id, link, f, t, b, d);
    fprintf(ofp, "%s</defs>\n", id);
}//defAnimateSwipeSVG

void textSwipeAnimateSVG(FILE *ofp, char *id, char *txt, int fsz, int x, int y, int r, int g, int b, float op) {
    defAnimateSwipeSVG(ofp, ID2, "defAnimateSwipeSVG", 500, 50, 0, 5);
    fprintf(ofp,
            "%s<text id=\"%s\" x=\"%d\" y=\"%d\" font-size=\"%d\" fill=\"rgb(%d, %d, %d)\" fill-opacity=\"%.1f\">%s</text>\n",
            id, "defAnimateSwipeSVG", x, y, fsz, r, g, b, op, txt);
}//textSwipeAnimateSVG

void commentSVG(FILE *ofp, char *id, char *cmt) {
    fprintf(ofp, "%s<!--%s-->\n", id, cmt);
}//commentSVG

void drawHeader1HTML5(FILE *ofp, char *id, char *text, char *col) {
    fprintf(ofp, "%s<h1 style=\"color:%s\">%s</h1>\n", id, col, text);
}//drawHeader1HTML5

void drawParaHTML5(FILE *ofp, char *id, char *text, char *col) {
    fprintf(ofp, "%s<p style=\"color:%s\">%s</p>\n", id, col, text);
}//drawParaHTML5