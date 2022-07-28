#include <stdio.h>

void swap(int* x, int* y)
{
	int tmp;
	tmp = *y;
	*y = *x;
	*x = tmp;
}

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	if (a > b)
		swap(&a, &b);
	if (b > c)
		swap(&b, &c);
	if (a > b)
		swap(&a, &b);

	printf("%d %d %d", a, b, c);

	return 0;
}