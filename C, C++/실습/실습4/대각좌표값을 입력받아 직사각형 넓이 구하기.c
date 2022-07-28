#include <stdio.h>
#include <math.h>

struct Point
{
	int x;
	int y;
};

int main()
{
	struct Point P1, P2;

	scanf("%d %d %d %d", &P1.x, &P1.y, &P2.x, &P2.y);

	int area;

	area = abs(P2.x - P1.x) * abs(P2.y - P1.y);

	printf("%d", area);

	return 0;
}