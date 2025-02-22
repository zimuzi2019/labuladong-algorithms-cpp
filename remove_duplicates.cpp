#include <bits/stdc++.h>
using namespace std;

int remove_duplicate(vector<int>& nums) {
    int slow = 0, fast = 1;

    while(fast < nums.size()) {
        if (nums[fast] != nums[slow]) {
            slow++;
            nums[slow] = nums[fast];
        } 
        fast++;
    }
    return slow+1;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << remove_duplicate(nums) << endl;

    return 0;
}