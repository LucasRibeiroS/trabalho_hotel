#include <stdio.h>
#include <stdlib.h>
#include "../include/seeds.h"
#include "../../auth/include/login.h"

void createAdminUser(int storageType)
{
    // Verify if user alreay exists
    Usuario *user = findUser("admin", storageType);
    FILE *file = NULL;

    if (user == NULL)
    {
        Usuario admin = {
            0,
            "name",
            "admin",
            "dgplq",
        };
        switch (storageType)
        {
        case 1:
            file = fopen("files/users.bin", "a+b");

            if (file != NULL)
            {
                fwrite(&admin, sizeof(Usuario), 1, file);

                fclose(file);
            }

            break;
        case 2:
            file = fopen("files/users.txt", "a+");

            if (file != NULL)
            {
                fprintf(file, "%d;", admin.id);
                fprintf(file, "%s;", admin.nome);
                fprintf(file, "%s;", admin.username);
                fprintf(file, "%s;", admin.senha);

                fclose(file);
            }

            break;

        default:
            printf("Metódo de salvamento inváldio.");
            break;
        }

        if (file == NULL)
        {
            printf("Erro na abertura do arquivo.");
        }
    }
}

void createAccommodationCategories(int storageType)
{
}