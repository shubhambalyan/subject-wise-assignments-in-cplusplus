#include <iostream>
#include <stdlib.h>
#include <graphics.h>
using namespace std;

#define MAX 20
#define ROUND(a) ((int)(a + 0.5))

#define LEFT_EDGE 0x1
#define RIGHT_EDGE 0x2
#define BOTTOM_EDGE 0x4
#define TOP_EDGE 0x8

#define INSIDE(a) (!a)
#define REJECT(a,b) (a & b)
#define ACCEPT(a,b) (!(a|b))
 
unsigned char encode(int x, int y, int xmin, int ymin, int xmax, int ymax) {
    
    unsigned char code = 0x00;

    if(x < xmin)
    	code = code | LEFT_EDGE;
    if(x > xmax)
    	code = code | RIGHT_EDGE;
    if(y < ymin)
    	code = code | BOTTOM_EDGE;
    if(y > ymax)
    	code = code | TOP_EDGE; 
 
    return code;
}

void swapPts(int * x1, int * y1, int * x2, int * y2) {
	int temp;

	/* Swap x coordinate */
	temp = *x1;
	*x1 = *x2;
	*x2 = temp;

	/* Swap y coordinate */
	temp = *y1;
	*y1 = *y2;
	*y2 = temp;
}

void swapCodes(unsigned char * c1, unsigned char * c2) {
	unsigned char temp;
	temp = *c1;
	*c1 = *c2;
	*c2 = temp;
}

void clipLine(int xmin, int ymin, int xmax, int ymax, int x1, int y1, int x2, int y2) {
	unsigned char code1, code2;
	int done = FALSE, draw = FALSE;
	float m;

	while(!done) {
		code1 = encode(x1, y1, xmin, ymin, xmax, ymax);
		code2 = encode(x2, y2, xmin, ymin, xmax, ymax);
		if(ACCEPT(code1, code2)) {
			done = TRUE;
			draw = TRUE;
		}
		else {
			if(REJECT(code1, code2))
				done = TRUE;
			else {
				/* Ensure that P1 is outside window */
				if(INSIDE(code1)) {
					swapPts(&x1, &y1, &x2, &y2);
					swapCodes(&code1, &code2);
				}
			}

			/* Use slope (m) to find line clip edge intersections */
			if(x2 != x1) 
				m = (y2 - y1) / (x2 - x1);
			if(code1 & LEFT_EDGE) {
				y1 += (xmin - x1) * m;
				x1 = xmin;
			}
			else {
				if(code1 & RIGHT_EDGE) {
					y1 += (xmax - x1) * m;
					x1 = xmax;
				}
				else {
					if(code1 & BOTTOM_EDGE) {
						/* Need to update x1 for non vertical lines only */
						if(x2 != x1) 
							x1 += (ymin - y1) / m;
						y1 = ymin;
					}
					else {
						if(code1 & TOP_EDGE) {
							if(x2 != x1)
								x1 += (ymax - y1) / m;
							y1 = ymax;
						}
					} 
				}
			}
		}
	}
	if(draw)
		line(ROUND(x1), ROUND(y1), ROUND(x2), ROUND(y2));
} 
 
 
int  main() {
    int n;
    int i, j;
    int ln[MAX][4];
    int clip[4];
    int gd = DETECT, gm;
 
    cout << "Enter the number of lines to be clipped: ";
    cin >> n;
 
    cout << "Enter the x- and y-coordinates of the line-endpoints:\n";
    for (i=0; i<n; i++) {
		cout << "\nLine " << i+1 << " : ";
    	for (j=0; j<4; j++)
		    cin >> ln[i][j];
    }
		
 
    cout << "Enter the x- and y-coordinates of the left-top and right-bottom corners\nof the clip window:\n";
    
    for (i=0; i<4; i++)
		cin >> clip[i];
 
    initgraph (&gd, &gm, "");
 
    rectangle (clip[0], clip[1], clip[2], clip[3]);

    for (i=0; i<n; i++)
		line (ln[i][0], ln[i][1], ln[i][2], ln[i][3]);
    getch();
    
    cleardevice();
    rectangle (clip[0], clip[1], clip[2], clip[3]);
    for (i=0; i<n; i++) { 
		clipLine(clip[0], clip[1], clip[2], clip[3], ln[i][0], ln[i][1], ln[i][2], ln[i][3]); 
    }
    getch();
    closegraph();
    return 0;
}
