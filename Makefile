account.o : account.cpp account.h
	g++ -c account.cpp

UserBankAction.o : UserBankAction.cpp UserBankAction.h 
	g++ -c UserBankAction.cpp

UserBankAuth.o : UserBankAction.cpp UserBankAction.h account.h
	g++ -c UserBankAuth.cpp

program : account.o UserBankAction.o UserBankAuth.o -o program