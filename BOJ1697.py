import sys
from collections import deque

input_data = sys.stdin.readlines()

N,K = map(int,input_data[0].split())

def bfs(N,K):
	visited = []
	queue = deque([(N,0)]) #depth를 저장하기 위한 튜플
	while queue:
		node, depth = queue.popleft()

		if node == K: #target에 도착했으면 depth 반환
			return depth

		if node in visited: # 방문했으면 넘어가기
			continue
			
		visited.append(node)

		if node + 1 <= 100000:
			queue.append((node + 1, depth + 1))
		if node - 1 >= 0:
			queue.append((node - 1, depth + 1))
		if node * 2 <= 100000:
			queue.append((node * 2, depth + 1))

	return -1

print(bfs(N,K))

