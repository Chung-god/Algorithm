array = [1, 5, 7, 8, 2, 9, 10, 3, 6, 4]

index = 0
temp = 0

for i in range(len(array) - 1):
    min_idx = i
    for j in range(i + 1, len(array)):
        if array[min_idx] > array[j]:
            min_idx = j
    array[i], array[min_idx] = array[min_idx], array[i]

for i in array:
    print(i, end=' ')


