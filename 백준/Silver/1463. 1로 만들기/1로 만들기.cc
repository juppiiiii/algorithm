#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> cache = vector<int>(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        cache[i] = cache[i - 1] + 1;

        if (i % 2 == 0) {
            cache[i] = min(cache[i], cache[i / 2] + 1);
        }
        if (i % 3 == 0) {
            cache[i] = min(cache[i], cache[i / 3] + 1);
        }
    }
    cout << cache[n];

   return 0;
}