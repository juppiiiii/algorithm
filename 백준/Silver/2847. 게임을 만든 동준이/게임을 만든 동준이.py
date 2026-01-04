

def main():
    n = int(input())
    scores = []

    for i in range(n):
        scores.append(int(input()))

    cnt = 0
    for i in range(n - 1, 0, -1):
        if scores[i - 1] >= scores[i]:
            differ = scores[i - 1] - scores[i] + 1 
            scores[i - 1] -= differ
            cnt += differ
    
    print(cnt)


if __name__ == "__main__":
    main()