#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> cache(n + 1, 1);
    cache[2] = 2;

    for (int i = 3; i <= n; i++) {
        cache[i] = (cache[i - 2] + cache[i - 1]) % 10007 ;
    }

    cout << cache[n];
    return 0;
}