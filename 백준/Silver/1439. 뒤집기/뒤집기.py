

def main():
    given = list(map(int, input()))

    divider = [given[0]]

    for i in range(1, len(given)):
        if divider[-1] != given[i]:
            divider.append(given[i])

    print(min(divider.count(0), divider.count(1)))


if __name__ == "__main__":
    main()