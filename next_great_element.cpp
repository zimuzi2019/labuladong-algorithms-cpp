#include <bits/stdc++.h>
using namespace std;

vector<int> next_greater_element(vector<int>& nums) {
    vector<int> ans(nums.size());
    stack<int> s;

    for(int i = nums.size()-1; i >= 0; i--) { //
        while(!s.empty() && s.top() <= nums[i]) {
            s.pop();
        }
        if (!s.empty()) {
            ans[i] = s.top(); //
        } else {
            ans[i] = -1;
        }
        s.push(nums[i]);
    }

    return ans;
}

int main() {
    int n;

    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> res = next_greater_element(nums);

    for(auto r : res) {
        cout << r << " ";
    }
    cout << endl;

    return 0;
}