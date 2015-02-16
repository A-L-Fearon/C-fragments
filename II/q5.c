#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct point {
	int x,y;
};

struct rect {
	struct point ne,se,sw,nw;
};

int area(struct rect *rect);

int main(int arg){

	int i;

	struct point points[4];

	struct rect rectangle;

	printf("Please enter the coordinates for the triangle in the following format: \n");
	printf("Point 1 = NE, Point 2 = SE, Point 3 = SW, Point 4 = NW \n Please put a spcae between the x and y\n");

	for(i=0; i < 4; i++){
		printf("Point %d:", (i + 1));
		scanf("%d %d", &points[i].x, &points[i].y);
	}

	rectangle.ne = points[0];
	rectangle.se = points[1];
	rectangle.sw = points[2];
	rectangle.nw = points[3];

	printf("The area of a triangle with the given coordinates is: %d\n",area(&rectangle));
}

int area(struct rect *rect){
	int len = (rect->ne.x - rect->nw.x);
	int wid = (rect->nw.y - rect->sw.y);

	return len * wid;
}