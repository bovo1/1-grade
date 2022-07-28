#include <stdio.h>

int arraysum(int n, int a[])
{
	int sum = 0;
	int i = 0;
	for(i=0; i<n; i++)
	{
		sum += a[i];
	}
	return sum;
}

int main()
{
	int n,i,sum,avg;
	int count = 0;

	scanf("%d\n", &n);
	int score[100];
	for(i = 0; i<n; i++)
	{
		scanf("%d",&score[i]);
	}
	sum = arraysum(n,score);
	avg = sum / n;

	if(sum%n !=0)
	{
		avg++;
	}
	
	
	for(i=0; i<n; i++)
	{
		if(score[i]>=avg)
		{
			count++;
		}
	}
	
	printf("%d\n", count);
	
	return 0;
}