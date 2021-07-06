/*
Programmer: DHANUSH H V
Prog Lang : C#
Function  : Prints the resistance value using 4 color codes
Example:
Sample Input:
brown red brown gold
Sample Output:
R = 120 ±5% Ω
=================== More Details ====================
Resistance = 120 Ω
Tolerance = ±5%
R = 120 ±5% Ω
=====================================================
*/

// Simple resistance calculator using its color-code
// 4 color-codes

using System;
using System.Collections.Generic;   // used to work with arrays

namespace ResistanceCalculator
{
    public class MainClass
    {
        public static void Main(string[] args)
        {
            string[] act_clr = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "gray", "white", "gold", "silver"};

            double[] pct = {1, 10, 100, 1000, 1e4, 1e5, 1e6, 1e7, 1e8, 1, 0.1, 0.01};

            string[] tol = {"brown", "red", "green", "blue", "violet", "gray", "gold",
                            "silver", "none"};

            string[] tol1 = {"±1%", "±2%", "±0.5%", "±0.25%", "±0.1%", "±0.05%", "±5%",
                             "±10%", "±20%"};


            Console.Write("Enter color codes: ");
            string cols = Console.ReadLine();

            string[] c = cols.Split(" ");

            int x1, x2, x3, x4;
            double x13, z2, z;
            string x14, z1;

            x1 = Array.IndexOf(act_clr, c[0]);
            x2 = Array.IndexOf(act_clr, c[1]);
            x3 = Array.IndexOf(act_clr, c[2]);
            x4 = Array.IndexOf(tol, c[3]);

            x13 = pct[x3];
            x14 = tol1[x4];

            z1 = $"{x1}{x2}";
            z2 = float.Parse(z1) * x13;

            Console.WriteLine($"\nR = {z2} {x14} Ω");

            Console.WriteLine("\n================= More Details =================\n");

            if (z2 >= 0 && z2 < 1000)
            {
                Console.WriteLine($"Resistance = {z2} Ω\nTolerance = {x14}\n");
                Console.WriteLine($"R = {z2} {x14} Ω");
            }

            else if (z2 >= 1000 && z2 < 999000)
            {
                z = z2 * Math.Pow(10, -3);

                Console.WriteLine($"Resistance = {z} KΩ\nTolerance = {x14}\n");
                Console.WriteLine($"R = {z} {x14} KΩ");
            }

            else if (z2 >= 1e6 && z2 < 999000000)
            {
                z = z2 * Math.Pow(10, -6);

                Console.WriteLine($"Resistance = {z} MΩ\nTolerance = {x14}\n");
                Console.WriteLine($"R = {z} {x14} MΩ");
            }

            else
            {
                z = z2 * Math.Pow(10, -9);

                Console.WriteLine($"Resistance = {z} GΩ\nTolerance = {x14}\n");
                Console.WriteLine($"R = {z} {x14} GΩ");
            }

            Console.WriteLine("\n================================================");
        }
    }
}
