#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <cstdlib>

using namespace std;

class UserDataBase { 
    public: 
        char name[10];
        long int balance = 0;
        float user_account = 0.0;
        int normal_user_length = 6;
        int vip_user_length = 12;

        UserDataBase(); //constructor;
        ~UserDataBase(); //deconstructor;

	
        
	void HelloWorld();
    void CreateUser();
    private:
	int value = 0;
	char* GenerateAccountNumber(int length);
};
#endif