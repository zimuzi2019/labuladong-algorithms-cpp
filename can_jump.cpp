#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int farthest = 0;

    for (int i = 0; i < n-1; i++) {
        farthest = max(farthest, i + nums[i]);

        if (farthest <= i) {
            cout << "Can't jump!" << endl;
            return 0;
        }
    }

    if (farthest >= n-1) cout << "Can jump!" << endl;
    else cout << "Can't jump!" << endl;

    return 0;
}