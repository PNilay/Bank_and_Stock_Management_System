#include "bankAccount.h"
struct Bank{
    string Action;
    double  Amount;
    double cashBal;
    string H;
    string M;
    string S;
    string Month;
    string Day;
    string Year;
};


vector <Bank> BankInfo;
void bankAccount::currentBalance(vector<stock1>& StockInfo) {
    double Total_portfolio_value;
    double cashBalance = getBalance();
    cout<<"\nCash balance = "<<cashBalance<<endl;
    if (StockInfo.empty() != 1) {
        cout << left << setw(16) << "\nSymbol" << setw(28) << "Company" << setw(15) << "Number" << setw(15) << "Price"
             << setw(15) << "Total" << endl;
        for (int i = 0; i < StockInfo.size(); i++) {
            cout << left << setw(15) << StockInfo[i].name << setw(28) << StockInfo[i].desc << setw(15)
                 << StockInfo[i].Ammount <<
                 setw(15) << StockInfo[i].price << setw(15) << StockInfo[i].stocktotal << endl;
            Total_portfolio_value += StockInfo[i].stocktotal;
        }
    }
    Total_portfolio_value += cashBalance;

}
double bankAccount::deposit(vector<stock1>& StockInfo) {
    double deposit;
    cout<<"\nEnter Amount deposit:";
    cin>>deposit;
    string B = to_string(deposit);
    deposit = stod(validInput(B));
    double Total_portfolio_value;

    cout<<"\nDeposit $ "<<deposit<<" bank account"<<endl;
    double cashBalance = getBalance()+ deposit;
    cout<<"\nCash balance = "<<cashBalance<<endl;
    if(StockInfo.empty() !=1) {
        cout << left << setw(16) << "\nSymbol" << setw(28) << "Company" << setw(15) << "Number" << setw(15) << "Price"
             << setw(15) << "Total" << endl;
        for (int i = 0; i < StockInfo.size(); i++) {
            cout << left << setw(15) << StockInfo[i].name << setw(28) << StockInfo[i].desc << setw(15)
                 << StockInfo[i].Ammount <<
                 setw(15) << StockInfo[i].price << setw(15) << StockInfo[i].stocktotal << endl;
            Total_portfolio_value += StockInfo[i].stocktotal;
        }
        Total_portfolio_value += cashBalance;
        cout<<"\nTotal portfolio value: " <<Total_portfolio_value<<endl;
    }
    time_t T = time(NULL);
    tm* timePtr = localtime(&T);

    string  hr = to_string(timePtr->tm_hour);
    string min = to_string(timePtr->tm_min);
    string sec = to_string(timePtr->tm_sec);
    string  month = to_string(timePtr->tm_mon);
    string day = to_string(timePtr->tm_mday);
    string year = to_string((timePtr->tm_year)+1900);

    Bank BankHis;
    BankHis.Amount = deposit;
    BankHis.cashBal = cashBalance;
    BankHis.Action = "Deposit";
    BankHis.H = hr;
    BankHis.M = min;
    BankHis.S = sec;
    BankHis.Month = month;
    BankHis.Day = day;
    BankHis.Year = year;
    BankInfo.push_back(BankHis);
    setBalance(cashBalance);
}


double bankAccount::withdraw(vector<stock1>& StockInfo) {
    double withdraw;
    cout<<"\nEnter Amount to withdraw: $";
    cin>>withdraw;
    string B = to_string(withdraw);
    withdraw = stod(validInput(B));

    double Total_portfolio_value;
    double cashBalance = getBalance()- withdraw;
    if (withdraw < cashBalance) {
        cout << "\nWithdraw $ " << withdraw << " bank account" << endl;
        cout << "\nCash balance = " << cashBalance << endl;
        if (StockInfo.empty() != 1) {
            cout << left << setw(16) << "\nSymbol" << setw(28) << "Company" << setw(15) << "Number" << setw(15)
                 << "Price"
                 << setw(15) << "Total" << endl;
            for (int i = 0; i < StockInfo.size(); i++) {
                cout << left << setw(15) << StockInfo[i].name << setw(28) << StockInfo[i].desc << setw(15)
                     << StockInfo[i].Ammount <<
                     setw(15) << StockInfo[i].price << setw(15) << StockInfo[i].stocktotal << endl;
                Total_portfolio_value += StockInfo[i].stocktotal;
            }
            Total_portfolio_value += cashBalance;
            cout << "\nTotal portfolio value: $" << Total_portfolio_value << endl;
        }
        time_t T = time(NULL);
        tm *timePtr = localtime(&T);

        string hr = to_string(timePtr->tm_hour);
        string min = to_string(timePtr->tm_min);
        string sec = to_string(timePtr->tm_sec);
        string month = to_string(timePtr->tm_mon);
        string day = to_string(timePtr->tm_mday);
        string year = to_string((timePtr->tm_year) + 1900);

        Bank BankHis;
        BankHis.Amount = withdraw;
        BankHis.cashBal = cashBalance;
        BankHis.Action = "Withdraw";
        BankHis.H = hr;
        BankHis.M = min;
        BankHis.S = sec;
        BankHis.Month = month;
        BankHis.Day = day;
        BankHis.Year = year;
        BankInfo.push_back(BankHis);
        setBalance(cashBalance);
    } else{
        cout<<"\nInvalid Input"<<endl;
    }
}

void bankAccount::transactionsHistory(){
    ofstream myfile;
    myfile.open("bank_transaction_history.txt", ios_base::app);
    if(BankInfo.empty() != 1) {
        myfile << left << setw(15) << "Action" << setw(15) << "Amount" << setw(15) << "Cash Balance" << setw(15)
               << "Date " << setw(15) << "Time" << endl;
        for (int i = 0; i < BankInfo.size(); i++) {
            myfile << left << setw(15) << BankInfo[i].Action << setw(15) << BankInfo[i].Amount << setw(15)
                   << BankInfo[i].cashBal << BankInfo[i].Month << "/" << BankInfo[i].Day << "/" << setw(11)
                   << BankInfo[i].Year
                   << BankInfo[i].H << ":" << BankInfo[i].M << ":" << BankInfo[i].S << endl;
        }
        myfile.close();

        ifstream file("bank_transaction_history.txt");
        string line;
        while (getline(file, line))
            cout << line << endl;
        file.close();
        cout << endl;
    }
}