n = int(input())
A = []; B = []; C = []; D =[]
for _ in range(n):
	a, b, c, d = map(int, input().split())
	A.append(a); B.append(b); C.append(c); D.append(d)

AB = []
for a in A:
	for b in B:
		AB.append(a + b)
AB.sort()

CD = []
for c in C:
	for d in D:
		CD.append(c + d)
CD.sort()

result = 0
lp = 0
rp = n**2 - 1

while(lp < len(AB) and rp >= 0):
	if(AB[lp] + CD[rp] == 0):
		ABsame = 1
		CDsame = 1
		while(lp < len(AB) - 1 and AB[lp] == AB[lp+1]):
			ABsame += 1
			lp += 1
		while(rp > 0 and CD[rp] == CD[rp-1]):
			CDsame += 1
			rp -= 1
		result += ABsame * CDsame
		lp += 1
		rp -= 1
	elif(AB[lp] + CD[rp] > 0):
		rp -= 1
	else:
		lp += 1
        
print(result)