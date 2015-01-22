/*
* Account.h
* By Pedro Garate on 10/30/2014
* Description: This program mantains account balance.
*              It can deposit or withdraw from the account.
*/

#ifndef _ACCOUNT_H
#define _ACCOUNT_H
#include <exception>

using namespace std;

class Account {
private:
	double balance; // account balance
public:
	Account(); // default constructor, balance = 0
	Account(double initialDeposit); // 2nd constructor, balance = initialDeposit
	double getBalance() const;
	double deposit(double amount); // deposit into account
	double withdraw(double amount); // withdraw from account
};// end Account

class Exception_Negative_Deposit : public exception
{
public:
	virtual const char* what() const throw();
};// end Exception_Negative_Deposit

class Exception_Overdraw : public exception
{
public:
	virtual const char* what() const throw();
};// end Exception_Overdraw

class Exception_Negative_Withdraw : public exception
{
public:
	virtual const char* what() const throw();
};// end Exception_Negative_Withdraw

#endif
