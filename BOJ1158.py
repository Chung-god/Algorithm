N,term = input().split()
N = int(N)
term = int(term)

myList =[]
for i in range(N):
    myList.append(i)
ansList=[]
i = term -1
while len(myList)!=0 :
    ansList.append(myList[i]+1)
    myList.pop(i)
    i += term -1;
    while i >= len(myList):
        if len(myList) ==0: break
        i -= len(myList)

print("<", end='')
for i in ansList:
    if i == ansList[-1]:
        print(i, end = '')
    else:
        print("%s, " %(i), end='')
print(">")