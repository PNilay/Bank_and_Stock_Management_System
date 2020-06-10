#include "Account.h"

Account::Account()
{
}


double Account::cashBalance = 10000;

double Account::getBalance() {
    return cashBalance;
}
void Account::setBalance(double &bal) {
    cashBalance = bal;
}

string Account::validInput(string Input)   // This function check if the user input number is valid.
{
    string Correct_input;
    string Numbers = ".0123456789";
    int Checking =0;
    int index =0;
    while(Input[index] != 0)
    {
        int i =0;
        for (i =0; i <= 10; i++){

            if (Input[index] == Numbers[i])
            {
                Checking++;
                break;
            }
        }
        index++;
    }
    if (index == Checking)
    {
        Correct_input = Input;
    }
    else  // if the number inputted is invalid then this else statement will run.
    {
        string k;
        cout<<"You entered Invalid input."<<endl;
        cout<<"\nPlease Enter new number:";
        cin>>k;
        Correct_input = validInput(k);
        cout<<endl;
    }
    return Correct_input;
}

