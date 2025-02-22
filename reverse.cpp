#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int nums[n];

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int left = 0, right = sizeof(nums)/sizeof(nums[0]) - 1;

    while(left < right) {
        swap(nums[left], nums[right]);
        left++;
        right--;
    }

    for(auto n : nums) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}