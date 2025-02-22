#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;

    vector<int> nums(n);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int left = 0, right = nums.size()-1;

    while(left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) {
            cout << "[" << left+1 << ", " << right+1 << "]" << endl;
            break;
        }
        else if (sum < target) left++;
        else right--; 
    }

    return 0;
}