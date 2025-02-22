#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, int> memo;

int super_egg_drop(int k, int n){
    if (k == 1) return n;
    if (n == 0) return 0;

    if (memo.count({k, n}) > 0) {
        return memo[{k, n}];
    }

    int res = INT_MAX;

    for(int i = 1; i <= n; i++) {
        res = min(
            res,
            max(super_egg_drop(k, n-i), super_egg_drop(k-1, i-1)) + 1 // 别忘了 +1
        );
    }

    memo[{k, n}] = res;

    return res;
}

int main() {
    int k, n;

    cin >> k >> n;

    cout << super_egg_drop(k, n) << endl;
     
    return 0;
}

// 原始解法其实推荐用 python，注意怎么用 map 实现类似 dict 的功能，似乎不能用 unordered_map
// 这是最简单的，此题还有些更好的做法