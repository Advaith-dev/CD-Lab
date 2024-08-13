#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char newString[100][30];

void main()
{
    FILE *f;
    f = fopen("nfa.txt", "r");

    char ch;

    int j = 0;
    int ctr = 0;
    int i = 0;
    int row, col;

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

    int numstate;
    printf("Enter the number of states: ");
    scanf("%d", &numstate);
    char nfa[numstate][numstate];

    for (i = 1; i < ctr; i += 3)
    {
        if (strcmp(newString[i], "e") == 0)
        {
            printf("%s\n", newString[i - 1]);
            printf("%s\n", newString[i]);
            printf("%s\n", newString[i + 1]);

           c
        }
    }
}
