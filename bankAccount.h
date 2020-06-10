
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include "Account.h"
#include <vector>

class bankAccount : public Account
{
public:
    void currentBalance(vector<stock1> &StockInfo);
    double deposit(vector<stock1> &StockInfo);
    double withdraw(vector<stock1> &StockInfo);
    void transactionsHistory();

private:
};

#endif
