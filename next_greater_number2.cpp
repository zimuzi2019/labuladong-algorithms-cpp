#include <bits/stdc++.h>
using namespace std;

// 所有的不同就是翻两倍遍历，每次下标都取 % n，相当于每个位置被计算了两次
vector<int> next_greater_element(vector<int>& nums) {
    int n = nums.size();

    vector<int> ans(nums.size());
    stack<int> s;

    for(int i = 2 * n - 1; i >= 0; i--) { //
        while(!s.empty() && s.top() <= nums[i % n]) {
            s.pop();
        }
        if (!s.empty()) {
            ans[i % n] = s.top(); //
        } else {
            ans[i % n] = -1;
        }
        s.push(nums[i % n]);
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