#include <bits/stdc++.h>
using namespace std;

int main() {
    int amount;
    int n;

    cin >> amount >> n;

    vector<int> coins(n);

    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));

    for(int i = 0; i < n + 1; i++) {
        dp[i][0] = 1;
    }

    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= amount; j++) {
            if (j - coins[i-1] >= 0) {
                dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j]; // 注意是 dp[i][j-coins[i-1]]，因为每个物品的数量是无限的
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[n][amount] << endl;

    return 0;
}

// 同样可以进行状态压缩