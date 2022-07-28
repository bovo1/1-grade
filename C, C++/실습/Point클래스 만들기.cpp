#include <iostream>
#include <cmath>
using namespace std;

class Point
{
	private:
	int x;
	int y;
	
	public:
	Point() {};
	Point(int x1, int y1);
	void move(int x1, int y1);
	int distance(Point P);
	int getx();
	int gety();
};
Point::Point(int x1, int y1) : x(x1), y(y1){}
void Point::move(int x1, int y1)
{
	x = x + x1;
	y = y + y1;
}
int Point::distance(Point DP)
{
	int dis;
	dis = sqrt((DP.x-x)*(DP.x-x) + (DP.y - y)*(DP.y-y));
	return dis;
}
int Point::getx()
{
	return x;
}
int Point::gety()
{
	return y;
}
int main()
{
	int x,y,x1,y1;
	cin >> x >> y >> x1 >> y1;
	Point P1(x,y);
	Point P2(x1,y1);
	cout<<P1.distance(P2)<<endl;
	P1.move(x1,y1);
	cout<<P1.getx()<<"\t"<<P1.gety()<<endl;
	return 0;
}