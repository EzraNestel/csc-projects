#include <stdio.h>
#include <stdlib.h>

#define WIN_WIDTH (500)
#define WIN_HEIGHT (300)
#define ID0 ("")
#define ID1 ("   ")
#define ID2 ("     ")

//prototypes
void openSVG(char *id, int w, int h);
void commentSVG(char *id, char *cmt);
void fillRectSVG(char *id, int x, int y, int w, int h, int r, int g, int b, float op);
void fillCircleSVG(char *id, int cx, int cy, int rad, int r, int g, int b, float op);
void fillEllipseSVG(char *id, int cx, int cy, int rx, int ry, int r, int g, int b, float op);
void drawCirclesRowSVG(char* id, int cx, int cy, int rad, int n, int r, int g, int b);
void closeSVG(char *id);
void prologueHTML5(void);
void drawTextH1HTML5(char *id, char *text, char *col);
void drawParaHTML5(char *id, char *text, char *col);
void epilogueHTML5(void);

void openSVG(char* id, int w, int h) {
    printf("%s<svg width=\"%d\" height=\"%d\">\n", id, w, h);
}//openSVG

void closeSVG(char* id) {
    printf("%s</svg>\n", id);
}//closeSVG

void commentSVG(char* id, char* cmt) {
    printf("%s<!--%s-->\n", id, cmt);
}//commentSVG

void fillRectSVG(char* id, int x, int y, int w, int h, int r, int g, int b, float op) {
    printf("%s<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"rgb(%d, %d, %d)\" fill-opacity=\"%.1f\"></rect>\n", id, x, y, w, h,r, g, b, op);
}//fillRectSVG

void fillCircleSVG(char* id, int cx, int cy, int rad, int r, int g, int b, float op) {
    printf("%s<circle cx=\"%d\" cy=\"%d\" r=\"%d\" fill=\"rgb(%d, %d, %d)\" fill-opacity=\"%.1f\"></circle>\n", id, cx, cy, rad, r, g, b, op);
}//fillCircleSVG

void fillEllipseSVG(char* id, int cx, int cy, int rx, int ry, int r, int g, int b, float op) {
    printf("%s<ellipse cx=\"%d\" cy=\"%d\" rx=\"%d\" ry=\"%d\" fill=\"rgb(%d, %d, %d)\" fill-opacity=\"%.1f\"></ellipse>\n", id, cx, cy, rx, ry, r, g, b, op);
}//fillEllipseSVG

void drawCirclesRowSVG(char *id, int cx, int cy, int rad, int n, int r, int g, int b) {
    // replace with your code
}//drawCirclesRowSVG

void drawShapesSVG(void) {
    openSVG(ID1, WIN_WIDTH, WIN_HEIGHT);
    commentSVG(ID1, "Define and paint SVG view box");
    fillRectSVG(ID2, 0, 0, WIN_WIDTH, WIN_HEIGHT, 245, 245, 220, 1.0);
    commentSVG(ID2, "Draw SVG shapes");
    fillCircleSVG(ID2, 50, 150, 40, 60, 249, 237, 0.8);
    fillRectSVG(ID2, 130, 120, 100, 60, 0, 255, 0, 0.7);
    fillEllipseSVG(ID2, 370, 150, 100, 40, 255, 0, 255, 0.6);
    drawCirclesRowSVG(ID2, 50, 50, 50, 5, 255, 0, 0);
    drawCirclesRowSVG(ID2, 50, 250, 50, 5, 0, 0, 255);
    closeSVG(ID1);
}//drawShapesSVG

void prologueHTML5(void) {
    printf("%s%s\n", ID0, "<!DOCTYPE html>");
    printf("%s%s\n", ID0, "<html>");
    printf("%s%s\n", ID0, "<head>");
    printf("%s%s\n", ID1, "<title>");
    printf("%s%s\n", ID2, "My First CSC 111 Page");
    printf("%s%s\n", ID1, "</title>");
    printf("%s%s\n", ID0, "</head>");
    printf("%s%s\n", ID0, "<body>");
    drawTextH1HTML5(ID1, "My CSC 111 HTML5/SVG page", "lime");
}//prologueHTML5

void epilogueHTML5(void) {
    drawParaHTML5(ID1, "SVG is a great skill for my co-op job resume", "blue");
    printf("%s%s\n", ID0, "</body>");
    printf("%s%s\n", ID0, "</html>");
}//epilogueHTML5

void drawTextH1HTML5(char* id, char* text, char* col) {
    printf("%s<h1 style=\"color:%s\">%s</h1>\n", id, col, text);
}//drawTextH1HTML5

void drawParaHTML5(char* id, char* text, char* col) {
    printf("%s<p style=\"color:%s\">%s</p>\n", id, col, text);
}//drawParaHTML5

int main(void) {
    prologueHTML5();
    drawShapesSVG();
    epilogueHTML5();
    return EXIT_SUCCESS;
}//main
