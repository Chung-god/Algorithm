#순열은 permutations
#조합은 combinations
#from itertools
from itertools import permutations
import sys

N,M = map(int,sys.stdin.readline().split())
k = list(map(int,sys.stdin.readline().split()))
k.sort()
for i in list(permutations(k,M)):
    for j in range(M):
        sys.stdout.write(str(i[j]) + ' ')
    sys.stdout.write('\n') #print와 다르게 개행없음 
