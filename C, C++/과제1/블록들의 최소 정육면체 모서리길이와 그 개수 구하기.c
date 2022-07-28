#include <stdio.h>
#include <math.h>

int LCM(int x, int y); //최소공배수
int GCD(int x, int y); //최대공약수

int main()
{
	int x=0, y=0, z=0; // 입력받는 변수
	int a = 0, b = 0, c = 0; //벽돌의 개수를 구하는 변수
	int length=0, brick=0;
	unsigned int the_number_of_brick=0;
	

	scanf("%d %d %d", &x, &y, &z);

	brick = GCD(GCD(x, y), z);
	length = LCM(LCM(x, y), z);

	a = length / x;
	b = length / y;
	c = length / z;

	the_number_of_brick = a * b * c;
	

	printf("%d %u", length, the_number_of_brick);
	
	return 0;
}

int GCD(int x, int y)
{
	int tmp;
	if (x < y)
	{
		tmp = x;
		x = y;
		y = tmp;
	}
	while (y != 0)
	{
		tmp = x % y;
		x = y;
		y = tmp;
	}
	return x;

}

int LCM(int x, int y)
{
	return x * y / GCD(x, y);
}
