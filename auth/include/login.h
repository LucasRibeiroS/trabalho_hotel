#ifndef LOGIN_H
#define LOGIN_H

#include "../../utils/include/types.h"

/* 
* Search user by username.
* Returns an instance of 'Usuario'
*/
Usuario *findUser(char username[], int storageType);

/* 
* Search user by username and validate password
* Returns an instance of 'Usuario' if login is sucessful
*/
Usuario *login(char username[], char password[], int storageType);

#endif
