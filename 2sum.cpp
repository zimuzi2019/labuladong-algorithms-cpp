#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;

    vector<int> nums(n);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    unordered_map<int, int> index;
    for (int i = 0; i < n; i++) {
        index[nums[i]] = i; // 为什么两个相同的值不会被覆盖？
    }

    for (int i = 0; i < n; i++) {
        int other = target - nums[i];

        //
        if (index.count(other) > 0 && index[other] != i) { 
            cout << "[" << i << ", " << index[other] << "]";

            return 0; // 因为题干说了唯一解，直接就返回了
        }
    }

    return 0;
}