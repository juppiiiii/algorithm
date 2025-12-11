

def main():
    n, k = map(int, input().split())

    cnt = 0
    while n > k:
        if n % k == 0:
            n /= k
            cnt += 1
        else:
            n -= 1
            cnt += 1

    if 1 < n:
        cnt += (n - 1)
    print(int(cnt))

if __name__ == "__main__":
    main()