def count_tree(lines, length):
    # 나무 길이가 length를 초과할 때 초과된 부분만 합산
    return sum(line - length for line in lines if line > length)


def solve(lines, N):
    low, high = 0, max(lines)  # 톱날 길이의 최소값과 최대값 설정
    answer = 0

    while low <= high:  # 이분 탐색 진행
        mid = (low + high) // 2  # 중간값 계산
        toN = count_tree(lines, mid)  # 현재 mid로 자른 나무 길이의 합 계산

        if toN >= N:  # 필요한 나무 길이를 만족하면
            answer = mid  # 정답 후보 갱신
            low = mid + 1  # 더 긴 톱날 길이로 탐색
        else:
            high = mid - 1  # 더 짧은 톱날 길이로 탐색
    return answer


import sys

# 콘솔 입력 처리
input_lines = sys.stdin.read().strip().split('\n')
K, N = map(int, input_lines[0].split())  # 나무의 개수와 필요한 나무 길이
lines = list(map(int, input_lines[1].strip().split()))  # 나무 길이 리스트

# 문제 해결 및 결과 출력
print(solve(lines, N))
