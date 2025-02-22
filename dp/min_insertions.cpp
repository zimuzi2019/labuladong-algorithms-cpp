#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1;

    cin >> s1;

    vector<vector<int>> dp(s1.size(), vector<int>(s1.size(), 0)); // 用 .size() 取长度

    // for(int i = 0; i < s1.size(); i++) {
    //     dp[i][i] = 1;
    // }

    for(int i = s1.size() - 2; i >= 0; i--) {
        for(int j = i+1; j < s1.size(); j++) {
            if(s1[i] == s1[j]) {
                dp[i][j] = dp[i+1][j-1];
            } else {
                dp[i][j] = min(dp[i][j-1], dp[i+1][j]) + 1;
            }
        }
    }
    
    cout << dp[0][s1.size()-1] << endl;
     
    return 0;
}

// 注意这里插入是 +1 不是 +2
// 同样可以进行状态压缩
