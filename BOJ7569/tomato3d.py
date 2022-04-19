#토마토 문제의 3차원 버전 
#상하좌우는 구현이 되어 있으니 위 아래만 추가 하면 됨
from collections import deque
def bfs(graph,M,N,H):
    queue = deque()
    dx = [0,0,1,-1,0,0]
    dy = [1,-1,0,0,0,0]
    dz = [0,0,0,0,1,-1] #차원 하나를 추가
    for h in range(H):
        for i in range(N):
            for j in range(M):
                if graph[h][i][j] == 1:
                    queue.append([h,i,j])
    day = 0
    while queue:
        # print(day)
        # for i in range(N):
        #     for j in range(M):
        #         print(graph[i][j],end='')
        #     print()
        
        n = len(queue)
        for _ in range(n):
            tomato = queue.popleft()
            # print(tomato)
            z = tomato[0]
            y = tomato[1]
            x = tomato[2]
            # print(y,x)
            for i in range(6):
                nz = z + dz[i]
                ny = y + dy[i]
                nx = x + dx[i]
                #범위 추가
                if nx >= 0 and nx < M and ny >=0 and ny < N and nz >= 0 and nz < H:
                    if graph[nz][ny][nx] == 0:
                        graph[nz][ny][nx] = 1
                        queue.append([nz,ny,nx])
        day += 1  
    for h in range(H):
        for i in range(N):
            for j in range(M):
                if(graph[h][i][j] == 0):
                    return -1
    return day -1


if __name__ == '__main__':
    M,N,H = input().split()
    M = int(M)
    N = int(N)
    H = int(H)
    graph = []
    for j in range(H):
        temp = []
        for i in range(N):
            temp.append(list(map(int,input().split())))
        graph.append(temp)
    
    print(bfs(graph,M,N,H))
