#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1;
    string s2;

    cin >> s1 >> s2;

    vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0)); // 用 .size() 取长度

    for(int i = 1; i <= s1.size(); i++) {
        for(int j = 1; j <= s2.size(); j++) {
            if(s1[i] == s2[j]) {
                dp[i][j] = dp[i-1][j-1]+1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[s1.size()][s2.size()] << endl;
     
    return 0;
}

// 一开始还搞混了，直接正着遍历就好了。按照后面的说法，刚好就是两种情况之一

    // for(int i = s1.size() - 1; i > 0; i--) {
    //     for(int j = s2.size(); j > i; j--) {
    //         if(s1[i] == s2[j]) {
    //             dp[i][j] = dp[i+1][j+1]+1;
    //         } else {
    //             dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
    //         }
    //     }
    // }