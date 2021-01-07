/* Pierce Tarleton
	CpSc 1071 Fall 2018
	lab9 - bank account class
*/

#include "bank_account.h"


int main (void) {

	Bank_account acct1;
	Bank_account acct2(23456, 250.00);
	Bank_account *acct3;

	cout << fixed << setw(7) << setprecision(2);

	// testing acct1
	cout << "\nacct1: ";
	acct1.display();
	cout << "\nacct1 balance: " << acct1.get_balance();
	acct1.set_id(12345);
	cout << "\nacct1: ";
	acct1.display();

	// testing acct2	
	cout << "\nacct2 balance: " << acct2.get_balance();
	acct2.display();

	// testing acct3
	acct3 = new Bank_account(34567, 40.00);
	cout << "\nacct3 balance: " << acct3->get_balance();
	acct3->display();

	// testing deposit with acct1
	acct1.deposit(20.00);
	cout << "\nacct1 balance: " << acct1.get_balance();
	acct1.display();

	// testing withdrawal with acct2
	acct2.withdraw(10.00);
	cout << "\nacct2 balance: " << acct2.get_balance();
	acct2.display();

	// tesitng deposit with acct1
	acct3->deposit(350.00);
	cout << "\nacct3 balance: " << acct3->get_balance();
	acct3->display();


	return 0;
}		
		
