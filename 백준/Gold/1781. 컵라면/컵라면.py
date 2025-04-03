import sys
import heapq

input = sys.stdin.read
data = input().split()
N = int(data[0])
assignments = []

# 입력 데이터 파싱
index = 1
for _ in range(N):
    deadline = int(data[index])
    cup_ramen = int(data[index + 1])
    assignments.append((deadline, cup_ramen))
    index += 2

# 데드라인을 기준으로 정렬
assignments.sort()

min_heap = []
for deadline, cup_ramen in assignments:
    heapq.heappush(min_heap, cup_ramen)
    if len(min_heap) > deadline:
        heapq.heappop(min_heap)

print(sum(min_heap))