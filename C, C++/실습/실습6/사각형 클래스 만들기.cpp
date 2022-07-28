#include <iostream>
using namespace std;

class Point
{
private:
	int x;
	int y;
	
public:
	Point(){};
	Point(int x1, int y1);
	void move(int x1, int y1);
	int distance(Point P);
	int getx();
	int gety();
};
Point::Point(int x1, int y1):x(x1), y(y1){}
void Point::move(int x1, int y1){
	x = x + x1;
	y = y + y1;
}

int Point::getx(){return x;}
int Point::gety(){return y;}

class Rectangle
{
private:
	Point LowerLeft, UpperRight;
	
public:
	Rectangle(){};
	Rectangle(int llx, int lly, int urx, int ury);
	Point getLLPoint();
	Point getURPoint();
	int area();
	int perimeter();
	void move(Point P);
};

Rectangle::Rectangle(int llx, int lly, int urx, int ury):LowerLeft(llx,lly),UpperRight(urx,ury){}
Point Rectangle::getLLPoint(){
	return LowerLeft;
}
Point Rectangle::getURPoint(){
	return UpperRight;
}
int Rectangle::area(){
	return (UpperRight.getx()-LowerLeft.getx())*(UpperRight.gety()-LowerLeft.gety());
}
int Rectangle::perimeter(){
	return (UpperRight.gety()-LowerLeft.gety())*2+(UpperRight.getx()-LowerLeft.getx())*2;
}
void Rectangle::move(Point P){
	UpperRight.move(P.getx(), P.gety());
	LowerLeft.move(P.getx(), P.gety());
}
int main(){
	int x, y, x1, y1;
	cin >> x >> y >> x1 >> y1;
	Rectangle r(x,y,x1,y1);
	cout<<r.area()<<endl<<r.perimeter()<<endl;
}