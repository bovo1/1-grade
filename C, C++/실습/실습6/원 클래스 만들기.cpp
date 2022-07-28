#include <iostream>
#include <cstring>

using namespace std;
class Circle
{
	private:
	int radius;
	string color;
	public:
	Circle();
	Circle(int radius) : radius(radius) {}
	double calcArea()
	{
		return radius * radius * 3.14;
	}
};
int main()
{
	int r;
	cin >> r;
	Circle c(r);
	cout << c.calcArea()<<endl;
}