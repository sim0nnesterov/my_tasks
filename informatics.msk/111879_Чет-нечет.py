n = int(input())

l = 0
r = n * n
while r - l > 1 :
	mid = (l + r) // 2
	if mid * (mid + 1) // 2 < n :
	    l = mid
    else : 
		r = mid
n -= l * (l + 1) // 2 + 1
if l == 0 :
	print(1)
else :
	print ((l + 1) * l // 2 + 1 + (l - 1) * (l) // 2 + n * 2)
