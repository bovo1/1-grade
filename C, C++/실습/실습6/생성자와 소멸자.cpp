#include <iostream>
using namespace std;

class samplePoint
{
	private:
	int x;
	int y;
	public:
	samplePoint();
	samplePoint(int x1, int y1);
	~samplePoint();
};

samplePoint::samplePoint()
{
	x =1;
	y = 1;
	cout<<'('<<x<<','<<y<<')'<<"점 생성"<<endl;
}
samplePoint::samplePoint(int x1, int y1)
{
	x = x1;
	y = y1;
	cout<<'('<<x<<','<<y<<')'<<"점 생성"<<endl;
}
samplePoint::~samplePoint()
{
	cout<<'('<<x<<','<<y<<')'<<"점 파괴"<<endl;
}
int main()
{
	samplePoint p1;
	samplePoint p2(2,5);
	cout<<"이 프로그램은 종료 되었습니다."<<endl;
	return 0;
}
