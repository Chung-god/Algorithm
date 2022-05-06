import sys
input = sys.stdin.readline
r,c,t = map(int,input().split())
graph = []
airMachine = []

for i in range(r):
    graph.append(list(map(int,input().split())))
    if -1 in graph[i]:
        airMachine.append((i,graph[i].index(-1)))
ax1 = airMachine[0][0]
ay1 = airMachine[0][1]
ax2 = airMachine[1][0]
ay2 = airMachine[1][1]

dx = [0,0,1,-1]
dy = [1,-1,0,0]

def diffustion():
    newGraph = []
    for i in graph:
        newGraph.append(i.copy())
    #이중리스트 복사, 이중리스트는 copy를 그대로 쓰면 깊은 복사가 됨 


    for x in range(r):
        for y in range(c):
            if(graph[x][y]==0 or graph[x][y]==-1): continue
            dust = int(graph[x][y]/5) #확산되는 먼지의 양
            for k in range(4):
                nx = x + dx[k]
                ny = y + dy[k]
                if(nx<0 or ny<0 or nx>=r or ny>=c): continue
                if(graph[nx][ny] == -1): continue
                newGraph[nx][ny] += dust
                newGraph[x][y] -= dust

    for i in range(r):
        graph[i] = newGraph[i].copy()



def purity():
    for x in range(ax1-1,-1, -1):
        # print(x,',',ay1)
        if graph[x+1][ay1] == -1: 
            graph[x][ay1] == 0
        else: 
            graph[x+1][ay1] = graph[x][ay1]
            graph[x][ay1] = 0
    for y in range(1,c):
        graph[0][y-1] = graph[0][y]
        graph[0][y] = 0
    for x in range(1,ax1+1):
        graph[x-1][c-1] = graph[x][c-1]
        graph[x][c-1] = 0
    for y in range(c-2,0,-1):
        graph[ax1][y+1] = graph[ax1][y]
        graph[ax1][y] = 0
    # ax2,ay2
    for x in range(ax2+1,r):
        if(graph[x-1][0]==-1):
            graph[x][0] = 0
        else:
            graph[x-1][0] = graph[x][0]
            graph[x][0] = 0
    for y in range(1,c):
        graph[r-1][y-1] = graph[r-1][y]
        graph[r-1][y] = 0

    for x in range(r-2,ax2-1,-1):
        graph[x+1][c-1] = graph[x][c-1]
        graph[x][c-1] = 0
    for y in range(c-2,0,-1):
        graph[ax2][y+1] = graph[ax2][y]
        graph[ax2][y] = 0   

for _ in range(t):
    diffustion()
    purity()
    
result = 0
for x in range(r):
    for y in range(c):
        result += graph[x][y]
print(result+2)
    


        
        
        
    
