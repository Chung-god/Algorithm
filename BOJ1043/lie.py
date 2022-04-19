#백준1043, 거짓말 문제 
'''
1. 만약 진실을 아는 사람이 파티에 있으면 나머지 사람도 진실을 아는 사람이 됨 -> 큐에 삽입
2. 진실을 아는 사람이 없으면 큐에 다시 해당 파티에 참여한 사람을 삽입 
3. 진실을 아는 사람 큐가 빌 때까지 반복 
'''
import sys
from collections import deque

N,M = map(int,sys.stdin.readline().split())
tList = list(map(int,sys.stdin.readline().split())) 
tN = tList[0]
del tList[0]

queue = deque(tList)
pqueue = deque()

for i in range(M):
    temp = list(map(int,sys.stdin.readline().split()))
    del temp[0]
    pqueue.append(temp)
# print(pqueue)
# print(queue)

while queue:
    num = queue.popleft()
    # print(num)
    for _ in range(len(pqueue)):
        temp = pqueue.popleft()
        # print(temp)
        flag = 0
        for i in temp:
            if i == num:
                flag = 1
                temp.remove(i)
                for t in temp:
                    queue.append(t)
        if flag == 0 and len(temp) != 0:
            pqueue.append(temp)

# print(pqueue)
print(len(pqueue))

                
#고수분 코드
import sys
input = sys.stdin.readline

n, m = map(int, input().split())

k = map(int, input().split())
num = next(k) #하나 점프, 나중에 사용해보기
fact = list(k)
counted = set(fact) #set으로 바꿔서 차집합 구하기
linked = []
for _ in range(m):
    k = map(int, input().split())
    num = next(k)
    linked.append(set(k))
while fact and linked:
    i = fact.pop()
    new_linked = []
    for k in linked:
        if i in k: #리스트 안에 해당하는 값이 있으면 
            fact += list(k.difference(counted))
        else:
            new_linked.append(k)
    linked = new_linked

print(len(linked))
        

