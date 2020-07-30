/*
 * Name:Pierce Tarleton
 * Date Submitted:2/27/2019
 * Lab Section:4
 * Assignment Name:Lab 5 Bank
 */

// Note that this print function is meant to give an example of what format the print function should be in.  I know customers/accounts are not defined.

#include "Bank.h"
#include <iostream>

Bank::Bank(){
    map<int, double> accounts;
    deque<string> customers;
    int customerActionType = 0;
    int customerID = 0;
    double amount = 0.0;
}

void Bank::print(){
    cout << "Remaining customers in line: " << customers.size() << endl;
    cout << "Total active customers: " << accounts.size() << endl;
    cout << "CUSTOMER LIST" << endl;
    cout << "-------------------" << endl;
    for(auto& i:accounts){
        cout<<i.first<<" : "<< i.second<<endl;
    }
	// Here, print all customers and their account balances in the format
	// customerID : balance
}

//Reads in the impute from the input file
void Bank::readInput(string inputFile){
    bool first = true;
    string readIn;
    ifstream InFile(inputFile);
    
    //Reads in the first item from the file and checks if it is quit
    InFile>>readIn;
    while(readIn != "quit"){
        
        // if it is the first time through the loop then take the first item read in as the first account id, then get the rest of the information and add it to the queue customers, and set first to false
        if(first){
            first = false;
            customers.push_back(readIn);
            for(int i = 0; i<2; i++){
                InFile>>readIn;
                customers.push_back(readIn);
            }
        }
        
        //if readIn is new then read in the next three values adding them to the queue customers
        else if(readIn == "new"){
            for(int i = 0; i<3; i++){;
                InFile>>readIn;
                customers.push_back(readIn);
            }
        }
        
        //if readIn has a value of process then take the first there items out of the queue customers converting them to the corect data type and seting customerID, customerActionType, and amount equal to them respectivley
        else if(readIn == "process"){
                customerID = stoi(customers.front());
                customers.pop_front();
                customerActionType = stoi(customers.front());
                customers.pop_front();
                amount = stod(customers.front());
                customers.pop_front();
                
                //if customerActionType equals 2 call deposit with the other two variables as arguments, if customerActionType equals 3 then call withdrawal
                if(customerActionType == 2){
                    deposit(customerID, amount);
                }
                if(customerActionType == 3){
                    withdrawal(customerID, amount);
                }
            }
        InFile>>readIn;
    }
}

//returns the value of the account with the ID number equal to the account number sent in as an argument, returns -1 if the account does not exist
double Bank::getBalance(int accountNum){
    if(accounts.count(accountNum) == 1){
        return accounts.at(accountNum);
    }
    return -1.0;
}

//returns the queue of customers that have not been served yet
deque<string> Bank::getLine(){
    return customers;
}

//returns the size of the queue of customers that have not been surved yet
int Bank::getLineLength(){
    return customers.size();
}

//returns the map of acounts and there ballances
map<int, double> Bank::getAccounts(){
    return accounts;
}

//checks if the account exists and if it does then it subtracts amount if it does not bring the ballances below zero
void Bank::withdrawal(int accountNum, double amount){
    if(accounts.count(accountNum) == 1){
        if(accounts.at(accountNum) - amount >= 0){
            accounts.at(accountNum) -= amount;
        }
    }
}

//if the account does not exist then it creates it with the amount with a ballance equal to amount. If the account does exist then it adds amount to the balance
void Bank::deposit(int accountNum, double amount){
    if(accounts.count(accountNum) != 1){
        accounts[accountNum] = amount;
    }
    else{
        accounts[accountNum] += amount;
    }
}