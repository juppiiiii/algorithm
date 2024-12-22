#include <iostream>
#include <cmath>

long long recursive(long long a, long long b, long long c) {
    if (b == 1) return a % c;
    long long val = recursive(a, b / 2, c);
    val = val * val % c;
    if (b % 2 == 0) return val;
    return val * a % c;
}

int main() {

    std::ios::sync_with_stdio(NULL);
    std::cin.tie(0);

    long long a, b, c;
    std::cin >> a >> b >> c;
    long long answer = recursive(a, b, c);

    std::cout << answer;
}