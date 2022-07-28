#include <iostream>
using namespace std;

class Fraction
{
	private:
	int numerator;
	int denominator;
	
	public:
	Fraction(int x, int y);
	Fraction();
	Fraction add(Fraction f1);
	Fraction sub(Fraction f1);
	Fraction mult(Fraction f1);
	Fraction div(Fraction f1);
	Fraction reduce(Fraction f1);
	void print();
};

int gcd(int a, int b)
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

Fraction::Fraction() {}
Fraction::Fraction(int x, int y)
{
	numerator = x;
	denominator = y;
}

Fraction Fraction::reduce(Fraction f1)
{
	int gcdnum = gcd(f1.numerator, f1.denominator);
	Fraction res;
	res.numerator = f1.numerator / gcdnum;
	res.denominator = f1.denominator / gcdnum;
	
	return res;
}

Fraction Fraction::add(Fraction f1)
{
	Fraction res;
	res.denominator = f1.denominator * denominator;
	res.numerator = (f1.numerator * denominator) + (numerator * f1.denominator);
	return reduce(res);
}
Fraction Fraction::sub(Fraction f1)
{
	Fraction res;
	res.denominator = f1.denominator * denominator;
	res.numerator = (numerator * f1.denominator)-(f1.numerator * denominator);
	return reduce(res);
}
Fraction Fraction::mult(Fraction f1)
{
	Fraction res;
	res.denominator = f1.denominator * denominator;
	res.numerator = f1.numerator * numerator;
	return reduce(res);
}
Fraction Fraction::div(Fraction f1)
{
	Fraction res;
	res.denominator = denominator * f1.numerator;
	res.numerator = numerator * f1.denominator;
	return reduce(res);
}

void Fraction::print()
{
	/*
	if (numerator * denominator < 0)
	{
		if (numerator < 0 && denominator >0)	//
		{
			cout<<numerator<<"/"<<denominator<<endl;
		}
		else if (numerator > 0 && denominator < 0)
		{
			numerator *= -1;
			denominator *= -1;
			cout<<numerator<<"/"<<denominator<<endl;
		}
	}
*/
	if (denominator < 0)
	{
		denominator *= -1;
		numerator *= -1;
		cout<<numerator<<"/"<<denominator<<endl;
	}
	else if (numerator < 0 && denominator < 0)
	{
		numerator *= -1;
		denominator *= -1;
		cout<<numerator<<"/"<<denominator<<endl;
	}
	
	else if (numerator == 0 && denominator != 0)
	{
		numerator = 0;
		denominator = 1;
		cout<<numerator<<"/"<<denominator<<endl;
	}
	else
	{
		cout<<numerator<<"/"<<denominator<<endl;
	}

}



int main()
{
	int x,y,x1,y1;
	cin>>x>>y>>x1>>y1;
	Fraction f1 = {x,y};
	Fraction f2 = {x1,y1};
	f1.add(f2).print();
	f1.sub(f2).print();
	f1.mult(f2).print();
	f1.div(f2).print();
	
	return 0;
}


