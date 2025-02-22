#include <bits/stdc++.h>
using namespace std;

int sub_array_sum(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> pre_sum; // 存储什么？
    pre_sum[0] = 1;

    int ans = 0, sum_i = 0;
    for (int i = 0; i < n; i++) {
        sum_i += nums[i];

        int sum_j = sum_i - k;

        if(pre_sum.count(sum_j) > 0) {
            ans += pre_sum[sum_j];
        }

        pre_sum[sum_i]++;
    }

    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << sub_array_sum(nums, k) << endl;

    return 0;
}