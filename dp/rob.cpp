#include <bits/stdc++.h>
using namespace std;

map<int, int> memo;

int dp(vector<int>& nums, int start) {
    if(start >= nums.size()) return 0;

    if(memo.count(start) > 0) return memo[start];

    memo[start] =  max(
        dp(nums, start+1),
        dp(nums, start+2) + nums[start-1]   
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

    cout << dp(nums, 0) << endl;

    return 0;
}

// map<int, int> memo;

// int dp(vector<int>& nums, int n) {
//     if(n <= 0) return 0;

//     if(memo.count(n) > 0) return memo[n];

//     memo[n] =  max(
//         dp(nums, n-1),
//         dp(nums, n-2) + nums[n-1]   
//     );

//     return memo[n];
// }

// int main() {
//     int n;
//     cin >> n;

//     vector<int> nums(n);

//     for(int i = 0; i < n; i++) {
//         cin >> nums[i];
//     }

//     cout << dp(nums, n) << endl;

//     return 0;
// }

// 或者写成 dp 数组的形式，还可以进行状态压缩