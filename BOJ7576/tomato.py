#토마토
from collections import deque
def bfs(graph,M,N):
    queue = deque()
    #방향 리스트 선언
    dx = [0,0,1,-1]
    dy = [1,-1,0,0]
    #익은 토마토 큐에 삽입 
    for i in range(N):
        for j in range(M):
            if graph[i][j] == 1:
                queue.append([i,j])
    day = 0
    #큐가 빌때까지 반복
    while queue:
        # print(day)
        # for i in range(N):
        #     for j in range(M):
        #         print(graph[i][j],end='')
        #     print()
        
        n = len(queue)
        #한 타임에 큐가 끝나면 날짜 더하기
        for _ in range(n):
            tomato = queue.popleft()
            # print(tomato)
            y = tomato[0]
            x = tomato[1]
            # print(y,x)
            for i in range(4):
                ny = y + dy[i]
                nx = x + dx[i]
                #범위와 방향을 탐색하며 익힐 토마토 찾기
                if nx >= 0 and nx < M and ny >=0 and ny < N:
                    if graph[ny][nx] == 0:
                        #토마토를 익히고 큐에 삽입
                        graph[ny][nx] = 1
                        queue.append([ny,nx])
        day += 1   
    for i in range(N):
        for j in range(M):
          #안 익은 토마토가 있을 경우 -1 출력
            if(graph[i][j] == 0):
                return -1
    return day -1


if __name__ == '__main__':
    M,N = input().split()
    M = int(M)
    N = int(N)
    graph = []
    for i in range(N):
        graph.append(list(map(int,input().split())))
    # M = 6
    # N = 4
    # graph = [[0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 1]]
    print(bfs(graph,M,N))
