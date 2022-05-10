n = int(input())
graph = []

for _ in range(n):
    graph.append(list(map(int,input().split())))

#플로이드 와샬 : 반복문 3개, 플로이드 와샬 사용
#k 거쳐가는 노드
for k in range(n):
    #i 시작노드
    for i in range(n):
        #j 도착노드
        for j in range(n):
            if(graph[i][k] == 1 and graph[k][j] == 1):
                graph[i][j] = 1


for i in graph:     
    for j in i:
        print(j,end=' ')
    print()
