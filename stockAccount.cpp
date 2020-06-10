#include "stockAccount.h"
#include <iomanip>
struct stock
{
    string name;
    string desc;
    double price;
};
struct stock2
{
    string Action;
    string symbol;
    int shares;
    double price;
    string H;
    string M;
    string S;
};

void sortAcounts(vector<stock1> &StockInfo)
{
    stock1 temp;
    for (int i = 0; i < StockInfo.size(); i++)
    {
        for (int j = i + 1; j < StockInfo.size(); j++)
        {
            if (StockInfo[i].name[0] > StockInfo[j].name[0])
            {
                temp = StockInfo[j];
                StockInfo[j] = StockInfo[i];
                StockInfo[i] = temp;
            }
        }
    }
}

vector<stock2> StockInfo2;

void stockAccount::currentPrice()
{
    vector<stock> currentinfo;
    srand(time(NULL)); //srand( (unsigned)time( NULL ) );
    int num = rand() % 4 + 1;
    string name = "stock" + to_string(num) + ".txt";
    string name2 = "C:.\\" + name;

    ifstream file(name2);
    string line;

    while (getline(file, line))
    {
        string delim = "\t";
        vector<string> tokens;
        for (int i = 0; i < 3; i++)
        { // making 3 tokens
            if (i == 2)
            { // handling newline character
                line = line.substr(line.rfind(delim) + 1, string::npos);
                tokens.push_back(line);
            }
            tokens.push_back(line.substr(0, line.find(delim)));
            line = line.substr(line.find(delim) + 1, string::npos);
        }

        stock newstock;
        newstock.name = tokens[0];
        newstock.desc = tokens[1];
        newstock.price = stod(tokens[2]);
        currentinfo.push_back(newstock);
    }

    file.close();

    string symbol;
    int index = 50;
    cout << "\nEnter stock Symbol for checking price: ";
    cin >> symbol;

    for (int i = 0; i < currentinfo.size(); i++)
    {
        if (currentinfo[i].name == symbol)
        {
            index = i;
        }
    }

    // Time
    time_t T = time(NULL);
    tm *timePtr = localtime(&T);

    int hr = (timePtr->tm_hour);
    int min = (timePtr->tm_min);
    int sec = (timePtr->tm_sec);

    if (index != 50)
    {
        cout << currentinfo[index].name << "\t" << currentinfo[index].desc << "\t" << currentinfo[index].price
             << "\t" << hr << ":" << min << ":" << sec << endl;
    }
    else
    {
        cout << "\nInvalid Stock symbol entered" << endl;
    }
    cout << endl;
}

double stockAccount::buystock(vector<stock1> &StockInfo)
{

    vector<stock> currentinfo;
    srand(time(NULL));
    int num = rand() % 4 + 1;
    string name = "stock" + to_string(num) + ".txt";
    string name2 = ".\\" + name;
    ifstream file(name2);
    string line;

    while (getline(file, line))
    {
        string delim = "\t";
        vector<string> tokens;
        for (int i = 0; i < 3; i++)
        { // making 3 tokens
            if (i == 2)
            { // handling newline character
                line = line.substr(line.rfind(delim) + 1, string::npos);
                tokens.push_back(line);
            }
            tokens.push_back(line.substr(0, line.find(delim)));
            line = line.substr(line.find(delim) + 1, string::npos);
        }

        stock newstock;
        newstock.name = tokens[0];
        newstock.desc = tokens[1];
        newstock.price = stod(tokens[2]);
        currentinfo.push_back(newstock);
    }

    file.close();

    int Ammount;
    double price;
    string symbol;
    int index = 50;
    cout << "\nEnter buy options:";
    cin >> symbol >> Ammount >> price;

    for (int i = 0; i < currentinfo.size(); i++)
    {
        if (currentinfo[i].name == symbol)
        {
            index = i;
        }
    }

    double cashBalance = getBalance();

    if (index != 50)
    {
        double Total = (currentinfo[index].price * Ammount);
        if (cashBalance < Total || currentinfo[index].price > price)
        {
            cout << "\nCannot process transaction" << endl;
            cout << endl;
        }
        else
        {
            cashBalance = cashBalance - Total;
            time_t T = time(NULL);
            tm *timePtr = localtime(&T);

            string hr = to_string(timePtr->tm_hour);
            string min = to_string(timePtr->tm_min);
            string sec = to_string(timePtr->tm_sec);

            int SAME = -1;
            for (int i = 0; i < StockInfo.size(); i++)
            {
                if (StockInfo[i].name == symbol)
                {
                    SAME = i;
                }
            }

            if (SAME == -1)
            {
                stock1 newstock;
                newstock.name = symbol;
                newstock.desc = currentinfo[index].desc;
                newstock.price = currentinfo[index].price;
                newstock.Ammount = Ammount;
                newstock.stocktotal = Total;
                StockInfo.push_back(newstock);
                setBalance(cashBalance);
            }
            else
            {
                StockInfo[SAME].price = currentinfo[index].price;
                StockInfo[SAME].Ammount = StockInfo[SAME].Ammount + Ammount;
                StockInfo[SAME].stocktotal = StockInfo[SAME].Ammount * StockInfo[SAME].price;
            }
            sortAcounts(StockInfo);

            stock2 transactionHis;
            transactionHis.symbol = symbol;
            transactionHis.price = currentinfo[index].price;
            transactionHis.shares = Ammount;
            transactionHis.Action = "Buy";
            transactionHis.H = hr;
            transactionHis.M = min;
            transactionHis.S = sec;
            StockInfo2.push_back(transactionHis);
        }
    }
    else
    {
        cout << "\nInvalid Symbol" << endl;
    }
}

double stockAccount::sellstock(vector<stock1> &StockInfo)
{
    vector<stock> currentinfo;
    srand(time(NULL)); //srand( (unsigned)time( NULL ) );
    int num = rand() % 4 + 1;
    string name = "stock" + to_string(num) + ".txt";
    string name2 = ".\\" + name;

    ifstream file(name2);
    string line;

    while (getline(file, line))
    {
        string delim = "\t";
        vector<string> tokens;
        for (int i = 0; i < 3; i++)
        { // making 3 tokens
            if (i == 2)
            { // handling newline character
                line = line.substr(line.rfind(delim) + 1, string::npos);
                tokens.push_back(line);
            }
            tokens.push_back(line.substr(0, line.find(delim)));
            line = line.substr(line.find(delim) + 1, string::npos);
        }

        stock newstock;
        newstock.name = tokens[0];
        newstock.desc = tokens[1];
        newstock.price = stod(tokens[2]);
        currentinfo.push_back(newstock);
    }

    file.close();

    double cashBalance = getBalance();

    int Ammount;
    double price;
    string symbol;
    int index = 50, index2;
    cout << "\nEnter selling options: ";
    cin >> symbol >> Ammount >> price;

    for (int i = 0; i < StockInfo.size(); i++)
    {
        if (StockInfo[i].name == symbol)
        {
            index = i;
            for (int j = 0; j < currentinfo.size(); j++)
            {
                if (currentinfo[j].name == symbol)
                {
                    index2 = j;
                }
            }
        }
    }

    if (index != 50)
    {
        if (currentinfo[index2].price < price || StockInfo[index].Ammount < Ammount)
        {
            cout << "\nCannot process transaction" << endl;
            cout << endl;
        }
        else
        {
            double Total = (currentinfo[index2].price * Ammount);
            cashBalance = cashBalance + Total;
            time_t T = time(NULL);
            tm *timePtr = localtime(&T);

            string hr = to_string(timePtr->tm_hour);
            string min = to_string(timePtr->tm_min);
            string sec = to_string(timePtr->tm_sec);

            StockInfo[index].Ammount = StockInfo[index].Ammount - Ammount;
            StockInfo[index].price = currentinfo[index2].price;
            StockInfo[index].stocktotal = StockInfo[index].stocktotal - Total;

            if (StockInfo[index].Ammount == 0)
            {
                StockInfo.erase(StockInfo.begin() + index);
            }

            stock2 transactionHis;
            transactionHis.symbol = symbol;
            transactionHis.price = currentinfo[index2].price;
            transactionHis.shares = Ammount;
            transactionHis.Action = "Sell ";
            transactionHis.H = hr;
            transactionHis.M = min;
            transactionHis.S = sec;
            StockInfo2.push_back(transactionHis);

            setBalance(cashBalance);
        }
    }
    else
    {
        cout << "\nInvalid Symbol" << endl;
    }
}

void stockAccount::currentPortfolio(vector<stock1> &StockInfo)
{
    double Total_portfolio_value;
    double cashBalance = getBalance();
    cout << "\nCash balance = " << cashBalance << endl;
    if (StockInfo.empty() != 1)
    {
        cout << left << setw(16) << "\nSymbol" << setw(28) << "Company" << setw(15) << "Number" << setw(15) << "Price"
             << setw(15) << "Total" << endl;
        for (int i = 0; i < StockInfo.size(); i++)
        {
            cout << left << setw(15) << StockInfo[i].name << setw(28) << StockInfo[i].desc << setw(15)
                 << StockInfo[i].Ammount << setw(15) << StockInfo[i].price << setw(15) << StockInfo[i].stocktotal << endl;
            Total_portfolio_value += StockInfo[i].stocktotal;
        }
        Total_portfolio_value += cashBalance;
        cout << "\nTotal portfolio value: $" << Total_portfolio_value << endl;
    }
}
void stockAccount::transactionHistory()
{
    ofstream myfile;
    myfile.open("stock_transaction_history.txt", ios_base::app);
    myfile << left << setw(15) << "Action" << setw(15) << "Symbol" << setw(15) << "Shares" << setw(15) << "Price" << setw(15) << "Time" << endl;
    for (int i = 0; i < StockInfo2.size(); i++)
    {
        myfile << left << setw(15) << StockInfo2[i].Action << setw(15) << StockInfo2[i].symbol << setw(15)
               << StockInfo2[i].shares << setw(15) << StockInfo2[i].price << StockInfo2[i].H << ":" << StockInfo2[i].M << ":" << StockInfo2[i].S << endl;
    }
    myfile.close();

    ifstream file("stock_transaction_history.txt");
    string line;
    while (getline(file, line))
        cout << line << endl;
    file.close();
    cout << endl;
}