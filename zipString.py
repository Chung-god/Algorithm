def solution(s):
    answer =0
    slen = len(s)
    # print('len :' ,slen)
    maxlen = slen
    for i in range(1,int(len(s)/2)+1):
        arr = []
        first = 0
        last = i
        while last <= slen:
            arr.append(s[first:last])
            first += i
            last += i
        arr.append(s[first:slen])
        # print(arr)
        banbok = 1
        string = ""
        i = 0
        flag = False
        for i in range(0, len(arr)-1):
            if arr[i] == arr[i+1]:
                banbok += 1
                flag = True
            else:
                if banbok != 1:
                    string = string + str(banbok) + arr[i]
                    banbok = 1
                else: 
                    string = string  + arr[i]
                flag = False
        
        if flag == True:
            if banbok != 1:
                string = string + str(banbok) + arr[len(arr)-1]
        else:
            string = string  + arr[len(arr)-1]
            
        if maxlen > len(string):
            maxlen = len(string)
        # print(string)
        
    return maxlen
