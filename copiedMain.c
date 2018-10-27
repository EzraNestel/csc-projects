#include <stdio.h>
#include <stdlib.h>

#define ID0 ("")
#define ID1 ("   ")
#define ID2 ("     ")

#define WINWIDTH (500)
#define WINHEIGHT (300)

#define FILENAME ("A5P1.html")
#define FOPENERR ("fopen error %s")

// prototypes
int main(void);
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
void drawShapesSVG(FILE* ofp);
void drawCirclesRowSVG(FILE* ofp, char* id, int cx, int cy, int rad, int n, int r, int g, int b);

int main(void) {
    FILE* ofp = createFile(FILENAME);
    prologue(ofp, "My CSC 111 Art", "Welcome to my CSC 111 Webpage", "red");
    drawShapesSVG(ofp);
    epilogue(ofp, "SVG is a great skill for my co-op job resume", "blue");
    return EXIT_SUCCESS;
}//main

FILE* createFile(char* fnam) {
    // Create a new file.
    // The name of the file is given in the parameter fnam
    // Replace with your code here
}//createFile

void drawCirclesRowSVG(FILE* ofp, char* id, int cx, int cy, int rad, int n, int r, int g, int b){
    // Use the function fillCircleSVG to create the SVG circles
    // Replace with your code
}//drawCirclesRowSVG

void prologue(FILE* ofp, char* winTabTitle, char* opening, char* col) {
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

void epilogue(FILE* ofp, char* closing, char* col) {
    drawParaHTML5(ofp, ID1, closing, col);
    fprintf(ofp, "%s%s\n", ID0, "</body>");
    fprintf(ofp, "%s%s\n", ID0, "</html>");
}//epilogue

void openSVG(FILE* ofp, char* id, int w, int h) {
    fprintf(ofp, "%s<svg width=\"%d\" height=\"%d\">\n", id, w, h);
}//openSVG

void closeSVG(FILE* ofp, char* id) {
    fprintf(ofp, "%s</svg>\n", id);
}//closeSVG

void fillRectSVG(FILE* ofp, char* id, int x, int y, int w, int h, int r, int g, int b, float op) {
    fprintf(ofp, "%s<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"rgb(%d, %d, %d)\" fill-opacity=\"%.1f\"></rect>\n", id, x, y, w, h,r, g, b, op);
}//fillRectSVG

void fillCircleSVG(FILE* ofp, char* id, int cx, int cy, int rad, int r, int g, int b, float op) {
    fprintf(ofp, "%s<circle cx=\"%d\" cy=\"%d\" r=\"%d\" fill=\"rgb(%d, %d, %d)\" fill-opacity=\"%.1f\"></circle>\n", id, cx, cy, rad, r, g, b, op);
    printf("op[%d]=%.1f_\n", cx, op);
}//fillCircleSVG

void fillEllipseSVG(FILE* ofp, char* id, int cx, int cy, int rx, int ry, int r, int g, int b, float op) {
    fprintf(ofp, "%s<ellipse cx=\"%d\" cy=\"%d\" rx=\"%d\" ry=\"%d\" fill=\"rgb(%d, %d, %d)\" fill-opacity=\"%.1f\"></ellipse>\n", id, cx, cy, rx, ry, r, g, b, op);
}//fillEllipseSVG

void defAnimateSwipeSVG(FILE* ofp, char* id, char* link, int f, int t, int b, int d) {
    fprintf(ofp, "%s<defs>\n", id);
    fprintf(ofp, "%s<animate xlink:href=\"#%s\" id=\"swipe\" attributeName=\"x\" from=\"%d\" to=\"%d\" begin=\"%ds\" dur=\"%ds\" />\n", id, link, f, t, b, d);
    fprintf(ofp, "%s</defs>\n", id);
}//defAnimateSwipeSVG

void textSwipeAnimateSVG(FILE* ofp, char* id, char* txt, int x, int y, int r, int g, int b, float op){
    defAnimateSwipeSVG(ofp, ID2, "defAnimateSwipeSVG", 500, 50, 0, 5);
    fprintf(ofp, "%s<text id=\"%s\" x=\"%d\" y=\"%d\" fill=\"rgb(%d, %d, %d)\" fill-opacity=\"%.1f\">%s</text>\n", id, "defAnimateSwipeSVG", x, y, r, g, b, op, txt);
    printf("%s_x=%d_y=%d_r=%d_g=%d_b=%d_op=%.1f_\n", txt, x, y, r, g, b, op);
}//textSwipeAnimateSVG

void commentSVG(FILE* ofp, char* id, char* cmt) {
    fprintf(ofp, "%s<!--%s-->\n", id, cmt);
}//commentSVG

void drawHeader1HTML5(FILE* ofp, char* id, char* text, char* col) {
    fprintf(ofp, "%s<h1 style=\"color:%s\">%s</h1>\n", id, col, text);
}//drawHeader1HTML5

void drawParaHTML5(FILE* ofp, char* id, char* text, char* col) {
    fprintf(ofp, "%s<p style=\"color:%s\">%s</p>\n", id, col, text);
}//drawParaHTML5

void drawShapesSVG(FILE* ofp) {
    commentSVG(ofp, ID1, "Outline SVG viewbox");
    openSVG(ofp, ID1, WINWIDTH, WINHEIGHT);
    commentSVG(ofp, ID1, "Define and paint SVG view box");
    fillRectSVG(ofp, ID2, 0, 0, WINWIDTH, WINHEIGHT, 245, 245, 220, 1.0);
    commentSVG(ofp, ID2, "Draw SVG shapes");
    fillCircleSVG(ofp, ID2, 50, 150, 40, 60, 249, 237, 0.8);
    fillRectSVG(ofp, ID2, 130, 120, 100, 60, 0, 255, 0, 0.7);
    fillEllipseSVG(ofp, ID2, 370, 150, 100, 40, 255, 0, 255, 0.6);
    commentSVG(ofp, ID2, "SVG draw circles rows");
    drawCirclesRowSVG(ofp, ID2, 50, 50, 50, 5, 255, 0, 0);
    drawCirclesRowSVG(ofp, ID2, 50, 250, 50, 5, 0, 0, 255);
    commentSVG(ofp, ID2, "SVG animation");
    textSwipeAnimateSVG(ofp, ID2, "SVG Text Animation", 50, 255, 60, 249, 237, 1.0);
    closeSVG(ofp, ID1);
}//drawShapesSVG
