#include <bits/stdc++.h>
using namespace std;

bool compare(const vector<int>& a, const vector<int>& b){
    if (a[0] == b[0]) {
        return a[1] > b[1];
    }

    return a[0] < b[0];
}

int main() {
    int n;
    
    cin >> n;

    vector<vector<int>> envs(n, vector<int>(2));

    for(int i = 0; i < n; i++) {
        cin >> envs[i][0] >> envs[i][1];
    }

    sort(envs.begin(), envs.end(), compare);

    vector<int> dp(n, 1);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++) {
            if(envs[j][1] < envs[i][1]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;

    return 0;

}


// 另一种排序写法
// sort(envs.begin(), envs.end(), [](const vector<int>& a, const vector<int>& b) {
//     // 首先按照第一维升序排序，如果相同再按照第二维降序排序
//     if (a[0] == b[0]) {
//         return a[1] > b[1];  // 第二维降序
//     }
//     return a[0] < b[0];  // 第一维升序
// });

// 如果要 sort 一个二维数组，直接 sort(arr, arr+n, compare) 就行
// bool compare(const int a[2], const int b[2]) {
//     if (a[0] == b[0]) {
//         return a[1] > b[1];  // 第二维降序
//     }
//     return a[0] < b[0];  // 第一维升序
// }
