#ifndef CONFIG_H
#define CONFIG_H

/*
* Returns the current storage type,
* 1 for binary or 2 for text.
*/
int getStorageType();

/*
* Updates the config file with the 
* newStorage param, use newStorage = 1
* for binary and newStorage = 2 for text.
* Returns the storage type
*/
int updateStorageType(int newStorage);

#endif