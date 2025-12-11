

def main():
    n, m, k = map(int, input().split(" "))
    nums = list(map(int, input().split()))

    nums.sort(reverse=True)
    print(nums)

    sum = nums[0] * (m - m // k) + nums[1] * (m // k)

    print(sum)

if __name__ == "__main__":
    main()