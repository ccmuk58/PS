import math
n = int(input())
ans = int(math.factorial(n)/(math.factorial(5)*math.factorial(n-5)))
print(ans)
