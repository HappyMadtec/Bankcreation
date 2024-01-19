#include "account.h"


using namespace std;


char* UserDataBase::GenerateAccountNumber(int length){
	const char values[] ="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRTUVWXYZ012345679";
	char* random_string = new char[length +1];
	for(int i = 0; i<length; ++i){
		int random_char = rand()%(sizeof(values)-1);
		random_string[i] = values[random_char];

	}
	random_string[length] = '\0';
	return random_string;
}

void UserDataBase::CreateUser(){
	
	cout<<"What is your name?"<<endl;
	string name;
	getline(cin,name);
	cout<<"How much would you like to put in your bank account?"<<endl;
	cin>>balance;
	if (balance < 1000){
		GenerateAccountNumber(vip_user_length);
	}
	else {
		GenerateAccountNumber(normal_user_length);
	}

}

