from collections import deque
n,m,v = map(int,input().split())
# n = 5
# m = 5
# v = 1

graph = [[]]
for i in range(m):
    graph.append(list(map(int, input().split())))

# graph = [[],[1,2],[1,3],[2,4],[3,4],[4,5]]
def dfs(graph,v,visited):
    visited[v] = True
    print(v ,end=' ')
    tempList = []
    for i in range(1, len(graph)):
        if graph[i][0] != v and graph[i][1] == v:
            connectNode = graph[i][0]
        elif graph[i][1] != v and graph[i][0] == v:
            connectNode = graph[i][1]
        else:
            continue
        if not visited[connectNode] and tempList.count(connectNode) == 0:
            tempList.append(connectNode)
    tempList.sort()
    for i in tempList:
        if not visited[i]:
            dfs(graph,i,visited)

def bfs(graph,start,visited):
    queue = deque([start])
    visited[start] = True
    while queue:
        v = queue.popleft()
        print(v, end=' ')
        tempList = []
        for i in range(1,len(graph)):
            if graph[i][0] != v and graph[i][1] == v:
                connectNode = graph[i][0]
            elif graph[i][1] != v and graph[i][0] == v:
                connectNode = graph[i][1]
            else:
                continue
            if not visited[connectNode] and tempList.count(connectNode) == 0:
                tempList.append(connectNode)
        tempList.sort()
        # print(tempList)
        for i in tempList:
            if queue.count(i) == 0:
                queue.append(i)
                visited[i] = True


# visited = [False] * (n+1)
dfs(graph,v,[False] * (n+1))
print()
bfs(graph,v,[False] * (n+1))
