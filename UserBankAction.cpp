#include "UserBankAction.h"
#include <iostream>
#include <string.h>

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
	cout<<"Your current balance is: "<<balance<<endl;
}

void transfer(){
	cout<<"Please enter the user's bank name: "<<endl;
	
	
}
