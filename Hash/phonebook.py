def solution(phone_book):
    phone_book.sort()
    '''
    정렬을 하게 되면 아래와 같이 i번째와 i+1번째만 비교하면 됨.
    ['119', '1195524421', '97674223']
    ['12', '123', '1235', '567', '88']
    '''
    print(phone_book) 
    for i in range(len(phone_book)-1):
        if phone_book[i] == phone_book[i+1][0:len(phone_book[i])]:
            return False
        
    # 효율성 실패 
    # phone_book.sort(key=len)
    # for i in range(len(phone_book)-1):
    #     for j in range(i+1,len(phone_book)):
    #         if phone_book[i] == phone_book[j][0:len(phone_book[i])]:
    #             return False
    # return True
            
    # 효율성 더 큰 실패
    # answer = True
    # phone_book.sort()
    # flag = True
    # for i in range(len(phone_book)):
    #     for j in range(i+1,len(phone_book)):
    #         for k in range(len(phone_book[i])):
    #             if phone_book[i][k] != phone_book[j][k]:
    #                 flag = False
    #                 break
    #         if flag == True: return False
    return True
