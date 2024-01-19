#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class UserDataBase { 
    public: 
        char name[10];
        long int balance = 0;
        string user_account;
        int normal_user_length = 6;
        int vip_user_length = 12;

        //UserDataBase(); //constructor;
        //~UserDataBase(); //deconstructor;

    void CreateUser();
    private:
	int value = 0;
	char* GenerateAccountNumber(int length);
};

char* UserDataBase::GenerateAccountNumber(int length){
	const char values[] ="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRTUVWXYZ012345679";
	char* random_string = new char[length +1];
	for(int i = 0; i<length; ++i){
		int random_char = rand()%(sizeof(values)-1);
		random_string[i] = values[random_char];

	}
	random_string[length] = '\0';
    user_account = random_string;
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

class MyBankActions : public UserDataBase {
public:
	void deposit();
	void withdraw();
	void displayStatement();
	void transfer();


};

void MyBankActions::deposit(){
	int depositValue = 0;
	
	cout<<"You chose to deposit!"<<endl;
	
	cin>>depositValue;
	
	balance += depositValue;

	cout<<"Dear customer your new balance is: "<<balance<<endl;
}

void MyBankActions::withdraw(){
	int withdrawValue = 0;
	
	cout<<"You chose to withdraw!"<<endl;

	cin>>withdrawValue;
	if (balance < withdrawValue){
		cout<<"No enough balance"<<endl;
	}
	else {
		balance -= withdrawValue;
	}
	cout<<"Dear customer your new balance is: "<<balance<<endl; 
	
}

void MyBankActions::displayStatement(){
    
}

void MyBankActions::displayStatement(){
	cout<<"Your current balance is: "<<balance<<endl;
}

void transfer(){
	cout<<"Please enter the user's bank name: "<<endl;
	
}


int  main(){
    string name ; 
    int balance; 
    cout<<"What is the user name for your bank account?"<<endl;
    getline(cin,name);
    cout<<"what are the initial balance you want to put in your account?"<<endl;
    cin>>balance;

    UserDataBase Maickel;
    Maickel.balance = balance;
    Maickel.CreateUser();
    
    return 0;
}
