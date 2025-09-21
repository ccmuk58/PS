from math import *
h = int(input())
n = 2
while True:
	if h < 2 ** (2 ** n):
		print(-1)
		exit(0)
	if h == 2 ** (2 ** n):
		break
	n += 1

cnt = 0
delta = 0
temp = n
while temp > 0:
	if temp % 2 == 1:
		cnt += 1 + delta
	delta += 1
	temp //= 2

print(1 + n, 1 + cnt)

for i in range(n):
	print(1, end=" ")
print()

cnt = 2
delta = 0
temp = n
while temp > 0:
	if temp % 2 == 1:
		print(1, end=" ")
		for i in range(delta):
			print(cnt, end=" ")
		cnt += 1 + delta
	delta += 1
	temp //= 2