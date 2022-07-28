#include <stdio.h>
#include <math.h>

typedef struct Point
{
	int x;
	int y;
}Point;

void move(struct Point* P, int deltaX, int deltaY) //평행이동 함수
{
	(*P).x += deltaX;
	(*P).y += deltaY;
}

int main()
{
	Point P1, P2;
	int dx, dy;

	scanf("%d %d %d %d", &P1.x, &P1.y, &P2.x, &P2.y);
	scanf("%d %d", &dx, &dy);
	move(&P1,dx,dy);
	move(&P2,dx,dy);

	printf("%d %d %d %d", P1.x, P1.y, P2.x, P2.y);
}