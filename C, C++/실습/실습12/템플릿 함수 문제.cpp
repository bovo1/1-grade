#include <iostream>
using namespace std;

template <typename T>
T adder(T n, T m)
{
	return n+m;
}

template <typename T>
T sub(T n, T m)
{
	return n-m;
}

int main()
{
	int in, im;
	float fn, fm;
	cin>>in>>im>>fn>>fm;
	cout<<adder(in, im)<<endl<<adder(fn, fm)<<endl;
	cout<<sub(in, im)<<endl<<sub(fn,fm)<<endl;
}