#include <stdio.h>
#include <math.h>

struct Fraction
{
	long long int numerator; //분자
	long long int denominator; //분모
};

int gcd(long long int a, long long int b) //최대공약수
{
	long long int r;
	while (a % b != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return b;
}

struct Fraction reduce(struct Fraction r)
{
	long long int gcdNumDen;
	struct Fraction result;


	gcdNumDen = gcd(r.numerator, r.denominator);
	result.numerator = r.numerator / gcdNumDen;
	result.denominator = r.denominator / gcdNumDen;

	return result;
}

//분수를 분자/분모 양식으로 출력하는 함수
void print(struct Fraction r)
{
	if (r.numerator * r.denominator < 0)
	{
		if (r.numerator < 0 && r.denominator >0)
		{
			printf("%lld/%lld\n", r.numerator, r.denominator);
		}
		else if (r.numerator > 0 && r.denominator < 0)
		{
			r.numerator *= -1;
			r.denominator *= -1;
			printf("%lld/%lld\n", r.numerator, r.denominator);
		}
	}

	else if (r.numerator < 0 && r.denominator < 0)
	{
		r.numerator *= -1;
		r.denominator *= -1;
		printf("%lld/%lld\n", r.numerator, r.denominator);
	}
	else if (r.numerator == 0 && r.denominator != 0)
	{
		printf("0/1\n");
	}
	else
	{
		printf("%lld/%lld\n", r.numerator, r.denominator);
	}
}

struct Fraction minus(struct Fraction r1, struct Fraction r2)
{
	struct Fraction result;
	result.denominator = r1.denominator * r2.denominator;
	result.numerator = (r1.numerator * r2.denominator) - (r2.numerator * r1.denominator);
	return	reduce(result);		//r을 기약분수로 바꾸어 반환함.
}

struct Fraction multi(struct Fraction r1, struct Fraction r2)
{
	struct Fraction result;
	result.denominator = r1.denominator * r2.denominator;
	result.numerator = r1.numerator * r2.numerator;
	return reduce(result);		//r을 기약분수로 바꾸어 반환함.
}


int main()
{
	struct Fraction r1, r2, result1,result2;

	scanf("%lld %lld %lld %lld", &r1.numerator, &r1.denominator, &r2.numerator, &r2.denominator);
	
	if(r1.denominator ==0 || r2.denominator ==0)
	{
		return 0;
	}

	result1 = minus(r1, r2);
	result2 = multi(r1, r2);

	print(result1);
	print(result2);

	return 0;
}
