#include <stdio.h>

int is_prime(int number);
//int primenumber(int number, int arr[], int n);

int main()
{
	int number = 0;
	int finprimenum = 0;
	int arr[1000] = {};

	scanf("%d", &number);
		
	if(number<7 || number>1000)
	{
		return 0;
	}

	int s = 0;
	
	for (int i = number; i > 1 ; i--)
	{
		if (is_prime(i) == 1)
		{
			arr[s] = i;
			s++;
		}
	}

	//finprimenum = primenumber(number, arr, a);
	for (int a = 0; a <= s; a++)
	{
		for (int b = 0; b <= s; b++)
		{
			for (int c = 0; c <= s; c++)
			{
				if (arr[a] + arr[b] + arr[c] == number)
				{
					if(arr[a]>1 && arr[b]>1 && arr[c]>1)
					{
							printf("%d %d %d ", arr[c], arr[b], arr[a]);
							return 0;
					}
				}
			}
		}
	}


	return 0;

}

int is_prime(int number)
{
	int i;
	for (i = 2; i * i <= number; i++)
	{
		if (number % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

