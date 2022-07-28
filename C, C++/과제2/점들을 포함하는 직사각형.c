#include <stdio.h>
#include <stdlib.h>
//#include <assert.h>

struct Fraction
{
	int numerator; //분자
	int denominator; //분모
};

int gcd(int a, int b) //최대공약수
{
	int r;
	while (a % b != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return b;
}

int compare(const struct Fraction R1, const struct Fraction R2) // 비교함수
{
	int r1_common_numerator = R1.numerator * R2.denominator; // 통분된 분자 r1
	int r2_common_numerator = R2.numerator * R1.denominator;

	if (r1_common_numerator < r2_common_numerator) // R1 < R2
	{
		return -1;
	}
	else if (r1_common_numerator == r2_common_numerator) // R1 == R2
	{
		return 0;
	}
	else  // R1 > R2
	{
		return 1;
	}
}

struct Fraction big(const struct Fraction r[], const int n)
{
	int max_position = 0; // r[]에서 최대값의 위치, 초기값은 0번째 요소로 가정
	int i;
	for (i = 1; i < n; i++)
	{
		if (compare(r[i], r[max_position]) == 1) // r[i]가 기존 최대값보다 크다면
		{
			max_position = i; // 최대값의 위치를 갱신
		}
	}

	return r[max_position]; // 기억해둔 위치로 최대값 반환
}

struct Fraction small(const struct Fraction r[], const int n)
{
	int min_position = 0;
	int i;
	for (i = 1; i < n; i++)
	{
		if (compare(r[i], r[min_position]) == -1)// r[i]가 기존 최소값보다 작다면
		{
			min_position = i;
		}
	}

	return r[min_position];
}

struct Fraction reduce(const struct Fraction r)   //기약분수로 만들어주는것
{
	int gcdNumDen;
	struct Fraction result;

	gcdNumDen = gcd(r.numerator, r.denominator);

	result.numerator = r.numerator / gcdNumDen;
	result.denominator = r.denominator / gcdNumDen;

	return result;
}

struct Fraction minus(const struct Fraction r1, const struct Fraction r2)   //뺄셈
{
	struct Fraction result;

	result.denominator = r1.denominator * r2.denominator;
	result.numerator = (r1.numerator * r2.denominator) - (r2.numerator * r1.denominator);

	return   reduce(result);      //r을 기약분수로 바꾸어 반환함.
}

struct Fraction multi(const struct Fraction r1, const struct Fraction r2)   //곱셈
{
	struct Fraction result;
	
	result.denominator = r1.denominator * r2.denominator;
	result.numerator = r1.numerator * r2.numerator;

	return   reduce(result);      //r을 기약분수로 바꾸어 반환함.
}

void print(const struct Fraction r1)   //출력함수
{
	if (r1.numerator * r1.denominator == 0)
	{
		printf("0/1\n");
	}
	else
	{
		printf("%d/%d\n", r1.numerator, r1.denominator);
	}
}

int main(void)
{
	struct Fraction R1[1000], R2[1000]; // 2~1000
	struct Fraction X_B, X_S, Y_B, Y_S;
	struct Fraction Res_x, Res_y, Result;
	int n, i;

	scanf("%d", &n);   //몇개의 점이있는지 

	for (i = 0; i < n; i++)
	{
		scanf("%d %d %d %d", &R1[i].numerator, &R1[i].denominator, &R2[i].numerator, &R2[i].denominator);
		if (R1[i].denominator < 0) { // 분모를 양수로 변경
			R1[i].denominator *= -1;
			R1[i].numerator *= -1;
		}
		if (R2[i].denominator < 0) {
			R2[i].denominator *= -1;
			R2[i].numerator *= -1;
		}
	}

	X_B = big(R1, n);   //x좌표에서 최댓값
	X_S = small(R1, n);   //x좌표에서 최솟값
	Y_B = big(R2, n);
	Y_S = small(R2, n);

	Res_x = minus(X_B, X_S);   //x좌표 최댓값 - 최솟값
	Res_y = minus(Y_B, Y_S);   //y좌표 최댓값 - 최솟값

	Result = multi(Res_x, Res_y);   //서로 곱한것

	print(Result);   //면적 구하는게 x좌표에서 최댓값과 최솟값을 뺀거랑 y좌표에서 최댓값이랑 최솟값을 뺀거랑 서로 곱해주면 면적이 나옵니다.

	return 0;
}