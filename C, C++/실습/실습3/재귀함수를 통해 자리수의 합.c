#include <stdio.h>

int sum(int n)
{
	if(n==0)
	{
		return 0;
	}
	else
	{
		return sum(n/10) + n % 10;
	}
}

int main()
{
	int i=0,x=0;
	
	scanf("%d", &x);
	
	i = sum(x);
	
	printf("%d", i);
}
