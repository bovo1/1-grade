#include <iostream>
using namespace std;

class shape
{
	protected:
	int x,y;
	public:
	shape(int x, int y) : x(x),y(y){}
  virtual float area(){return 0;}
	virtual void print()
	{
    cout<<"shape draw"<<"\tarea = "<<area()<<endl;
  }
};

class rect : public shape
{
  private:
	int width, height;
	public:
	rect():shape(0,0),width(0),height(0) {}
	rect(int x, int y, int w, int h):shape(x,y),width(w),height(h){}
  virtual float area(){return width*height;}
	virtual void print(){
	cout<<"("<<x<<","<<y<<"),"<<width<<","<<height<<"\tarea = "<< area()<<endl;
	}
};

class circle : public shape
{
	private:
	int radius;
	public:
	circle(int x, int y, int r):shape(x,y), radius(r){}
	virtual float area(){return radius*radius*3.14;}
	virtual void print()
	{
 	 cout<<"("<<x<<","<<y<<"),"<<radius<<"\tarea = "<<area()<<endl;
	}
};
class triangle : public shape
{
  private:
	int width, height;
	public:
	triangle(int x, int y, int w, int h):shape(x,y),width(w),height(h){}
	virtual float area(){return width*height/2;}
	virtual void print()
	{
	  cout<<"("<<x<<","<<y<<"),"<<width<<","<<height<<"\tarea = "<<area()<<endl;
	}
};

int main()
{
  int check;
	int x,y,h,w,r;
	shape* s =new rect;
	s->print();
	cin>>x>>y>>h>>w;
	rect R(x,y,h,w);
	R.print();
	
	cin>>x>>y>>r;
	circle C(x,y,r);
	C.print();
	
	cin>>x>>y>>h>>w;
	triangle T(x,y,h,w);
	T.print();
	
	return 0;
}