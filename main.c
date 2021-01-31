#include <stdio.h>
#include <stdlib.h>
#include "config/include/config.h"
#include "config/include/seeds.h"
#include "utils/include/types.h"
#include "auth/include/login.h"

int main(int argc, char const *argv[])
{
    // Load config
    // Load storage type
    int storageType = getStorageType();
    // TO-DO
    // Load seeders
    createAdminUser(storageType);

    // Log in
    while (1)
    {
        char username[25];
        char password[25];
        printf("\nDigite seu nome de usuário\n");
        scanf("%s", username);
        printf("\nDigite sua senha\n");
        scanf("%s", password);

        Usuario *user = login(username, password, storageType);

        if (user != NULL)
        {
            printf("Usuario logado");
            break;
        }
    }

    return 0;
}
