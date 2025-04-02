import sys
from itertools import combinations
from bisect import bisect_right

input = sys.stdin.read
data = input().split()

N = int(data[0])
C = int(data[1])
weights = list(map(int, data[2:]))

# 물건을 두 그룹으로 나누기
half = N // 2
left_weights = weights[:half]
right_weights = weights[half:]

# 부분합 계산 함수
def get_subsums(weights):
    subsums = []
    for i in range(len(weights) + 1):
        for comb in combinations(weights, i):
            subsums.append(sum(comb))
    return subsums

# 왼쪽과 오른쪽 부분합 계산
left_subsums = get_subsums(left_weights)
right_subsums = get_subsums(right_weights)

# 오른쪽 부분합 정렬
right_subsums.sort()

# 가능한 조합의 수 계산
count = 0
for left_sum in left_subsums:
    if left_sum <= C:
        # C - left_sum 이하의 right_subsums 원소 개수 찾기
        idx = bisect_right(right_subsums, C - left_sum)
        count += idx

print(count)