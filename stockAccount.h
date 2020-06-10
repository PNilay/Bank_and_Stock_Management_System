#ifndef STOCKACCOUNT_H
#define STOCKACCOUNT_H
#include "Account.h"
#include <fstream>
#include <time.h>
#include <cstdlib>
#include <vector>

class stockAccount : public Account
{
private:
public:
    void currentPrice();
    double buystock(vector<stock1> &StockInfo);
    double sellstock(vector<stock1> &StockInfo);
    void currentPortfolio(vector<stock1> &StockInfo);
    void transactionHistory();
};

#endif
