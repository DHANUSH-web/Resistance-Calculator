/*
Programmer: DHANUSH H V
Prog Lang : Java
Function  : Prints the resistance value using 4 color codes
Example:
Sample Input:
brown red brown gold
Sample Output:
R = 120 (+/-)5% Ohm
=================== More Details ====================
Resistance = 120 Ohm
Tolerance = (+/-)5%
R = 120 (+/-)5% Ohm
=====================================================
*/

import java.util.Scanner;
import java.util.ArrayList;

class ResistanceCalculator
{
    static int index(int[] array, int e)
    {
        // create arraylist
        ArrayList<Integer> a = new ArrayList<>();

        for (int i : array)
        {
            a.add(i);
        }

        return a.indexOf(e);
    }

    static int index(String[] array, String e)
    {
        ArrayList<String> a = new ArrayList<>();

        for (String i : array)
        {
            a.add(i);
        }

        return a.indexOf(e);
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        String[] act_clr = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "gray", "white", "gold", "silver"};

        String[] tol = {"brown", "red", "green", "blue", "violet", "gray", "gold", "silver", "none"};

        String[] tol1 = {"(+/-)1%", "(+/-)2%", "(+/-)0.5%", "(+/-)0.25%", "(+/-)0.1%", "(+/-)0.05%", "(+/-)5%", "(+/-)10%", "(+/-)20%"};

        double[] pct = {1, 10, 100, 1000, 1e4, 1e5, 1e6, 1e7, 1e8, 1,
                       0.1, 0.01};

        System.out.print("Enter color code: ");
        String cols = sc.nextLine();

        String[] c = cols.split(" ");

        int x1, x2, x3, x4;
        double x13, z2, z;
        String x14, z1;

        x1 = index(act_clr, c[0]);
        x2 = index(act_clr, c[1]);
        x3 = index(act_clr, c[2]);
        x4 = index(tol, c[3]);

        x13 = pct[x3];
        x14 = tol1[x4];

        z1 = x1 + "" + x2;
        z2 = Float.parseFloat(z1) * x13;

        System.out.println("\nR = " + z2 + " " + x14 + " Ohm\n");

        System.out.println("\n============== More Details ==============\n");

        if (z2 >= 0 && z2 < 1000)
        {
            System.out.println("Resistance = " + z2 + " Ohm\nTolerance = " + x14);
            System.out.println("\nResistance = " + z2 + " " + x14 + " Ohm");
        }

        else if (z2 >= 1000 && z2 < 999000)
        {
            z = z2 * Math.pow(10, -3);

            System.out.println("Resistance = " + z + " KOhm\nTolerance = " + x14);
            System.out.println("\nResistance = " + z + " " + x14 + " KOhm");
        }

        else if (z2 >= 1e6 && z2 < 999000000)
        {
            z = z2 * Math.pow(10, -6);

            System.out.println("Resistance = " + z + " MOhm\nTolerance = " + x14);
            System.out.println("\nResistance = " + z + " " + x14 + " MOhm");
        }

        else
        {
            z = z2 * Math.pow(10, -9);

            System.out.println("Resistance = " + z + " GOhm\nTolerance = " + x14);
            System.out.println("\nResistance = " + z + " " + x14 + " GOhm");
        }

        System.out.println("\n==========================================");

        sc.close();
    }
}
