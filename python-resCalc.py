'''
Programmer: DHANUSH H V
Prog Lang : Python
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
'''

def indexOf(items, item):
    return items.index(item)

act_clr = ["black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "gray", "white", "gold", "silver"]
tol = ["brown", "red", "green", "blue", "violet", "gray", "gold", "silver", "none"]
tol1 = ["±1%", "±2%", "±0.5%", "±0.25%", "±0.1%", "±0.05%", "±5%", "±10%", "±20%"]
pct = [1, 10, 100, 1000, 1e4, 1e5, 1e6, 1e7, 1e8, 1, 0.1, 0.01]

c = input("Enter color code: ").split(" ")

# get the index of all the colors
x1 = indexOf(act_clr, c[0])
x2 = indexOf(act_clr, c[1])
x3 = indexOf(act_clr, c[2])
x4 = indexOf(tol, c[3])

x13 = pct[x3]
x14 = tol1[x4]   # to get the tolerance value of color using index

z1 = str(x1) + str(x2)
z2 = float(z1) * x13

print(f"\nR = {z2} {x14} Ω")

if z2 in range(0, 1000):
    z = z2
    unit = "Ω"
    
elif z2 in range(1000, 1000000):
    z = z2 * pow(10, -3)
    unit = "KΩ"
    
elif z2 in range(1000000, 1000000000):
    z = z2 * pow(10, -6)
    unit = "MΩ"
    
else:
    z = z2 * pow(10, -9)
    unit = "GΩ"
    
print("\n=========== More Info ===========\n")
print(f"Resistance = {z} {unit}\nTolerance = {x14}")
print(f"\nR = {z} {x14} {unit}")
print("\n=================================")
