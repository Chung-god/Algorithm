#백준 12865 배낭문제
#다이나믹 프로그래밍
n,k = map(int,input().split())

#물건의 무게와 가치를 넣을 리스트
item = [[0,0]]
#물건의 개수와 한계 무계까지의 이중리스트
d = [[0]*(k+1) for _ in range(n+1)]

for i in range(n):
    item.append(list(map(int,input().split())))

for i in range(1,n+1):
    for j in range(1,k+1):
        w = item[i][0] #무게
        v = item[i][1] #가치
        
        if j < w:
            #최대무게가 넘는다면 이전 값 삽입 
            d[i][j] = d[i-1][j]
        else:
            #아무것도 안 넣은 값과 무게를 빼고 가치를 더한 거 비교해서 더 큰거
            d[i][j] = max(d[i-1][j], d[i-1][j-w]+v) 

print(d[n][k])
