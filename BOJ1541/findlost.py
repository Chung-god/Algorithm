#백준 잃어버린 괄호 찾기 문제 1541 문제
#문자열을 파싱
#마이너스 뒤를 다 빼야한다는 아이디어 -> 식의 최소값
#위 조건을 찾지 못하면 문제를 풀 수 없음 
#런타임에러 : -로 시작하는 숫자 앞에는 num을 넣으면 안됨, 인덱스가 이상해지면서 str가 +,-를 수행하며 에러가 남 .

input = input()
arr = []

num = 0
#마이너스일 경우 계속 빼야하기 때문에 flag를 True로 한다. 
if(input[0]=='-'): 
    flag = True
    check = 1
elif(input[0]=='+'): 
    flag = False
    check = 1
else: 
    flag = False
    check = 0
    
for i in range(len(input)):
    if(input[i] == '-' or input[i]=='+'):
        if(i!=0) : #처음이 마이너스임을 고려하지 않을 경우 0이 들어가서 런타임에러가 발생하게 됨 
            arr.append(num)
        arr.append(input[i])
        num = 0
    else:
        num *= 10
        num += int(input[i])
arr.append(num)
# print(arr)

index = 0
ans = 0 

while(index < len(arr)):
    if(index % 2 == check): #숫자
        if(flag == False):
            ans += arr[index]
        else:
            ans -= arr[index]
    else:#기호
        if(arr[index]=='-' and flag==False):
            flag = not flag
    index +=1

print(ans)
