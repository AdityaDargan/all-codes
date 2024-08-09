L = [1, 3, -1, 4, -2, 5, 3]
try:
	n=10
	for i in range(n):
	   if L[i] < 0:
	      L[i] = 0
except IndexError:
	for i in range(n - len(L)):
	   L.append(0)

finally:
	print(L)
