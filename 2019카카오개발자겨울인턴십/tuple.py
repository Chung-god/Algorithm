#튜플

def solution(s):
    answer = []
    arr = []
    tempArr = []
    n = 0
    for i in range(len(s)-1):
        if s[i] == '{':
            continue
        if s[i] == '}':
            tempArr.append(n)
            n = 0
            arr.append(tempArr)
            tempArr = []
            continue
        if s[i] == ',':
            if s[i+1] == '{' : continue
            tempArr.append(n)
            n = 0
            continue
        else:
            n = n *10 + int(s[i])

    arr.sort(key=len)   
    # print(arr)
    for i in arr:
        for j in i:
            # print(j)
            if j not in answer:
                answer.append(j)
    # print(answer)
        
    return answer
