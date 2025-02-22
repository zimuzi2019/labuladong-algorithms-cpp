#include <bits/stdc++.h>
using namespace std;

bool compare(vector<int> a, vector<int> b) {
    return a[1] < b[1];
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> intvs(n, vector<int>(2));

    for(int i = 0; i < n; i++) {
        cin >> intvs[i][0] >> intvs[i][1];
    }

    sort(intvs.begin(), intvs.end(), compare);

    int i = 0, ans = 0, x_end = intvs[0][1];
    while(i < intvs.size()) {
        x_end = intvs[i][1];
        
        i++;
        ans++;
        
        while(i < intvs.size() && intvs[i][0] <= x_end) {
            i++;
        }
    }

    cout << ans << endl;

    return 0;
}