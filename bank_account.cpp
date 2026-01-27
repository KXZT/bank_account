// bank_account.cpp - Simple bank account class implementation
#include <cassert>
#include "bank_account.h"

int main()
{
	BankAccount account(1000);
	assert(account.balance() == 1000);
	
	account.deposit(500);
	assert(account.balance() == 1500);
	
	account.withdraw(200);
	assert(account.balance() == 1300);

	// test withdrawal that exceeds balance
	bool caught = false;
	try {
		account.withdraw(2000); // This should throw an exception
	}
	catch (const std::exception&) {
		caught = true;
	}
	assert(caught);

	// test deposit that causes overflow
	caught = false;
	try {
		account.deposit(UINT32_MAX); 
	}
	catch (const std::exception&) {
		caught = true;
	}
	assert(caught);


	return 0;
}
