#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, val;
    vector<int> maxHeap;

    cin >> n;
    while (n--) {
        cin >> val;

        if (val == 0) {
            if (maxHeap.empty()) {
                cout << 0 << "\n";
            } else {
                cout << maxHeap[0] << "\n";
                pop_heap(maxHeap.begin(), maxHeap.end());
                maxHeap.pop_back();
            }
        } else {
            maxHeap.push_back(val);
            push_heap(maxHeap.begin(), maxHeap.end());
        }
    }
    return 0;
}
