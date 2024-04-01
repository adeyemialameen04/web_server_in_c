import math

a = int(input("A variable: "))
b = int(input("B variable: "))
c = int(input("C variable: "))
result = 0
x1 = 0
x2 = 0

inside_sqrt = (b**2 - 4*a*c)

if inside_sqrt >= 0:
	result = math.sqrt(inside_sqrt)
	down_res = 2 * a
	x1 = (-b + result) / down_res
	x2 = (-b - result) / down_res
else:
	print("Negative value")

print(f"({x1}, {x2})")
