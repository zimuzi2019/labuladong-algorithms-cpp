#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    
    cin >> n;

    vector<int> dp(n + 1, 0);

    for(int i = 1; i <= n; i++) {
        // 如果按 A 键
        dp[i] = dp[i - 1] + 1;

        // 如果按 C-V 键，从之前某次开始选了 C-A + C-C 然后一直 C-V 循环
        for(int j = 2; j < i; j++) {
            dp[i] = max(dp[i], dp[j-2] * (i-j+1));
        }
    }
    
    cout << dp[n] << endl;
     
    return 0;
}

// 不要想得太复杂。每次要么按 A 键，要么按 C-V 键