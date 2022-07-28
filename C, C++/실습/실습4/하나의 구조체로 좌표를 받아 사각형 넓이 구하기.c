#include <stdio.h>
#include <math.h>

typedef struct Point
{
	int x;
	int y;
}Point;

typedef struct Ractangle
{
	Point lowerLeft;
	Point upperRight;
}Rectangle;

int main()
{
	Rectangle R;

	scanf("%d %d %d %d", &R.lowerLeft.x, &R.lowerLeft.y, &R.upperRight.x, &R.upperRight.y);

	int area;
	area = abs(R.upperRight.x - R.lowerLeft.x) * abs(R.upperRight.y - R.lowerLeft.y);
	printf("%d", area);

	return 0;

}

