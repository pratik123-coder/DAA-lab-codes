#include <stdio.h>
// Write a program in C to find GCD of two numbers using recursions.
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    char *sourceFileName = argv[1];
    char *destFileName = argv[2];

    FILE *sourceFile = fopen(sourceFileName, "r");
    FILE *destFile = fopen(destFileName, "w");

    if (sourceFile == NULL || destFile == NULL)
    {
        printf("Error opening files.\n");
        return 1;
    }

    int num1, num2;
    fprintf(destFile, "Results of GCD calculations from \"%s\" as:\n", sourceFileName);

    while (fscanf(sourceFile, "%d %d", &num1, &num2) == 2)
    {
        int result = gcd(num1, num2);
        fprintf(destFile, "GCD of %d and %d is %d\n", num1, num2, result);
    }

    fclose(sourceFile);
    fclose(destFile);

    printf("GCD results have been written to the destination file.\n");

    return 0;
}
