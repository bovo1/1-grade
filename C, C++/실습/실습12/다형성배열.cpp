#include <iostream>
#include <string>
#define PI 3.14
using namespace std;

class Shape
{
	protected:
	int x,y;
	public:
	void setOrigin(int x, int y){this->x=x, this->y =y;}
	virtual void draw(){cout<<"Shape Draw"<<endl;}
	virtual double getArea()=0;
};
class Rectangle : public Shape
{
	private:
	int width, height;
	public:
	void setWidth(int w){width=w;}
	void setHeight(int h){height =h;}
	void draw()
	{
		cout<<"Rectangle Draw"<<endl;
		cout<<"시작점: ("<<x<<", "<<y<<") "<<endl;
	}
	double getArea(){return width * height;}
};

class Ellipse : public Shape
{
	private:
	int width, height;
	public:
	void setWidth(int w){width = w;}
	void setHeight(int h){height = h;}
	void draw()
	{
		cout<<"Ellipse Draw"<<endl;
		cout<<"시작점: ("<<x<<", "<<y<<") "<<endl;
	}
	double getArea(){return width *height *PI/4;}
	
};

class Triangle : public Shape
{
	private:
	int width, height;
	public:
	void setWidth(int w){width = w;}
	void setHeight(int h){height = h;}
	void draw()
	{
		cout<<"Triangle Draw"<<endl;
		cout<<"시작점: ("<<x<<", "<<y<<") "<<endl;
	}
	double getArea(){return width * height /2;}
};

int main()
{
	int n,j,x,y,w,h;
	cin>>n;
	Shape *sarr[n];
	
	for(int i =0; i<n;i++)
	{
		cin>>j>>x>>y>>w>>h;
		if(j%3==0)
		{
			sarr[i] = new Rectangle;
			sarr[i]->setOrigin(x,y);
			((Rectangle *)sarr[i])->setWidth(w);
			((Rectangle *)sarr[i])->setHeight(h);
		}
		else if(j%3==1)
		{
			sarr[i] = new Ellipse;
			sarr[i]->setOrigin(x,y);
			((Ellipse *)sarr[i])->setWidth(w);
			((Ellipse *)sarr[i])->setHeight(h);
		}
		else
		{
			sarr[i] = new Triangle;
			sarr[i]->setOrigin(x,y);
			((Triangle *)sarr[i])->setWidth(w);
			((Triangle *)sarr[i])->setHeight(h);
		}
		
	}
	
	for(int i=0;i<n;i++)
	{
		cout<<endl;
		sarr[i]->draw();
		cout<<"면적 : "<<sarr[i]->getArea()<<endl;
		sarr[i]->draw();
	}
	return 0;
}


