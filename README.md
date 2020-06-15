# Bank and Stock Management System  
This project models the stock market and the bank account using the c++ class features.
At the beginning of the program the cash balance for the account is set to $10000. This cash balance changes through the course of the program by performing different types of banking and stocking transactions. Program is divided into two child  classes "stockAccount" and "bankAccount" which is inherited and managed by the parent class "Account".  

* **Bank Account:**  This part of the Program manages the bank account and performs tasks such as displaying current balance/portfolio, deposit to account, withdraw from account, and display all the transactions performed on bank account.
* **Stock Account:** This part of the program manages the stock portfolio for account. It performs all the tasks related to stock, such as purchase and sell of stocks, check current price for specific stock symbol, display stock portfolio, and display all the stock transaction history. This program uses the stock information stored in "stock1.txt", "stock2.txt", "stock3.txt" and 'stock4.txt" for all of the transactions. It selects one of the flies randomly for stock prices to imitate the real life situation.  

### Usage  
The program can be run by using following commands in terminal:
```
make  
.\Bank_Account  
```
All the build files of the programm can be removed by running following command in terminal:
```
make clean
```


