#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    cin >> t;

    int cache[13] = { 0, };
    cache[1] = 1;
    cache[2] = 2;
    cache[3] = 4;

    for (int i = 4; i < 13; i++) {
        cache[i] = cache[i - 1] + cache[i - 2] + cache[i - 3];
    }

    while (t--) {
        cin >> n;
        cout << cache[n] << '\n';
    }
   return 0;
}