#그냥 for문으로 자면 효율성 검사에서 실패한다. 
#정렬 후 다른 게 있으면 바로 return 하면 된다.
def solution(participant, completion):
    answer = ''
    participant.sort()
    completion.sort()
    beforeName = ''
    for i in range(len(participant)-1):
        if participant[i] != completion[i]: 
            return participant[i]
    return participant[-1]
