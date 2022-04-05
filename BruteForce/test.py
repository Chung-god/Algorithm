def solution(answers):
    answer = []
    supoja1 = [1,2,3,4,5]
    supoja2 = [2,1,2,3,2,4,2,5]
    supoja3 = [3,3,1,1,2,2,4,4,5,5]
    ans1 = 0
    ans2 = 0
    ans3 = 0
    for i in range(0,len(answers)):
        if answers[i] == supoja1[i%len(supoja1)]:
            ans1 += 1
        if answers[i] == supoja2[i%len(supoja2)]:
            ans2 += 1
        if answers[i] == supoja3[i%len(supoja3)]:
            ans3 += 1
    #print(ans1,ans2,ans3)
    if ans1 > ans2:
        if ans1 > ans3:
            answer.append(1)
        elif ans1 < ans3:
            answer.append(3)
        elif ans1 == ans3:
            answer.append(1)
            answer.append(3)
    elif ans1 == ans2:
        if ans1 > ans3:
            answer.append(1)
            answer.append(2)
        elif ans1 < ans3:
            answer.append(3)
        elif ans1 == ans3:
            answer.append(1)
            answer.append(2)
            answer.append(3)
    elif ans1 < ans2: 
        if ans2 > ans3:
            answer.append(2)
        elif ans2 < ans3:
            answer.append(3)
        elif ans2 == ans3:
            answer.append(2)
            answer.append(3)
    answer.sort()
    return answer

def solution(answers):
    pattern1 = [1,2,3,4,5]
    pattern2 = [2,1,2,3,2,4,2,5]
    pattern3 = [3,3,1,1,2,2,4,4,5,5]
    score = [0, 0, 0]
    result = []

    for idx, answer in enumerate(answers):
        if answer == pattern1[idx%len(pattern1)]:
            score[0] += 1
        if answer == pattern2[idx%len(pattern2)]:
            score[1] += 1
        if answer == pattern3[idx%len(pattern3)]:
            score[2] += 1
    #배열 안에 넣어서 최고값하고 계산 
    for idx, s in enumerate(score):
        if s == max(score):
            result.append(idx+1)

    return result
