n,m = map(int,input().split())
graph = []
visited = [[False]*m for _ in range(n)]
for _ in range(n):
    graph.append(list(map(int,input().split())))


dx = [0,0,1,-1]
dy = [1,-1,0,0]

#외부공기의 흐름
def dfs(graph,x,y):
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if(nx < 0 or nx >= n or ny < 0 or ny >= m): continue   
        if(graph[nx][ny]==0):     
            graph[nx][ny]= 2    
            dfs(graph,nx,ny)

            #외부의 접촉된 치즈를 녹임
def checkOut():
    for x in range(n):
        for y in range(m):
            if(graph[x][y]==1): #치즈일때
                out = 0
                for i in range(4):
                    nx = x + dx[i]
                    ny = y + dy[i]
                    if(nx < 0 or nx >= n or ny < 0 or ny >= m): continue   
                    if(graph[nx][ny]==2): out+=1
                if(out >= 2): 
                    graph[x][y] = 0
#치즈가 있는지 확인
def chesses():
    for x in range(n):
        for y in range(m):
            if(graph[x][y] != 2): return False
    return True

dfs(graph,0,0)
checkOut()
if(chesses()==True): 
    print(1)
else:
    time = 0
    while(chesses()!=True):
        for x in range(n):
            for y in range(m):
                if(graph[x][y] == 2): 
                    dfs(graph,x,y)
        checkOut()
        time += 1
    print(time)
