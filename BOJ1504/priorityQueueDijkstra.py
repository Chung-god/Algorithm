import sys
import heapq
input = sys.stdin.readline
n, m = map(int, input().split())
INF = int(1e9)
distance = [INF] * (n+1)
graph = [[] for _ in range(n+1)]
for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))
    graph[b].append((a, c))
v1,v2 = map(int,input().split())

def dijkstra(start, end):
    distance = [INF] * (n+1)
    q = []
    heapq.heappush(q, (0, start))  # 시작노드 정보 우선순위 큐에 삽입
    distance[start] = 0            # 시작노드->시작노드 거리 기록
    while q:
        dist, node = heapq.heappop(q)
        # 큐에서 뽑아낸 거리가 이미 갱신된 거리보다 클 경우(=방문한 셈) 무시
        if distance[node] < dist:
            continue
        # 큐에서 뽑아낸 노드와 연결된 인접노드들 탐색
        for next in graph[node]:
            cost = distance[node] + next[1]   # 시작->node거리 + node->node의인접노드 거리
            if cost < distance[next[0]]:      # cost < 시작->node의인접노드 거리
                distance[next[0]] = cost
                heapq.heappush(q, (cost, next[0]))
    return distance[end]


result1 = 0
result2 = 0
#1 -> v1 -> v2 -> N
# print(dijkstra(1,v1),dijkstra(v1,v2),dijkstra(v2,N))
result1 = dijkstra(1,v1) + dijkstra(v1,v2) + dijkstra(v2,n)
#1 -> v2 -> v1 -> N
# print(dijkstra(1,v2))
result2 = dijkstra(1,v2) + dijkstra(v2,v1) + dijkstra(v1,n)

# print(result1,result2)
ans = min(result1,result2)
if ans >= INF:
    print(-1)
else:
    print(ans)
