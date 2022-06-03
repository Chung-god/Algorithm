#2019 KAKAO BLIND RECRUITMENT
#오픈채팅방

def solution(record):
    answer = []
    userDict = {}
    #userDict 업데이트
    for code in record:
        temp = code.split(' ')
        if temp[0] == 'Enter' or temp[0] == 'Change':
            userDict[temp[1]] = temp[2]
    
    for code in record:
        temp = code.split(' ')
        name = userDict[temp[1]]
        if temp[0] == 'Enter':
            answer.append(name + '님이 들어왔습니다.')
        elif temp[0] =='Leave':
            answer.append(name + '님이 나갔습니다.')
    #result 출력 
    
    return answer
