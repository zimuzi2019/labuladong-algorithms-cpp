#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    cin >> n;

    vector<int> nums(n);

    int sum = 0;

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        sum += nums[i];
    }

    if(sum % 2 != 0) {
        cout << "false" << endl;
        return 0;
    }

    vector<vector<bool>> dp(n+1, vector<bool>(sum/2+1, false));

    for(int i = 0; i < n + 1; i++) {
        dp[i][0] = true;
    }

    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum/2; j++) {
            if (j - nums[i-1] >= 0) {
                dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j]; // 注意有两种情况
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    if (dp[n][sum/2]) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}

