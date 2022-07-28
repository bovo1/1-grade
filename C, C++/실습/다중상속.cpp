#include <iostream>
using namespace std;

class PassangerCar
{
	protected:
	int seats;
	public:
	void set_seats(int n){seats = n;}
};

class Truck
{
	protected:
	int payload;
	public:
	void set_payload(int n){payload = n;}
};

class Pickup : public PassangerCar, public Truck
{
	private:
	int tow_capability;
	public:
	void set_tow(int n){tow_capability = n;}
	void print()
	{
	cout<<"seats : "<<seats<<endl<<"payload : "<<payload<<endl<<"tow_capability : "<<tow_capability<<endl;
	}
};

int main()
{
	Pickup car;
	int s,p,t;
	cin>>s>>p>>t;
	car.set_seats(s);
	car.set_payload(p);
	car.set_tow(t);
	car.print();
	return 0;
	
}