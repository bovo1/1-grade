#include <stdio.h>
#include <math.h>
#define MAX 1000

struct Point
{
	int x;
	int y;
};

double perimeter(struct Point Polygon[], int n)
{
	double result = 0.0;
	for (int i = 0; i < n - 1; i++)
	{
		result += sqrt((Polygon[i].x - Polygon[i + 1].x) * (Polygon[i].x - Polygon[i + 1].x) + (Polygon[i].y - Polygon[i + 1].y) * (Polygon[i].y - Polygon[i + 1].y));
	}
	result += sqrt((Polygon[n - 1].x - Polygon[0].x) * (Polygon[n-1].x - Polygon[0].x) + (Polygon[n-1].y - Polygon[0].y) * (Polygon[n-1].y - Polygon[0].y));

		return result;
}

int main()
{
	struct Point Polygon[MAX];

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &(Polygon[i].x), &(Polygon[i].y));
	}

	printf("%.2f", perimeter(Polygon,n));

	return 0;
}
