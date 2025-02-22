#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    
    cin >> n;

    int a[105];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int dp[105];

    for(int i = 0; i < n; i++) {
        dp[i] = 1;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if (a[j] < a[i] && dp[j]+1 > dp[i]) {
                dp[i] = dp[j]+1;
            } 
        }
    }

    int ans = dp[0];
    for(int i = 0; i < n; i++) {
        if(dp[i] > ans) {
            ans = dp[i];
        }
    }

    cout << ans << endl;

    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;

//     vector<int> a(n);
//     for(int i = 0; i < n; i++) {
//         cin >> a[i];
//     }

//     vector<int> dp(n, 1);  // 动态规划数组，初始化为 1

//     // 使用动态规划计算 LIS
//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < i; j++) {
//             if (a[j] < a[i]) {
//                 dp[i] = max(dp[i], dp[j] + 1);  // 状态转移
//             }
//         }
//     }

//     // 输出结果
//     cout << *max_element(dp.begin(), dp.end()) << endl;

//     return 0;
// }


// 还有一种二分搜索的解法