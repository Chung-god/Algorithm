def findPrime(arr):
    idx = 1 
    num = 0
    for i in arr:
        num = num + int(i) * idx
        idx = idx * 10
    # print(num)
    
    if num < 2: return False, num
    for i in range(2, num):
        if num % i == 0 : return False, num
    return True, num
        

from itertools import permutations
def solution(numbers):
    answer = 0
    numList = []
    permuList = []
    result = []
    for i in numbers:
        numList.append(i)
    for idx,n in enumerate(numList):
        permuList.append(list(permutations(numList,idx+1)))
    for idx in range(len(permuList)):
        for num in permuList[idx]:
            a,b = findPrime(num)
            if a == True: 
                if b not in result:
                    result.append(b)
                    answer +=1
            
    return answer
