#include <stdio.h>
#include <math.h>

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

//분수를 분자/분모 양식으로 출력하는 함수
void print(struct Fraction r)
{
	int num, denom;
	//분모가 음수인 경우 분모를 양수로 하여 출력

	if (r.denominator < 0)
	{
		r.numerator *= -1;
		r.denominator *= -1;
	}
	printf("%d/%d\n", r.numerator, r.denominator);
}

	//분수 r을 기약분수 형태로 반환

struct Fraction reduce(struct Fraction r)
{
	int gcdNumDen;
	struct Fraction result;
	if (r.numerator == 0 || r.denominator == 0)
	{
		return r;
	}
	//분모나 분자가 0이면 그냥 반환

	gcdNumDen = gcd(r.numerator, r.denominator);
	result.numerator = r.numerator / gcdNumDen;
	result.denominator = r.denominator / gcdNumDen;

	return result;
}
	//두 분수를 더하여 이를 반환
	
struct Fraction add(struct Fraction r1, struct Fraction r2)
{
	struct Fraction result;
	result.denominator = r1.denominator * r2.denominator;
	result.numerator = (r1.numerator * r2.denominator) + (r2.numerator * r1.denominator);
	return	reduce(result);		//r을 기약분수로 바꾸어 반환함.
}

int main()
{
	struct Fraction r1, r2, result;
	scanf("%d %d %d %d", &r1.numerator, &r1.denominator, &r2.numerator, &r2.denominator);
	result = add(r1, r2);
	print(result); //분수를 출력하는 함수 print 이용

	return 0;
}
