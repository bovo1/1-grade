#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int ini_accountNum = 0;

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

class Bank
{
private:
BankAccount account[100];
string BankName;
int last_accountNum;
int tortal_userNumber;
public:
Bank();
void newAccount(string ownerName, int pinNum, int ini_balance);
int getBalance(int accountnum);
void deposit(int accountNum, int amount);
void withdraw(int accountNum,int amount);
};
Bank::Bank()
{
	last_accountNum = 11111;
	tortal_userNumber =0;
}
void Bank::newAccount(string ownerName, int pinNum, int ini_balance)
{
	BankAccount newone(ownerName, pinNum, ini_balance, last_accountNum);
	account[tortal_userNumber]=newone;
	tortal_userNumber++;
	last_accountNum++;
}
int Bank::getBalance(int accountnum)
{
	int i= 0;
	for(i=0;i<tortal_userNumber;i++)
	{
		if(account[i].getAccountNumber()==accountnum)
		{
			break;
		}
	}
	//account[i].checkPinNumber();
	return account[i].getBalance();
}
void Bank::deposit(int accountNum, int amount)
{
	int i =0;
	for(i=0;i<tortal_userNumber;i++)
	{
		if(account[i].getAccountNumber()==accountNum)
		{
			break;
		}
	}
	account[i].deposit(amount);
}
void Bank::withdraw(int accountNum, int amount)
{
	int i =0;
	for(i=0;i<tortal_userNumber;i++)
	{
		if(account[i].getAccountNumber()==accountNum)
		{
			break;
		}
	}
	account[i].withdraw(amount);

}

int main()
{
	Bank Bk;
	int command = 0;
	while (command != 5)
	{
		cin>>command;
		if(command == 1)
		{
			string name;
			int pwd;
			int startbalance;
			cin>>name>>pwd>>startbalance;
			Bk.newAccount(name, pwd, startbalance);
		}
		else if(command == 2)
		{
			int acNum;
			cin>>acNum;
			int b;
			b = Bk.getBalance(acNum);
			if( b!= -1)
			{
				cout<<b<<endl;
			}
		}
		else if(command == 3)
		{
			int acNum_d, dAmount;
			cin>>acNum_d >>dAmount;
			Bk.deposit(acNum_d, dAmount);
		}
		else if(command ==4)
		{
			int acNum_w, wAmount;
			cin>>acNum_w>>wAmount;
			Bk.withdraw(acNum_w, wAmount);
		}
		else if(command == 5)
		{
			break;
		}
		else
		{
			cout<<"error"<<endl;
		}
	}
	return 0;
}



