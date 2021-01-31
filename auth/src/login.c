#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/login.h"

/* 
* Validates password
* Returns 1 if sucessful and 0 if fails
*/
int verifyPassword(char userPassword[], char inputPassword[])
{
    size_t length = strlen(inputPassword);
    char *encryptedPassword = malloc(sizeof(char) * length);
    // Encrypts the inputPassword in order to compare with
    // the encrypted one on the file
    for (int i = 0; i < length; i++)
    {
        if (((inputPassword[i] + 3) == '\\') || (inputPassword[i] + 3 == ';'))
        {
            encryptedPassword[i] = inputPassword[i] + 2;
            continue;
        }

        encryptedPassword[i] = inputPassword[i] + 3;
    }

    if (strcmp(userPassword, encryptedPassword) == 0)
    {
        return 1;
    }

    printf("\nSenha inválida\n");

    return 0;
}

Usuario *findUser(char username[], int storageType)
{
    FILE *file = NULL;
    Usuario *user = malloc(sizeof(Usuario));
    // Open file from correct config
    switch (storageType)
    {
    case 1:
        // Reads binary file
        file = fopen("files/users.bin", "rb");

        if (file != NULL)
        {
            Usuario tempUser;
            // Go through every binary looking for the username
            while (fread(&tempUser, sizeof(Usuario), 1, file))
            {
                if (strcmp(username, tempUser.username) == 0)
                {
                    user->id = tempUser.id;
                    strcpy(user->nome, tempUser.nome);
                    strcpy(user->username, tempUser.username);
                    strcpy(user->senha, tempUser.senha);

                    return user;
                }
            }
        }
        break;
    case 2:
        // Reads text file
        file = fopen("files/users.txt", "r");
        if (file != NULL)
        {
            char userString[400];
            Usuario tempUser;
            // Go through every line looking for the username
            while (fgets(userString, 400, file) != NULL)
            {
                char *token = strtok(userString, ";");
                for (int i = 0; token != NULL; i++)
                {
                    switch (i)
                    {
                    case 0:
                        tempUser.id = atoi(token);
                        break;
                    case 1:
                        strcpy(tempUser.nome, token);
                        break;
                    case 2:
                        strcpy(tempUser.username, token);
                        break;
                    case 3:
                        strcpy(tempUser.senha, token);
                        break;
                    default:
                        break;
                    }

                    token = strtok(NULL, ";");
                }

                if (strcmp(username, tempUser.username) == 0)
                {
                    user->id = tempUser.id;
                    strcpy(user->nome, tempUser.nome);
                    strcpy(user->username, tempUser.username);
                    strcpy(user->senha, tempUser.senha);

                    return user;
                }
            }
        }
        break;
    default:
        break;
    }

    if (file == NULL)
    {
        printf("\nFalha ao abrir o arquivo de usuário\n");
    }

    return NULL;
}

Usuario *login(char username[], char password[], int storageType)
{
    Usuario *user = findUser(username, storageType);

    if (user == NULL)
    {
        printf("\nUsuário não encontrado\n");
        return NULL;
    }
    else if (verifyPassword(user->senha, password) == 1)
    {
        return user;
    }

    return NULL;
}