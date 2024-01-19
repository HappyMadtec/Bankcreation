#include "account.h"

class UserAuth : private UserDataBase {

	bool Authentification(char* code);
	
// the user can try and identify 3 times 
// scenario 3 Users 
// First user is good authentification
// Second User fails the first try or the second try and succeed on the third or second
// Last user fails the 3 trials and his account is blocked

};
