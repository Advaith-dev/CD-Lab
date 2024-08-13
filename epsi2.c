#include <stdio.h>
#include <string.h>

#define MAX_STATES 20
#define MAX_STATE_LENGTH 3

// Arrays to store results and states
char result[MAX_STATES][MAX_STATE_LENGTH];
char copy[MAX_STATE_LENGTH];
char states[MAX_STATES][MAX_STATE_LENGTH];

// Function to add a state to the result list
void add_state(char a[MAX_STATE_LENGTH], int i)
{
    strcpy(result[i], a);
}

// Function to display the epsilon closure
void display(int n)
{
    int k = 0;
    printf("\nEpsilon closure of %s = { ", copy);

    while (k < n)
    {
        printf(" %s", result[k]);
        k++;
    }
    printf(" }\n");
}

int main()
{
    FILE *INPUT;
    INPUT = fopen("input.dat", "r");

    if (INPUT == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    char state[MAX_STATE_LENGTH];
    int end, i = 0, n, k = 0;
    char state1[MAX_STATE_LENGTH], input[MAX_STATE_LENGTH], state2[MAX_STATE_LENGTH];

    printf("\nEnter the number of states: ");
    scanf("%d", &n);

    printf("\nEnter the states:\n");
    for (k = 0; k < n; k++)
    {
        scanf("%s", states[k]);
    }

    for (k = 0; k < n; k++)
    {
        i = 0;
        strcpy(state, states[k]);
        strcpy(copy, state);
        add_state(state, i++);

        while (1)
        {
            end = fscanf(INPUT, "%s%s%s", state1, input, state2);
            if (end == EOF)
            {
                break;
            }
            if (strcmp(state, state1) == 0)
            {
                if (strcmp(input, "e") == 0)
                {
                    add_state(state2, i++);
                    strcpy(state, state2);
                }
            }
        }

        display(i);
        rewind(INPUT);
    }

    fclose(INPUT);
    return 0;
}
