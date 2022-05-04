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

    
        
        
