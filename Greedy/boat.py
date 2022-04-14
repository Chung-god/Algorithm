#효율성을 위해서 파이썬 라이브러리 (삭제, 삽입)을 사용하기 보단 인덱싱을 한다는 생각을 가질 것
def solution(people, limit):
    people.sort()
    answer = 0
    left = 0
    right = len(people) - 1
    while left < right:
        if people[left] + people[right] <= limit:
            left += 1
            right -= 1
        else:
            right -= 1
        answer += 1
    
    if right == left: return answer + 1
    return answer 
    # while people:
    #     last = len(people)-1       
    #     if people[0] + people[last] > limit:
    #         del people[last]
    #         answer += 1
    #     else:
    #         del people[last]
    #         if len(people) == 0: return answer + 1
    #         del people[0]
    #         answer += 1
    # return answer
