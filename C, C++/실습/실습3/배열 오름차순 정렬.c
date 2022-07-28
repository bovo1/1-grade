#include <stdio.h>

int arraymax(int n, int a[])
{
	int i;
	int max = 0;
	int ind_max= 0;
	for(i=0;i<n;i++)
	{
		if(a[i]>max)
		{
			max = a[i];
			ind_max =i;
		}
	}
	return ind_max; //최댓값의 위치를 반환
}

int main()
{
	int A[100] = {0,};
	int n,i;
	int ind_max, temp;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%d", &A[i]);
	}
	
	for(i=n-1;i>0;i--)
	{
		ind_max = arraymax(i+1,A); //최대 위치
		temp = A[i];
		A[i] = A[ind_max];
		A[ind_max] = temp;
	}
	for(i=0;i<n;i++)
	{
		printf("%d", A[i]);
	}
	
}


