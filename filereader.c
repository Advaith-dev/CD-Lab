#include <stdio.h>
#include <string.h>
#include <ctype.h>

void header_Check(int j);
void keyword_Check(int j);
void operator_Check(int j);
void specialc_Check(int j);
void literal_check(int j);

char newString[100][30];

void main()
{
    FILE *f;
    f = fopen("t.txt", "r");

    char ch;

    int i = 0;
    int j = 0;
    int ctr = 0;

    do
    {
        ch = fgetc(f);
        if (ch == ' ' || ch == '\0' || ch == '\n' || ch == '\t')
        {
            newString[ctr][j] = '\0';
            ctr++;
            j = 0;
        }
        else
        {
            newString[ctr][j] = ch;
            j++;
        }
        i += 1;

    } while (ch != EOF);

    for (i = 0; i < ctr; i++)
    {

        header_Check(i);

        keyword_Check(i);
        operator_Check(i);
        specialc_Check(i);
        literal_check(i);

        fclose(f);
    }
}
void header_Check(int j)
{
    if (strncmp(newString[j], "#include", 8) == 0)
    {
        printf("Preprocessor Directives: %s\n", newString[j]);
    }
}

void keyword_Check(int j)
{
    if (
        strcmp(newString[j], "void") == 0 ||
        strcmp(newString[j], "int") == 0 ||
        strcmp(newString[j], "char") == 0 ||
        strcmp(newString[j], "for") == 0 ||
        strcmp(newString[j], "if") == 0 ||
        strcmp(newString[j], "else") == 0)
    {
        printf("Keyword: %s\n", newString[j]);
    }

    if (strcmp(newString[j], "int") == 0 || strcmp(newString[j], "char") == 0 || strcmp(newString[j], "void") == 0)
    {
        printf("Identifier: %s\n", newString[j + 1]);
    }
}

void operator_Check(int j)
{
    if (
        strcmp(newString[j], "+") == 0 ||
        strcmp(newString[j], "-") == 0 ||
        strcmp(newString[j], "*") == 0 ||
        strcmp(newString[j], "/") == 0 ||
        strcmp(newString[j], "//") == 0)
    {
        printf("Operator: %s\n", newString[j]);
    }
    else if (strcmp(newString[j], "=") == 0)
    {
        printf("Assignment operator: %s\n", newString[j]);
    }
}

void specialc_Check(int j)
{
    if (
        strcmp(newString[j], "(") == 0 ||
        strcmp(newString[j], ")") == 0 ||
        strcmp(newString[j], "[") == 0 ||
        strcmp(newString[j], "]") == 0 ||
        strcmp(newString[j], ";") == 0)
    {
        printf("Special character: %s\n", newString[j]);
    }
}

void literal_check(int j)
{
    if (isdigit(newString[j][0]) || newString[j][0] == '\'')
    {
        printf("literal: %s\n", newString[j]);
    }
}
