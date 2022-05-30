def solution(numbers, hand):
    ans = ""
    phone = {1:(0,0), 2:(0,1), 3:(0,2),
             4:(1,0), 5:(1,1), 6:(1,2),
             7:(2,0), 8:(2,1), 9:(2,2),
             '*':(3,0), 0:(3,1), '#':(3,2)} 
    lx,ly = phone['*']
    rx,ry = phone['#']
    
    for i in numbers:
        if i in [1,4,7]:
            ans += 'L'
            lx,ly = phone[i]
        elif( i in [3,6,9]):
            ans += 'R'
            rx,ry = phone[i]
        elif(i in [2,5,8,0]):
            tx,ty = phone[i]
            lterm = abs(tx-lx) + abs(ty-ly)
            rterm = abs(tx-rx) + abs(ty-ry)
 
            if(lterm > rterm):
                ans += 'R'
                rx,ry = phone[i]
            elif(lterm < rterm):
                ans += 'L'
                lx,ly = phone[i]
            elif(lterm == rterm):
                if hand =='right':
                    ans += 'R'
                    rx,ry = phone[i]
                else:
                    ans += 'L'
                    lx,ly = phone[i]

    return ans
