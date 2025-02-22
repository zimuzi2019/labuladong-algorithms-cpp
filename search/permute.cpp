#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> res;

void backtrack(vector<int>& track, vector<int>& nums) {
    if(track.size() ==  nums.size()) {
        res.push_back(track);
        return;
    }

    for(int i = 0; i < nums.size(); i++) {
        if (find(track.begin(), track.end(), nums[i]) != track.end()) { // count 也行
            continue;
        }

        track.push_back(nums[i]);

        backtrack(track, nums);

        track.pop_back();
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> track;

    backtrack(track,nums);

    for (auto r : res) { // 写成 const auto & r 更好
        for (int n : r) {
            cout << n << " ";
        }
        cout << endl;
    }

    return 0;
}