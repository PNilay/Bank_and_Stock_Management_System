#include <iostream>
#include "stockAccount.h"
#include "bankAccount.h"
#include "Account.h"
using namespace std;


void menu(int *num) // main Menu
{
    int select = 0;
    cout << "Welcome! Select options below:" << endl;

    cout << "\t1. Stock Portfolio Account."
         << "\n\t2. Bank Account."
         << "\n\t3. Exit." << endl;

    cout << "Selection:\t";
    cin >> select;
    *num = select;
}

void menu1(int *num) // Sub Menu for stock Account
{
    int select = 0;
    cout << "Welcome! Select options below:" << endl;

    cout << "\t1. Display current price for a stock symbol."
         << "\n\t2. Buy stock"
         << "\n\t3. Sell stock"
         << "\n\t4. Display current portfolio"
         << "\n\t5. Display transactions history"
         <<"\n\t6. Return to main menu"<<endl;


    cout << "Selection:\t";
    cin >> select;
    *num = select;
}

void menu2(int *num) // Sub menu for banking account
{
    int select = 0;
    cout << "Welcome! Select options below:" << endl;

    cout << "\t1. View account balance"
         << "\n\t2. Deposit money"
         << "\n\t3. Withdraw money"
         << "\n\t4. Display transactions history"
         << "\n\t5. Return to previous menu" <<endl;


    cout << "Selection:\t";
    cin >> select;
    *num = select;
}


int main() {
    int input = 0;
    vector< stock1> myVector;
    stockAccount stocksample1;
    bankAccount bankAccount1;

    while(input != 3)// run loop to continue program until terminated by user
    {
        menu(&input);

        switch (input) {
            case 1: {// Stock Portfolio Account
                int SubInput1 = 0;
                while (SubInput1 != 6)// run loop to continue program until terminated by user
                {
                    menu1(&SubInput1);
                    switch (SubInput1) {
                        case 1: stocksample1.currentPrice();
                            break;
                        case 2: stocksample1.buystock(myVector);
                            break;
                        case 3: stocksample1.sellstock(myVector);
                            break;
                        case 4: stocksample1.currentPortfolio(myVector);
                            break;
                        case 5: stocksample1.transactionHistory();
                            break;
                        case 6:
                            break;
                        default: {
                            cout << "\nYou entered a wrong input, please select menu again";
                        }
                            break;
                    }
                }
            }
                    break;
                case 2:
                    {;
                    // Bank Account
                    int SubInput2 = 0;
                    while (SubInput2 != 5)// run loop to continue program until terminated by user
                    {
                        menu2(&SubInput2);
                        switch (SubInput2)
                        {
                            case 1: bankAccount1.currentBalance(myVector);
                                break;
                            case 2: bankAccount1.deposit(myVector);
                                break;
                            case 3: bankAccount1.withdraw(myVector);
                                break;
                            case 4: bankAccount1.transactionsHistory();
                                break;
                            case 5:
                                break;
                            default:
                                cout << "\nYou entered a wrong input, please select menu again";
                                break;
                        }
                    }
                }
                        break;
                    case 3: {cout<<"\nBank is Closed";}
                        break;
                    default: cout<<"\nYou entered a wrong input, please select menu again";
                        break;
                    }
                     }

                     return 0;
                      }
