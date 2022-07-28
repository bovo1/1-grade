#include <stdio.h>

int GCD(int a, int b)
{
	if(a%b ==0)
	{
		return b;
	}
	else
	{
		return GCD(b,a%b);
	}
	
}

int main()
{
	int x,y;
	int result=0;
	
	scanf("%d %d", &x, &y);
	
	printf("%d", GCD(x,y));
	
	return 0;
}
