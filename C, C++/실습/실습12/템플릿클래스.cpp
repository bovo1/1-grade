#include <iostream>
using namespace std;

template <typename T>
class Point
{
	private:
	T x, y;
	public:
	Point(T n, T m)
	{
		x = n;
		y = m;
	}
	void setPoint(T a, T b){x=a, y=b;}
	void move(T a, T b){x+=a, y+=b;}
	void print(){cout<<"("<<x<<","<<y<<")"<<endl;}
};
int main()
{
	int ix, iy;
	float fx, fy;
	int mx, my;
	float mfx, mfy;
	cin>>ix>>iy>>fx>>fy;
	cin>>mx>>my>>mfx>>mfy;
	
	Point<int> P(ix, iy);
	Point<float> P2(fx, fy);
	P.print();
	P2.print();
	P.move(mx,my);
	P2.move(mfx,mfy);
	P.print();
	P2.print();
	
	return 0;
}