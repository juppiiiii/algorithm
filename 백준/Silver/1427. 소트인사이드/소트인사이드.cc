#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    vector<int> answer;
    while (n > 0) {
        int divider = n % 10;
        answer.push_back(divider);

        n /= 10;
    }

    sort(answer.begin(), answer.end(), [](int a, int b) {
        return a > b;
    });

    for (auto i : answer) {
        cout << i;
    }

    return 0;
}