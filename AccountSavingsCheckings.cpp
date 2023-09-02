//============================================================================
// Name        : CMPE126-LAB-3-1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Part-One
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

class Account
{
 public:
 Account();
 Account( double ); // constructor initializes balance
 virtual void credit( double ); // add an amount to the account balance
 virtual bool debit( double ); // subtract an amount from the account balance
 void setBalance( double ); // sets the account balance
 double getBalance(); // return the account balance
 private:
 double balance; // data member that stores the balance
}; // end class Account

Account::Account(double intBalance)
{
	if(intBalance >= 0.0)
		balance = intBalance;
	else
	{
		cout<<"Initial Balance Cannot Be Negative" << endl;
		balance = 0.0;
	}
}
void Account::credit(double amount)
	{
		balance = balance + amount;
	}
bool Account::debit(double amount)
{
	if (amount > balance)
	{
		cout << "Debit Amount Is More Than Account Balance "<<endl;
		return false;
	}
	else{
		balance = balance - amount;
		return true;
	}
}
void Account::setBalance(double newBalance)
{
	balance = newBalance;
}
double Account::getBalance()
{
	return balance;
}

class SavingsAccount : public Account
{
 public:
 // constructor initializes balance and interest rate
 SavingsAccount( double, double );
 double calculateInterest(); // determine interest owed
 private:
 double interestRate; // interest rate (percentage) earned by account
 }; // end class SavingsAccount
SavingsAccount::SavingsAccount (double intBalance, double rate):Account(intBalance)
{
	interestRate = rate;
}
double SavingsAccount::calculateInterest()
{
return getBalance() * interestRate;
}

class CheckingAccount : public Account
{
 public:
 // constructor initializes balance and transaction fee
 CheckingAccount( double, double );
 void credit( double ); // redefined credit function
 bool debit( double ); // redefined debit function
 private:
 double transactionFee; // fee charged per transaction
 // utility function to charge fee
 void chargeFee();
}; // end class CheckingAccount

CheckingAccount::CheckingAccount(double intBalance, double fee):Account(intBalance)
{
	transactionFee = fee;
}
void CheckingAccount::credit(double amount)
{
	Account::credit(amount);
	chargeFee();
}
bool CheckingAccount::debit(double amount)
{
	bool charged = Account::debit(amount);
	if (charged)
	{
		chargeFee();
		return true;
	}
	else
		return false;
}
void CheckingAccount::chargeFee()
{
	Account::setBalance(getBalance() - transactionFee);
	cout<<"$"<<transactionFee<<" Transaction Fee Charged" << endl;
}


int main() {
	vector<Account *> account(4);
	double interest;

	account[0]= new SavingsAccount(25.0, 0.03);
	account[1]= new CheckingAccount(100.0, 5.0);


	for(int i = 0; i<account.size();i++)
	{
		cout<<"Account "<< i + 1 <<" balance: $" << account[i]->getBalance();
		double withdrawalAmount = 0.0;
		cout<<"\nEnter Amount To Withdrawal From Account " << i + 1 << ":$";
		cin>> withdrawalAmount;
		account[i]->debit(withdrawalAmount);
		account[i]->getBalance();

		cout<<"Amount After Withdrawal:$"<< account[i]->getBalance();
		cout<<endl;
		double depositAmount = 0.0;
		cout<< "Enter Amount To Deposit Into Account " << i+1 << ":$";
		cin>>depositAmount;
		account[i]->credit(depositAmount);
		account[i]->getBalance();

		cout<<"Amount After Deposit:$"<< account[i]->getBalance();
		cout<<"\n"<<endl;

		SavingsAccount *s = dynamic_cast<SavingsAccount*>(account[i]);
		if(s != NULL)
		{
		cout<<"Account Is of Saving Type"<<endl;
		interest = s->calculateInterest();
		cout<<"Interest Owed: "<<interest<<endl;
		s->credit(interest);
		}
		else {
		cout<<"Account "<<(i+1)<<" Is Of Checking Type"<<endl;
		}
		cout<<"Final Balance: $"<<account[i]->getBalance()<<endl;
		cout<<endl;
		}

		for(int i=0; i<4; i++)
		delete account[i];
		return 0;
		}
