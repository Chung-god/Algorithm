def solution(lottos, win_nums):
    #0의 개수, 0이 아닌 것 중 맞는 개수 
    #최저는 0이 아닌 게수 순위 
    #최고는 최저 + 0의 개수 
    zero = 0
    right = 0
    minRank = 0
    maxRank = 0
    for lotto in lottos:
        if lotto == 0: 
            zero += 1
            continue
        if lotto in win_nums:
            right += 1
            
    if right == 6:
        minRank = 1
    elif right == 5:
        minRank = 2
    elif right == 4:
        minRank = 3
    elif right == 3:
        minRank = 4
    elif right == 2:
        minRank = 5
    elif right == 1:
        minRank = 6
    elif right == 0:
        minRank = 6
        if zero != 0: #0이 없는데서 올래서 처음에 틀림
            maxRank = minRank - zero +1
            return [maxRank, minRank]
    maxRank = minRank - zero
    return [maxRank, minRank]
