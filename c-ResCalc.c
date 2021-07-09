/*
Programmer: DHANUSH H V
Prog Lang : C-Language
Function  : Prints the resistance value using 4 color codes

Sample Input:
red red yellow gold

Sample Output:

R = 220000 (+/-)5% ohm
=========== More Info ===========
Resistance = 220 K-Ohm
Tolerance = (+/-)5%
R = 220 (+/-)5% K-Ohm
=================================

*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

// function to return the index of an item in an array
int getIndex(char str1[][12], char str2[], int sz)
{
    int index = 0;

    for (int i=0; i<sz; i++)
    {
        if (!strcmp(str1[i], str2))
        {
            index = i;
            break;
        }
    }

    return index;
}

int main()
{
    char act_clr[12][12] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "gray", "white", "gold", "silver"};
    char tol[9][12] = {"brown", "red", "green", "blue", "violet", "gray", "gold", "silver", "none"};
    char tol1[9][12] = {"(+/-)1p", "(+/-)2p", "(+/-)0.5p", "(+/-)0.25p", "(+/-)0.1p", "(+/-)0.05p", "(+/-)5p", "(+/-)10p", "(+/-)20p"};
    int pct[] = {1, 10, 100, 1000, 1e4, 1e5, 1e6, 1e7, 1e8, 1, 0.1, 0.01};

    char c[4][12];
    printf("Enter color code: ");
    scanf("%s %s %s %s", c[0], c[1], c[2], c[3]);

    int x1, x2, x3, x4;
    float x13, z2, z;

    x1 = getIndex(act_clr, c[0], 12);
    x2 = getIndex(act_clr, c[1], 12);
    x3 = getIndex(act_clr, c[2], 12);
    x4 = getIndex(tol, c[3], 9);

    x13 = pct[x3];
    char x14[12] = "";

    strcat(x14, tol1[x4]);

    char s1[4];
    char s2[4];

    sprintf(s1, "%d", x1);
    sprintf(s2, "%d", x2);

    char z1[12] = "";
    // concatenate the two digits
    strcat(z1, s1);
    strcat(z1, s2);

    z2 = atof(z1) * x13;

    printf("\nR = %.2f %s Ohm\n", z2, x14);

    char unit[12] = "";

    if (z2 >= 0 && z2 < 1000)
    {
        z = z2;
        strcat(unit, "Ohm");
    }

    else if (z2 >= 1000 && z2 < 1e6)
    {
        z = z2 * pow(10, -3);
        strcat(unit, "K-Ohm");
    }

    else if (z2 >= 1e6 && z2 < 1e9)
    {
        z = z2 * pow(10, -6);
        strcat(unit, "M-Ohm");
    }

    else
    {
        z = z2 * pow(10, -9);
        strcat(unit, "G-Ohm");
    }

    printf("\n=========== More Info ===========\n");
    printf("\nResistance = %.2f %s\n", z, unit);
    printf("Tolerance = %s\n", x14);
    printf("\nR = %.2f %s %s\n", z, x14, unit);
    printf("\n=================================\n");
    return 0;
}
