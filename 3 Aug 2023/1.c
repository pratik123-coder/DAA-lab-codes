#include <stdio.h>
#include <stdlib.h>
// Write a program in C to convert the first ‘n’ decimal numbers of a disc
// file to binary using recursion. Store the binary value in a separate disc file.
void decimalToBinary(int decimalNum, FILE *destFile)
{
    if (decimalNum > 0)
    {
        decimalToBinary(decimalNum / 2, destFile);
        fprintf(destFile, "%d", decimalNum % 2);
    }
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: %s <n> <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    char *sourceFileName = argv[2];
    char *destFileName = argv[3];

    FILE *sourceFile = fopen(sourceFileName, "r");
    FILE *destFile = fopen(destFileName, "w");

    if (sourceFile == NULL || destFile == NULL)
    {
        printf("Error opening files.\n");
        return 1;
    }

    fprintf(destFile, "Contents of the output disc file \"%s\" as\n", destFileName);

    for (int i = 0; i < n; i++)
    {
        int decimalNum;
        if (fscanf(sourceFile, "%d", &decimalNum) == 1)
        {
            fprintf(destFile, "The binary equivalent of %d is ", decimalNum);
            decimalToBinary(decimalNum, destFile);
            fprintf(destFile, "\n");
        }
        else
        {
            printf("Source file doesn't have enough numbers.\n");
            break;
        }
    }

    fclose(sourceFile);
    fclose(destFile);

    printf("Binary values have been written to the destination file.\n");

    return 0;
}
