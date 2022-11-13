#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int schaakbord[20], count;

int display(int);
void queen_function(int, int);
int placeholder(int, int);

void queen_function(int rijwaarde, int aantalQ)
{
    int kolomwaarde;
    for (kolomwaarde = 1; kolomwaarde <= aantalQ; kolomwaarde++)
    {
        if (placeholder(rijwaarde, kolomwaarde))
        {
            schaakbord[rijwaarde] = kolomwaarde;
            if (rijwaarde == aantalQ)
            {
                display(aantalQ);
            }
            else
            {
                queen_function(rijwaarde + 1, aantalQ);
            }
        }
    }
}

int placeholder(int rijwaarde, int kolomwaarde)
{
    int count;
    for (count = 1; count <= rijwaarde - 1; count++)
    {
        if (schaakbord[count] == kolomwaarde)
        {
            return 0;
        }
        else
        {
            if (abs(schaakbord[count] - kolomwaarde) == abs(count - rijwaarde))
            {
                return 0;
            }
        }
    }
    return 1;
}

int display(int aantalQ)
{
    int m, n;
    printf("\n\n\tPossible Solution %d:\n\n", ++count);
    for (m = 1; m <= aantalQ; m++)
    {
        printf("\t[%d]", m);
    }
    for (m = 1; m <= aantalQ; m++)
    {
        printf("\n\n[%d]", m);
        for (n = 1; n <= aantalQ; n++)
        {
            if (schaakbord[m] == n)
            {
                printf("\tQ");
            }
            else
            {
                printf("\t*");
            }
        }
    }
}

void main()
{
    int aantalQ = 7;
    queen_function(1, aantalQ);
    printf("\n\n");
}
