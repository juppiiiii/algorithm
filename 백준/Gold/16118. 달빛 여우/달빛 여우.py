import heapq
import sys
input = sys.stdin.read
INF = sys.maxsize

def solve():
    data = input().split()
    idx = 0

    N = int(data[idx]); idx += 1
    M = int(data[idx]); idx += 1

    graph = [[] for _ in range(N + 1)]
    for _ in range(M):
        a = int(data[idx]); idx += 1
        b = int(data[idx]); idx += 1
        d = int(data[idx]); idx += 1
        graph[a].append((b, d * 2))
        graph[b].append((a, d * 2))  # 여우 기준으로 모두 *2 (늑대 처리 시 편하게 하기 위해)

    # 여우의 최단거리 (일반적인 다익스트라)
    fox_dist = [INF] * (N + 1)
    fox_dist[1] = 0
    heap = [(0, 1)]
    while heap:
        time, now = heapq.heappop(heap)
        if fox_dist[now] < time:
            continue
        for nxt, cost in graph[now]:
            if fox_dist[nxt] > time + cost:
                fox_dist[nxt] = time + cost
                heapq.heappush(heap, (time + cost, nxt))

    # 늑대의 최단거리 (두 가지 상태: 빠르게 vs 느리게)
    wolf_dist = [[INF] * (N + 1) for _ in range(2)]  # 0: 빠르게, 1: 느리게
    wolf_dist[0][1] = 0
    heap = [(0, 1, 0)]  # (time, node, state)

    while heap:
        time, now, state = heapq.heappop(heap)
        if wolf_dist[state][now] < time:
            continue
        for nxt, cost in graph[now]:
            if state == 0:  # 빠르게: 시간 절반
                new_time = time + cost // 2
                if wolf_dist[1][nxt] > new_time:
                    wolf_dist[1][nxt] = new_time
                    heapq.heappush(heap, (new_time, nxt, 1))
            else:  # 느리게: 시간 두 배
                new_time = time + cost * 2
                if wolf_dist[0][nxt] > new_time:
                    wolf_dist[0][nxt] = new_time
                    heapq.heappush(heap, (new_time, nxt, 0))

    # 비교
    result = 0
    for i in range(2, N + 1):
        if fox_dist[i] < min(wolf_dist[0][i], wolf_dist[1][i]):
            result += 1

    print(result)

solve()