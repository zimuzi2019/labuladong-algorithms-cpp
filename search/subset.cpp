#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> res;

void backtrack(vector<int>& track, vector<int>& nums, int start) { // 比传统的回溯框架多一个 start 参数
    res.push_back(track);

    for (int i = start; i < nums.size(); i++) {
        // if (count(track.begin(), track.end(), nums[i]) > 0) {
        //     continue;
        // }
        
        track.push_back(nums[i]);

        backtrack(track, nums, i+1);

        track.pop_back();
    }
}

void subsets(vector<int>& nums) {
    vector<int> track;
    backtrack(track, nums, 0);
}

int main() {
    int n;

    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    subsets(nums);

    for (auto r : res) {
        for (auto n : r) {
            cout << n << " ";
        }
        cout << endl;
    }

    return 0;
}