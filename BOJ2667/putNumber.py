n = int(input())
graph = []
for _ in range(n):
    graph.append(list(map(int,input())))

# n= 7
# graph = [[0, 1, 1, 0, 1, 0, 0], [0, 1, 1, 0, 1, 0, 1], [1, 1, 1, 0, 1, 0, 1], [0, 0, 0, 0, 1, 1, 1], [0, 1, 0, 0, 0, 0, 0], [0, 1, 1, 1, 1, 1, 0], [0, 1, 1, 1, 0, 0, 0]]


def dfs(x,y):
    #범위 벗어나면 종료
    if x <= -1 or y <= -1 or x >= n or y >= n:
        return False
    #방문하지 않았다면 네 방향 탐색
    if graph[x][y] == 1:
        graph[x][y] = 2
        global count
        count +=1
        dfs(x + 1, y)
        dfs(x - 1, y)
        dfs(x, y + 1)
        dfs(x, y - 1)
        return True
    return False

result = 0
count = 0
depthList = []
for i in range(n):
    for j in range(n):
        temp = []
        count = 0
        if dfs(i,j) == True:
            result += 1
            depthList.append(count)

print(result)
depthList.sort()
for d in depthList:
    print(d)
