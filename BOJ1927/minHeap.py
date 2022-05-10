import heapq
import sys

n = int(sys.stdin.readline()) #입력 방식 input 느림

heap = []
for i in range(n):
    m = int(sys.stdin.readline())
    if m == 0:
        try:
            minheap = heapq.heappop(heap)
            print(minheap)
        except:
            print(0)
    else:
        heapq.heappush(heap,m)
