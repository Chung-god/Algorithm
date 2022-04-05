def solution(brown, yellow):
    if yellow == 1: return [3, 3]
    for sero in range(1,int(yellow/2+1)):
        if yellow % sero != 0: continue 
        garo = yellow/sero
        if garo + sero == (brown - 4)/2:
            return [garo + 2, sero + 2]
