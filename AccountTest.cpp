/*
* AccountTest.cpp
* By Pedro Garate on 10/30/2014
* Description: This program mantains account balance.
*              It can deposit or withdraw from the account.
*/

#include "Account.h"
#include <iostream>

using namespace std;

void withdraw(Account& num, double amount);// try-catch block for withdrawal
void deposit(Account& num, double amount); // try-catch block for deposit

int main()
{
	//*************** test constructors ********************
	cout << "ACCOUNT BALANCE PROGRAM:" << endl;
	cout << "Let's start with accounts which balances are zero and $2000." << endl;
	Account acct1;
	Account acct2(2000);

	//*************** test getBalance **********************
	cout << "\nAccount # 1\t\tBalance: $ " << acct1.getBalance() << endl;
	cout << "Account # 2\t\tBalance: $ " << acct2.getBalance() << endl << endl;

	//*************** test deposit and withdraw ************
	cout << "If we deposit $3504.75 into account #1, and withdraw $1504.25 from account #2,\n"
		"the new balances would be:\n";
	cout << "\nAccount # 1\t\tBalance: $ ";
	deposit(acct1, 3504.75);
	cout << endl;
	cout << "Account # 2\t\tBalance: $ ";
	withdraw(acct2, 1504.25);
	cout << endl << endl;

	//**** test negative amounts for deposit and withdraw ****
	cout << "Let's try using invalid amounts." << endl;
	cout << "If we deposit $-435.75 into account #1, and withdraw $-100 from account #2,\n"
		"the new balances would be:\n";
	cout << "\nAccount # 1\t\tBalance: $ ";
	deposit(acct1, -435.75);
	cout << endl;
	cout << "Account # 2\t\tBalance: $ ";
	withdraw(acct2, -100);
	cout << endl << endl;

	//*************** test overdraw exception ***************
	cout << "Or withdraw $10666.50 from account #1 the new balances would be:\n";
	cout << "Account # 1\t\tBalance: $ ";
	withdraw(acct1, 10666.50);
	cout << endl;
	cout << "Account # 2\t\tBalance: $ " << acct2.getBalance() << endl;

	return EXIT_SUCCESS;
}//end of main

// try-catch block for withdrawal
void withdraw(Account& num, double amount)
{
	try {
		cerr << num.withdraw(amount);
	}
	catch (Exception_Negative_Withdraw& e)
	{
		cerr << num.getBalance() << e.what();
	}
	catch (Exception_Overdraw& e)
	{
		cerr << num.getBalance() << e.what();
	}
}// end withdraw

// try-catch block for deposit
void deposit(Account& num, double amount)
{
	try {
		cerr << num.deposit(amount);
	}
	catch (Exception_Negative_Deposit& e)
	{
		cerr << num.getBalance() << e.what();
	}
}// end deposit
