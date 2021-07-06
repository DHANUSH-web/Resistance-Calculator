
/*
Programmer: DHANUSH H V
Prog Lang : JavaScript (NodeJS)
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

// finding the index of an item in list or array
function indexOf(array, item)
{
    let index = 0;

    for (let i=0; i<array.length; i++)
    {
        if (array[i] == item)
        {
            index = i;
            break;
        }
    }

    return index; // returning index of item in array
}

let act_clr = ["black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "gray", "white", "gold", "silver"];
let tol = ["brown", "red", "green", "blue", "violet", "gray", "gold", "silver", "none"];
let tol1 = ["±1%", "±2%", "±0.5%", "±0.25%", "±0.1%", "±0.05%", "±5%", "±10%", "±20%"];
let pct = [1, 10, 100, 1000, 1e4, 1e5, 1e6, 1e7, 1e8, 1, 0.1, 0.01];

let c = "black brown green gold";
c = c.split(" ");

let x1, x2, x3, x4, x13, x14, z1, z2, z, resistance, unit;

x1 = indexOf(act_clr, c[0]);
x2 = indexOf(act_clr, c[1]);
x3 = indexOf(act_clr, c[2]);
x4 = indexOf(tol, c[3]);

x13 = pct[x3];
x14 = tol1[x4];

z1 = `${x1}${x2}`;
z2 = parseFloat(z1) * x13;

console.log("R = " + z2 + " " + x14 + " Ω");

console.log("\n============= More Info =============\n");

if (z2 >= 0 && z2 < 1000)
{
    resistance = z2;
    unit = "Ω";
}

else if (z2 >= 1000 && z2 < 1e6)
{
    resistance = z2 * Math.pow(10, -3);
    unit = "KΩ";
}

else if (z2 >= 1e6 && z2 < 1e7)
{
    resistance = z2 * Math.pow(10, -6);
    unit = "MΩ";
}

else
{
    resistance = z2 * Math.pow(10, -9);
    unit = "GΩ";
}

console.log(`Resistance = ${resistance} ${unit}\nTolerance = ${x14}`);
console.log(`\nR = ${resistance} ${x14} ${unit}`);
console.log("\n=====================================");
