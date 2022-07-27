/*
<해결방법>

먼저 세 개의 소수의 합으로 나타내고 싶은 숫자를 입력받습니다. 그리고 2부터 number 사이의 소수를 저장하기 위해서 arr배열을 정해주었습니다.
소수판별 함수를 통해서 입력받은 수부터 1보다 클때까지의 소수들을 arr 배열에 저장했습니다.
그리고 3중반복문과 조건문을 사용해서 배열들의 수를 더한 값이 number 값과 같다면 출력하도록 하였습니다.

제출일자 : 20190926
*/

#include <stdio.h>

int is_prime(int number);

int main()
{
	int number = 0;
	int arr[1000] = {};

	scanf("%d", &number);
	if(number < 7 || number>1000)
	{
		return 0;
	}

	int s = 0;
	for (int i = number; i >1 ; i--)
	{
		if (is_prime(i) == 1)
		{
			arr[s] = i;
			s++;
		}
	}

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
