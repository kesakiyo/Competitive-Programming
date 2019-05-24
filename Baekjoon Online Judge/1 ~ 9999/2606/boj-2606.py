n = int(input())
m = int(input())
A = [[False] * n for _ in range(n)]
V = [False] * n

def dfs(here):
	V[here] = True
	for there in range(n):
		if A[here][there] and not V[there]:
			dfs(there)

for _ in range(m):
	u, v = map(int, input().split())
	A[u - 1][v - 1] = A[v - 1][u - 1] = True

dfs(0)
ans = 0
for i in range(n):
	if V[i]:
		ans += 1

print(ans - 1)
