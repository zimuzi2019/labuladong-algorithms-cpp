#include <bits/stdc++.h>
using namespace std;

vector<int> daily_temperatures(vector<int>& t) {
    vector<int> ans(t.size());
    stack<int> s;

    for(int i = t.size()-1; i >= 0; i--) { //
        while(!s.empty() && t[s.top()] <= t[i]) {
            s.pop();
        }
        if (!s.empty()) {
            ans[i] = (s.top() - i); //
        } else {
            ans[i] = 0;
        }
        s.push(i); //
    }

    return ans;
}

int main() {
    int n;

    cin >> n;

    vector<int> t(n);

    for(int i = 0; i < n; i++) {
        cin >> t[i];
    }

    vector<int> res = daily_temperatures(t);

    for(auto r : res) {
        cout << r << " ";
    }
    cout << endl;

    return 0;
}