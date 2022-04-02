def solution(priorities, location):
    answer = 1
    numList = [x for x in range(0,len(priorities))]
    while True:
        if(len(numList) == 1):
            return answer
        num = numList.pop(0)
        numPrior = priorities.pop(0)
        flag = 0
        print('num:', numList, 'prior ', priorities)
        for i in range(0,len(priorities)):
            if(numPrior < priorities[i]): #중요도가 크게 있음
                numList.append(num)
                priorities.append(numPrior)
                flag = 1
                break
        if flag == 0:
            print(num,numPrior,answer)
            if num == location:
                return answer
            else:
                answer = answer + 1
                
#다른 사람 풀이

def solution(priorities, location):
    queue =  [(i,p) for i,p in enumerate(priorities)] #enumerate 는 딕셔너리 형태로 맵핑해줌
    answer = 0
    while True:
        cur = queue.pop(0)
        if any(cur[1] < q[1] for q in queue): #any를 통해 if문을 간결하게 풀 수 있음
            queue.append(cur)
        else:
            answer += 1
            if cur[0] == location:
                return answer
