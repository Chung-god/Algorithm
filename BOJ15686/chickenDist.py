'''
BOJ15686 치킨거리구하기 문제
브루트포스로 구함 
1. 집위치, 치킨집 거리 구하기
2. 모든 집의 모든 치킨집 간에 거리 구하기
3. M개의 조합 구하기
4. 해당 조합에 해당되는 치킨거리 구하기
5. 도시의 치킨거리 최솟값 출력 
'''
from itertools import combinations 
N,M = map(int,input().split())
chickMap = [[0]*(N+1)]

for i in range(N):
    temp = [0] + list(map(int,input().split()))
    chickMap.append(temp)
    
chicDistList = [] 
houseList = []
chickList = []

for i in range(N+1):
    for j in range(N+1):
        if(chickMap[i][j] == 1):
            houseList.append([i,j])
        elif(chickMap[i][j] == 2):
            chickList.append([i,j])
        
for i in range(len(houseList)):
    temp = []
    for j in range(len(chickList)):
        #집과 치킨집 사이 거리 구하기
        dist = abs(houseList[i][0] - chickList[j][0]) + abs(houseList[i][1] - chickList[j][1]) 
        temp.append(dist)
    chicDistList.append(temp)
    
# print(chicDistList)
cbn = [x for x in range(len(chickList))]
cbn = list(combinations(cbn,M)) #조합으로 M개의 치킨집 리스트 구하기
# print(list(combinations(t,M)))

answer = [0]*len(cbn)
# print(answer)
for i in range(len(cbn)):
    for j in chicDistList:
        small = 1000
        for k in range(len(j)): 
            if k in cbn[i]: #조합에 해당되는 집끼리의 치킨 거리를 구함
                if j[k] < small:
                    small = j[k]
        answer[i] += small #해당 조합의 도시의 치킨거리를 구함

print(min(answer)) #가장 작은 치킨거리를 출력 
            
