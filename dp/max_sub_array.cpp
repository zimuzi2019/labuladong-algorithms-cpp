#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    
    cin >> n;

    vector<int> a(n);
    vector<int> dp(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    dp[0] = a[0];

    for(int i = 1; i < n; i++) {
        dp[i] = max(dp[i-1]+a[i], a[i]);
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;
    
    return 0;
}

// 可以进一步进行状态压缩