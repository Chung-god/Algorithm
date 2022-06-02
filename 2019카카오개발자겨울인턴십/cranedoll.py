#크레인 인형뽑기 게임
def solution(board, moves):
    answer = 0
    box = []
    for m in moves:
        for i in range(len(board)):
            if board[i][m-1] != 0:
                box.append(board[i][m-1])
                board[i][m-1] = 0
                break
    
    while True:
        Flag = False
        for i in range(1,len(box)):
            if box[i-1] == box[i]:
                del box[i]
                del box[i-1]
                answer += 2
                Flag = True
                break
        if Flag == False: break
            
                
    return answer
