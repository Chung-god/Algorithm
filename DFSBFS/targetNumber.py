def solution(numbers, target):
    answer = 0
    tList = []
    for i in range(0,len(numbers)):
        if i == 0:
            tList.append(numbers[i])
            tList.append(-1*numbers[i])
            continue
        tList = tList*2
        for j in range(0,len(tList)):
            if j < len(tList)/2:
                tList[j] = tList[j] + numbers[i]
            else: 
                tList[j] = tList[j] - numbers[i]
    return tList.count(target)
  
  #다른 사람 풀이
def solution(numbers, target):
    if not numbers and target == 0 :
        return 1
    elif not numbers:
        return 0
    else:
        return solution(numbers[1:], target-numbers[0]) + solution(numbers[1:], target+numbers[0]) #재귀로 그냥 돌려버림
      

from itertools import product
def solution(numbers, target):
    l = [(x, -x) for x in numbers]
    s = list(map(sum, product(*l)))
    return s.count(target)
