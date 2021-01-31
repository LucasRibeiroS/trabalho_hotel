#include <stdio.h>
#include <stdlib.h>
#include "../include/config.h"

int getStorageType()
{
    // File declaration and opening
    FILE *file = NULL;
    file = fopen("files/config.bin", "rb");

    if (!file)
    {
        // Close current file
        fclose(file);

        // Create new file with binary standart
        updateStorageType(1);
    }

    // Reads the file content and write into type variable
    int type;
    fread(&type, sizeof(int), 1, file);

    // Close file
    fclose(file);

    return type;
}

int updateStorageType(int newStorage)
{
    // New storage validation
    if (newStorage == 1 || newStorage == 2)
    {
        // File declaration and opening
        FILE *file = NULL;
        file = fopen("files/config.bin", "wb");

        if (file == NULL)
        {
            printf("\nErro ao abrir arquivo de configuração\n");
            exit(1);
        }

        // Write newStorage value into file
        fwrite(&newStorage, sizeof(int), 1, file);

        // Close file
        fclose(file);

        return newStorage;
    }
    else
    {
        printf("\nTipo de armazenamento inválido.\n");
        return getStorageType();
    }
}