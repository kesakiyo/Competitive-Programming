def findMax(A):
	if len(A) == 2:
		return 0
	ret = 0
	for i in range(1, len(A) - 1):
		ret = max(ret, findMax(A[:i] + A[i + 1:]) + A[i - 1] * A[i + 1])
	return ret

n = int(input())
A = [int(val) for val in input().split()]
print(findMax(A))
