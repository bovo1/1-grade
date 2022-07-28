#include <stdio.h>

int isexist(int B[], int nB, int x)
{
	int j;
	for(j=0; j<nB; j++)
	{
		if(x == B[j])
		{
			return 1;
		}
	}
	return 0;
}

int existcommonx(int A[], int nA, int B[], int nB)
{
	int i,j;
	int number_of_AnB = 0;
	for(i = 0; i<nA; i++)
	{
		if(isexist(A,nB,B[i]) == 1)
		{
			number_of_AnB ++;
		}
	}
	return number_of_AnB;
}

int main()
{
	int A[100] = {0,};
	int B[100] = {0,};
	int nA=0, nB=0, i;
	int number_of_AnB = 0;
	scanf("%d %d", &nA, &nB);
	
	for(i = 0; i<nA; i++)
	{
		scanf("%d", &A[i]);
	}
	for(i=0; i<nB; i++)
	{
		scanf("%d", &B[i]);
	}
	printf("%d",existcommonx(A, nA, B, nB));
	
	return 0;
	
}
