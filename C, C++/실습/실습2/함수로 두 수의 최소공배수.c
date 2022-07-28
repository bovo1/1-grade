#include <stdio.h>
#include <math.h>

int LCM(int a, int b);
int GCD(int a, int b);

int LCM(int a, int b)
{
	return a * b/ GCD(a,b);
}
	
int GCD(int a, int b)
{
	int tmp;
	if(a<b)
	{
		tmp = a;
		a=b;
		b=tmp;
	}
	while(b!=0)
	{
		tmp = a%b;
		a=b;
		b=tmp;
	}
	return a;
}

int main()
{
	int a,b;
	scanf("%d", &a);
	scanf("%d", &b);
	
	printf("%d", LCM(a,b));
	
	return 0;
	
}
		
