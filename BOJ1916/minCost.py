import sys
input = sys.stdin.readline
INF = int(1e9)

N = int(input())
M = int(input())
graph = [[] for _ in range(N+1)]
dist = [INF] * (N+1)
visited = [False] * (N+1)
for _ in range(M):
    a,b,c = map(int,input().split())
    graph[a].append((b,c))
# print(graph)
start,end = map(int,input().split())

#방문하지 않은 노드이면서 시작도느와 최단거리인 노드 반환
def getSmallestNode():
    minValue = INF
    ans = 0
    for i in range(1,N+1):
        if not visited[i] and dist[i] < minValue:
            minValue = dist[i]
            ans = i
    return ans

def dijkstra(start):
    dist[start] = 0 #시작노드 처리
    visited[start] = True #방문처리
    
    #시작노드 인접한 노드의 최단거리 계산을 위해 dist 입력
    for i in graph[start]:
        if dist[i[0]] > i[1]: #첫 시도에서 틀린 이유 두 노드 사이에 더 작은 값이 있을 수 있음 
            dist[i[0]] = i[1]
        # print(dist)
        
    #시작노드 제외한 노드들 처리
    for _ in range(N-1):
        now = getSmallestNode() #시작노드에서 방문하지 않은 가장 작은 값을 선택
        visited[now] = True #해당 노드 방문처리
        # 해당 노드의 인접한 노드들 간의 거리 계산
        for next in graph[now]:
            cost = dist[now] + next[1]
            if cost < dist[next[0]]:
                dist[next[0]] = cost

dijkstra(start)
print(dist[end])
            
