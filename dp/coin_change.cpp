#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> memo;

int dp(vector<int>& coins, int amount) {
    if (amount < 0) return -1;
    if (amount == 0) return 0; //

    if(memo.count(amount) > 0) return memo[amount];

    int res = INT_MAX;

    for(int i = 0; i < coins.size(); i++) {
        if (dp(coins, amount - coins[i]) != -1) { // 子问题有解
            res = min(res, dp(coins, amount - coins[i])+1); // 记得 +1
        }
    }

    if (res == INT_MAX) { //
        memo[amount] = -1;
    } else {
        memo[amount] = res;
    }

    return memo[amount];
}

int main() {
    int amount;
    int n;

    cin >> amount >> n;

    vector<int> coins(n);

    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    cout << dp(coins, amount) << endl;
    
    return 0;
}


// int coinChange(vector<int>& coins, int amount):
//     vector<int> dp(amount+1, amount+1);

//     dp[0] = 0;

//     for (int i = 0; i < dp.size(); i++) {
//         for (int coin : coins):
//             if (i - coin < 0) continue;
//             dp[i] = min(dp[i], 1+dp[i-coin]);
//     }
// 怎么感觉有点像背包问题