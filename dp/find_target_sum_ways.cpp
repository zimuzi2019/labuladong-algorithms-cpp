#include <bits/stdc++.h>
using namespace std;

int main() {
    int target;
    int n;

    cin >> target >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // 转化为子集背包问题 sum(A) = (target + sum(nums)) / 2

    
    return 0;
}