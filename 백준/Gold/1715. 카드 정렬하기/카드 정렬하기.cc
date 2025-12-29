#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b, tmp, sum;
    cin >> n;

    priority_queue<int> minHeap;

    if (n == 1) {
        cout << 0;
        return 0;
    }

    while (n--) {
        cin >> tmp;
        minHeap.push(-tmp);
    }

    long long count = 0;
    while (true) {
        a = minHeap.top();
        minHeap.pop();

        b = minHeap.top();
        minHeap.pop();

        sum = a + b;
        count += sum;

        if (minHeap.empty()) break;

        minHeap.push(sum);
    }

    cout << -count;
    return 0;
}
