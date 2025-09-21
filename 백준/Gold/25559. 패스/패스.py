n = int(input())
if n == 1:
	print(1)
elif n % 2 == 1:
	print(-1)
else:
	odd = n - 1
	even = 2
	print(n, end =" ")
	for i in range(n - 1):
		if i % 2 == 0:
			print(odd, end =" ")
			odd -= 2
		else:
			print(even, end =" ")
			even += 2