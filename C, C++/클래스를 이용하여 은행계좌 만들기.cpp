#include <iostream>
#include <string>
#include <string.h>
#define ini_accountNum 11111
using namespace std;

class BankAccount
{
private:
int accountNumber;
string owner;
int balance;
int PinNumber;

public:
BankAccount(){}
BankAccount(string owner1, int pinNum, int ini_balance);
BankAccount(string owner1, int pinNum, int ini_balance, int acNum);
void setOwner(string name);
string getOwner();
int getAccountNumber();
void changePinNumber(int num);
bool checkPinNumber();
int getBalance();
void deposit(int amount);
void withdraw(int amount);
void print();

};

BankAccount::BankAccount(string owner1, int pinNum, int ini_balance)
{
	owner = owner1;
	balance = ini_balance;
	PinNumber = pinNum;
	accountNumber = ini_accountNum;
}
BankAccount::BankAccount(string owner1, int pinNum, int ini_balance, int acNum)
{
	owner = owner1;
	balance = ini_balance;
	PinNumber = pinNum;
	accountNumber = acNum;
}
void BankAccount::setOwner(string name)
{
	owner = name;
}
string BankAccount::getOwner()
{
	return owner;
}
bool BankAccount::checkPinNumber()
{
	int number;
	cin>>number;
	if(number==PinNumber)
	{
		return true;
	}
	else
	{
		cout<<"PWD not correct";
		return false;
	}	
}
void BankAccount::changePinNumber(int num)
{
	if(checkPinNumber())
	{
		PinNumber=num;
	}
	
}
int BankAccount::getAccountNumber()
{
	return accountNumber;
}
int BankAccount::getBalance()
{
	if(checkPinNumber())
	{
		return balance;
	}
	else
	{
		return -1;
	}
}
void BankAccount::deposit(int amount)
{
	balance += amount;
}
void BankAccount::withdraw(int amount)
{
	if(checkPinNumber())
	{
		if(amount>balance)
		{
			cout<<"잔액부족"<<endl;
		}
		else
		{
			balance -= amount;
		}	
	}
	
}
void BankAccount::print()
{
	cout<<"owner : "<<owner<<endl<<"accountnumber : "<<accountNumber<<endl<<"balance :"<<balance<<endl;
}

int main()
{
	string name;
	int password, balance;
	cin>>name>>password>>balance;

	BankAccount Bankaccount(name, password, balance);
	
	int command=0;
	int amount = 0;
	int amount1 = 0;
	
	while(command != 5)
	{
		cin>>command;
		if(command == 1)
		{
			int Balance = 0;
			Balance = Bankaccount.getBalance();
			if(Balance != -1)
			{
				cout<<Balance<<endl;
			}	
		}
		else if(command == 2)
		{
			cin>>amount;
			Bankaccount.deposit(amount);
		}
		else if(command == 3)
		{
			cin>>amount1;
			Bankaccount.withdraw(amount1);
		}
		else if(command == 4)
		{
			int num;
			cin>>num;
			Bankaccount.changePinNumber(num);
		}
		else if(command == 5)
		{
			return 0;
		}
		else
		{
			cout<<"error"<<endl;
		}
	}
	
}