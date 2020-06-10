Bank_Account: Account.o bankAccount.o stockAccount.o main.o
	g++ Account.o bankAccount.o stockAccount.o main.o -o Bank_Account

Account.o: Account.cpp
	g++ -c Account.cpp

bankAccount.o: bankAccount.cpp
	g++ -c bankAccount.cpp

stockAccount.o: stockAccount.cpp
	g++ -c stockAccount.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o Bank_Account