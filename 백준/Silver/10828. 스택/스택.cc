#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, tmp;
    string order;
    deque<int> stack;

    cin >> n;
    while (n--) {
        cin >> order;
        if (order == "push") {
            cin >> tmp;
            stack.push_front(tmp);
        } else if (order == "top") {
            if (stack.empty()) {
                cout << -1 << "\n";
            } else {
                cout << stack.front() << "\n";
            }
        } else if (order == "empty") {
            cout << (stack.empty() ? 1 : 0) << "\n";
        } else if (order == "size") {
            cout << stack.size() << "\n";
        } else if (order == "pop") {
            if (stack.empty()) {
                cout << -1 << "\n";
            } else {
                cout << stack.front() << "\n";
                stack.pop_front();
            }
        }
    }
    return 0;
}