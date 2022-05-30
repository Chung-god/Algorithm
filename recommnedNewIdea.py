def solution(new_id):
    new_id = new_id.lower()
    for i in new_id:
        if 'a' <= i and i <= 'z':
            continue
        if '0' <= i and i <= '9':
            continue
        if i in ['-','_','.']:
            continue
        new_id = new_id.replace(i,'')
    while True:
        if '..' in new_id:
            new_id = new_id.replace('..','.')
        else:
            break

    arr =list(new_id) 
    if arr[0] == '.': 
        del arr[0]
    
    if len(arr) > 0:
        if arr[len(arr)-1]=='.':
            del arr[len(arr)-1]
    else:
        arr.append('a')
    while len(arr) >= 16:
        del arr[len(arr)-1]
    
    if arr[0] == '.': 
        del arr[0]
    
    if len(arr) > 0:
        if arr[len(arr)-1]=='.':
            del arr[len(arr)-1]
    
    if len(arr) <= 2:
        while len(arr) < 3:
            arr.append(arr[len(arr)-1])
    new_id =''.join(arr)
    return new_id
