#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

struct stock1
{
    string name;
    string desc;
    double price;
    int Ammount;
    double stocktotal;
};

class Account
{
public:
    Account();

    double getBalance();
    void setBalance(double &);
    string validInput(string);

protected:
private:
    static double cashBalance;
};

#endif
