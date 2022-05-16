import sys
N,M = map(int,input().split())
arr = {} #딕셔너리로 해야 리스트 쓰면 in 때문에 for 문이 되니깐 시간 복잡도 초과
for i in range(N):
    t = sys.stdin.readline().rstrip() #개행문자 빼기
    arr[t] = i

dbj = []
for _ in range(M):
    temp = sys.stdin.readline().rstrip()
    if temp in arr:
        dbj.append(temp)
dbj.sort()
print(len(dbj))
for i in range(len(dbj)):
    print(dbj[i])
    
