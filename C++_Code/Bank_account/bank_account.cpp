/*Pierce Tarleton
  cpsc 1071-002
  Fall 2018
  Lab# 9
  
  The implementation of the funcuons in the Bank_account class*/

#include "bank_account.h"

/*Bank_account::Bank_account(){
	id = 0;
	balance = 0;
}

Bank_account::Bank_account(int id_num, double amount){
	id = id_num;
	balance = amount;
}*/
void transaction(const Bank_account &obj, int transaction){
	balance = balance + transaction;
	obj.balance -= transaction;
}
//Bank_account::Bank_account(int id_num, double bal??

Bank_account::Bank_account(int id_num, int bal){
	id = id_num;
	balance = 0;
	balance = balance + bal;
}
Bank_account::Bank_account(const Bank_account &obj){
	p=new Bank_account;
	*p.id = *obj.id;
	*p.balance = *obj.balance;
}

Bank_account::~Bank_account(){
	cout<<"The Destructor has been implimented"<< endl;
	delete p;
}

double Bank_account::get_balance(){
	return balance;
}

void Bank_account::set_id(int id_num){
	id = id_num;
}

void Bank_account::deposit(double amount){
	balance += amount;
}

void Bank_account::withdraw(double amount){
	balance -= amount;
}

void Bank_account::display(){
	cout<< endl;
	cout<<"Account Number: "<< id<< endl;
	cout<<"Account Balance: "<< balance<< endl;
}
