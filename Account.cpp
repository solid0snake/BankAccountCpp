/*
* Account.cpp
* By Pedro Garate on 10/30/2014
* Description: This program mantains account balance.
*              It can deposit or withdraw from the account.
*/

#include "Account.h"

//default constructor. balance = 0
Account::Account() :balance{ 0 }
{
}//end of default constructor

//2nd constructor. balance = initialDeposit
Account::Account(double initialDeposit)
{
	balance = initialDeposit;
}//end of 2nd constructor

//accessor. gets balance
double Account::getBalance() const
{
	return balance;
}//end of getBalance

//mutator. deposits into account if amount is not negative
//returns balance
double Account::deposit(double amount)
{
	Exception_Negative_Deposit e_neg_dep;

	if (amount > 0)
		return balance += amount;
	else
		throw e_neg_dep;
}//end of deposit

//mutator. withdraws from account if amount is less than balance
//and not negative.
//returns balance
double Account::withdraw(double amount)
{
	Exception_Negative_Withdraw e_neg_wit;
	Exception_Overdraw e_over;

	if (amount > balance)
		throw e_over;
	else if (amount < 0)
		throw e_neg_wit;
	else {
		balance -= amount;
		return balance;
	}
}//end of withdraw

// Exception. Negative Deposit
const char* Exception_Negative_Deposit::what() const throw()
{
	return "\n(Error 1: Transaction canceled. A negative amount cannot be deposited)";
}// end Exception_Negative_Deposit

// Exception. Overdraw
const char* Exception_Overdraw::what() const throw()
{
	return "\n(Error 2: Transaction canceled. Withdrawing amount will overdraw the account)";
}// end Exception_Overdraw

// Exception. Negative Withdraw
const char* Exception_Negative_Withdraw::what() const throw()
{
	return "\n(Error 3: Transaction canceled. A negative amount cannot be withdrawn)";
}// end Exception_Negative_Withdraw
