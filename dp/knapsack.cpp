#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, w;

    cin >> n >> w;

    vector<int> wt(n);
    vector<int> val(n);

    for(int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> val[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(w+1, 0));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= w; j++) {
            if (j - wt[i-1] >= 0) {
                dp[i][j] = max(
                    dp[i-1][j], //
                    dp[i-1][j-wt[i-1]] + val[i-1]
                );
            } else { 
                dp[i][j] = dp[i-1][j]; //
            }
        }
    }

    cout << dp[n][w] << endl;

    return 0;
}

// 可以进行状态压缩

