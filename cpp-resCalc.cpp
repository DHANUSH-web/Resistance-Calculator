/*
Programmer: DHANUSH H V
Prog Lang : C++
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

// all the headerfiles can be replaced with single header file: #include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<sstream>
// #include<bits/stdc++.h>
using namespace std;

// function to return the index of an item in the vector
int indexOf(vector<auto> items, auto item)
{
    int index = -1;
    for (int i=0; i<items.size(); i++)
    {
        if (items[i] == item)
        {
            index = i;
            break;
        }
    }

    return index;
}

int main()
{
    vector<string> act_clr = {"black", "brown", "red", "orange", "yellow", "green",
                              "blue", "violet", "gray", "white", "gold", "silver"};

    vector<string> tol = {"brown", "red", "green", "blue", "violet", "gray", "gold", "silver", "none"};
    vector<string> tol1 = {"(+/-)1%", "(+/-)2%", "(+/-)0.5%", "(+/-)0.25%", "(+/-)0.1%", "(+/-)0.05%", "(+/-)5%", "(+/-)10%", "(+/-)20%"};
    vector<float> pct = {1, 10, 100, 1000, 1e4, 1e5, 1e6, 1e7, 1e8, 1, 0.1, 0.01};

    string c1, c2, c3, c4, x14, z1, s1, s2, unit;
    int x1, x2, x3, x4;
    float x13, z2, z;

    cout << "Enter color codes: ";
    cin >> c1 >> c2 >> c3 >> c4;

    x1 = indexOf(act_clr, c1);
    x2 = indexOf(act_clr, c2);
    x3 = indexOf(act_clr, c3);
    x4 = indexOf(tol, c4);

    x13 = pct[x3];
    x14 = tol1[x4];

    stringstream ss1, ss2;
    ss1 << x1;
    ss2 << x2;

    ss1 >> s1;
    ss2 >> s2;

    z1 = s1 + s2;
    z2 = stof(z1) * x13;

    cout << "\nR = " << z2 << " " << x14 << " ohm" << endl;

    if (z2 >= 0 && z2 < 1000)
    {
        z = z2;
        unit = "ohm";
    }

    else if (z2 >= 1000 && z2 < 1e6)
    {
        z = z2 * pow(10, -3);
        unit = "K-Ohm";
    }

    else if (z2 >= 1e6 && z2 < 1e9)
    {
        z = z2 * pow(10, -6);
        unit = "M-Ohm";
    }

    else
    {
        z = z2 * pow(10, -9);
        unit = "G-Ohm";
    }

    cout << "\n=========== More Info ===========\n" << endl;
    cout << "Resistance = " << z << " " << unit << endl;
    cout << "Tolerance = " << x14 << endl;
    cout << "\nR = " << z << " " << x14 << " " << unit << endl;
    cout << "\n=================================" << endl;

    return 0;
  }
