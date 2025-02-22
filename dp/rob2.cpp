#include <bits/stdc++.h>
using namespace std;

map<int, int> memo;

int dp(vector<int>& nums, int start, int end) {
    if(start >= end) return 0;

    if(memo.count(start) > 0) return memo[start];

    memo[start] =  max(
        dp(nums, start+1, end),
        dp(nums, start+2, end) + nums[start-1]   
    );

    return memo[start];
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    if (nums.size() == 1) cout << nums[0] << endl;

    cout << max(dp(nums, 0, n-2), dp(nums, 1, n-1)) << endl;


    return 0;
}