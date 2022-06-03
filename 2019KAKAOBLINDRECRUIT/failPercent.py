#실패율 = 스테이지에 도달했으나 아직 클리어하지 못한 플레이어의 수 / 스테이지에 도달한 플레이어의 수 
def solution(N, stages):
    failPlayer = len(stages)
    failArr = {}
    for i in range(1,N+1):
        n = 0
        for stage in stages:
            if stage == i:
                n = n + 1
        if n == 0: #0을 나눌 때는 반드시 런타임 에러 고려해야 함 
            failArr[i] = 0
            continue
        failArr[i] = n/failPlayer
        failPlayer -= n
    arr = sorted(failArr.items(),key=lambda x : x[1], reverse=True)
    answer = []
    for i in range(len(arr)):
        answer.append(arr[i][0])
            
        
    return answer
