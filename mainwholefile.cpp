#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

// use design patterns in the creation of this bank simulation 
// do unit tests -> check for libraries
// check for technics to verify the tests (memory leaks -- read rational test realtime)
//{memory leak , performance bottleneck, logic error in c++ code}
using namespace std;
class PrintingFiles {
public:
	int balance;
    PrintingFiles(const string& name, const string& account, double initialBalance) {}

    void printingFilesTXT(ofstream& outputFile);
    int printingUser2Files(const string& username);
};

void PrintingFiles::printingFilesTXT(ofstream& outputFile) {
    outputFile << "|------------------------------------" << endl;
    outputFile << "|          Bank Statement for  << name << " << endl;
    outputFile << "|          Account:  << user_account << " << endl;
    outputFile << "|------------------------------------" << endl;
    outputFile << endl;
    outputFile << endl;
    outputFile << "Your balance is: " << balance << endl;
    outputFile << endl;
}

int PrintingFiles::printingUser2Files(const string& username) {
    string filename = username + ".txt";

    ifstream fileCheck(filename);
    if (fileCheck.good()) {
        cout << "File exists" << endl;
    }
    fileCheck.close();

    ofstream outputFile(filename, ios::out | ios::trunc);
    if (!outputFile.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    } else {
        printingFilesTXT(outputFile);
        return 0;
    }
}

class MyBankActions  { //composition
private: 
	UserDataBase operations;
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
	
	operations.balance += depositValue;

	cout<<"Dear customer your new balance is: "<<operations.balance<<endl;
}

void MyBankActions::withdraw(){
	int withdrawValue = 0;
	cout<<"You chose to withdraw!"<<endl;
	cin>>withdrawValue;
	if (operations.balance < withdrawValue){
		cout<<"No enough balance"<<endl;
	}
	else {
		operations.balance -= withdrawValue;
	}
	cout<<"Dear customer your new balance is: "<<operations.balance<<endl; 
	
}


void MyBankActions::displayStatement(){
	cout<<"Your current balance is: "<<operations.balance<<endl;
}

class UserDataBase : public PrintingFiles { 
	public: 
        
		string name;
        long int balance = 0;
        string user_account;
        int normal_user_length = 6;
        int vip_user_length = 12;

        //UserDataBase(); //constructor;
        //~UserDataBase(); //deconstructor;
	UserDataBase() {
        CreateUser();
    }

    // Destructor
    ~UserDataBase() {
	}

    void CreateUser();
    private:
	int value = 0;
	char* GenerateAccountNumber(int length);
	void makeMyfile();
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





int  main(){
    /*
	string name ; 
    int balance; 
    cout<<"What is the user name for your bank account?"<<endl;
    getline(cin,name);
    cout<<"what are the initial balance you want to put in your account?"<<endl;
    cin>>balance;
	*/
    UserDataBase Maickel;
    cout << "User Name: " << Maickel.name << endl;
    cout << "User Account: " << Maickel.user_account << endl;
    cout << "User Balance: " << Maickel.balance << endl;
    
    return 0;
}
