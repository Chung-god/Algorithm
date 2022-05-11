import sys

n = int(input()) #입력 방식 input 느림

#집합 사용, 리스트 쓰면 메모리 초과날 수 있음
arr = set()
for _ in range(n):
    opList = sys.stdin.readline().strip().split() #공백이 들어가기 때문에 strip()으로 개행 빼주기 
    op1 = opList[0]
    #조금이라도 효율적으로 if 문 작성
    if(len(opList) == 2):
        op2 = int(opList[1])
        if(op1=='add'):
            arr.add(op2)
        elif(op1=='remove'):
            arr.discard(op2) 
            #remove 사용 시 요소가 없으면 런타임 에러 남 
        elif(op1=='check'):
            if op2 in arr:
                print(1)
            else:
                print(0)
        elif(op1=='toggle'):
            if op2 in arr: 
                arr.discard(op2)
            else:
                arr.add(op2)
    elif(op1=='all'):
        arr = {x for x in range(1,21)}
    elif(op1=='empty'):
        arr.clear()
 

