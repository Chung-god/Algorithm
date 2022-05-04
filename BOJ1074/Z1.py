#처음에는 재귀 함수로 풀었으나 메모리 초과가 났다.
#map이 없어도 되는 구조여서 map을 없앴고 이 후 시간 초과가 났다.
#즉 들어갈 범위를 구한 부분만 재귀를 들어가야 했다.
#그래서 z가 행의 길이에 따라서 인덱스가 변하는 값을 찾아서 계산했다. 
#간단한 건데 unboundlocal error 등이 나서 시간이 오래걸렸다.
import sys

n,r,c = map(int,sys.stdin.readline().split())
n = pow(2,n)

def find2(num):
    ans = 0
    while num:
        num = int(num/2)
        ans+=1
    return ans-1


def Z(N,x,y,index,a,b):
    #변이 2일 때는 가장 작은 z이기 때문에 계산해서 풀기
    if(N == 2):
        if(x == a and y == b): print(index)
        if(x == a and (y+1)== b): print(index+1)
        if((x+1) == a and y == b): print(index+2)
        if((x+1) == a and (y+1) == b): print(index+3)
    else:
        newN = int(N/2)
        temp = pow(4, find2(newN)) 
        #갱신되는 자리에서 newN을 더해나가야 위치를 찾을 수 있음
        if(a < x + newN and b <  y + newN):
            Z(newN,x,y,index,a,b)
        elif(a < x + newN and b >= y + newN):
            index +=  temp
            Z(newN,x,y + newN,index,a,b)
        elif(a >= x + newN and b <  y + newN):
            index += temp*2
            Z(newN,x + newN,y,index,a,b)
        elif(a >= x + newN and b >=  y + newN):
            index += temp*2 + temp
            Z(newN,x + newN,y+ newN,index,a,b)
  
Z(n,0,0,0,r,c)

    
        
        
