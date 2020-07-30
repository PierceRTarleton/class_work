/*
 * Name:Pierce Tarleton
 * Date Submitted:2/27/2019
 * Lab Section:4
 * Assignment Name:Lab 5 Bank
 */

// All necessary directions are in the lab description on Mimir and in the
// input.txt file.  What data structures would be most approprite for this
// task?  Keep in mind that you need to be able to rapidly access accounts
#include <string>
#include <map>
#include <deque>
#include <fstream>
#include <cctype>
#include <vector>
using namespace std;

class Bank{
  private:
    map<int, double> accounts;
    deque<string> customers;
    int customerActionType;
    int customerID;
    double amount;

  public:
    Bank();
    void print();
    void readInput(string inputFile);
    double getBalance(int accountNum);
    deque<string> getLine();
    int getLineLength();
    map<int, double> getAccounts();
    void withdrawal (int accountNum, double amount);
    void deposit (int accountNum, double amount);
// double getBalance -- returns balance of a specific customer
// ... getLine -- returns the data structure containing all unserved customers
// ... getAccounts -- returns the data structure containing all customer accounts
// Add any other methods which are necessary to finish the assignment
    };
