#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    cin >> n;

    vector<int> nums(n+2);

    nums[0] = 1;
    nums[n+1] = 1;

    for(int i = 1; i <= n; i++){
        cin >> nums[i];
    }

    vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

    for(int i = n; i >= 0; i--) {
        for(int j = i+1; j < n+2; j++) {
            for(int k = i+1; k < j; k++) {
                dp[i][j] = max(
                    dp[i][j],
                    dp[i][k] + dp[k][j] + nums[k] * nums[i] * nums[j]
                );
            }
        }
    }

    cout << dp[0][n+1] << endl;

    return 0;
}

