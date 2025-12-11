

def main():
    cards = []
    n, m = map(int, input().split(" "))


    minMax = 0
    for i in range(n):
        cards.append(list(map(int, input().split(" "))))
        if minMax < min(cards[i]):
            minMax = min(cards[i])

    print(minMax)
    

if __name__ == "__main__":
    main()