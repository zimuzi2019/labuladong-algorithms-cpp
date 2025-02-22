#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& heights) {
    int l_max = heights[0], r_max = heights[heights.size() - 1], ans = 0;

    int left = 1, right = heights.size() - 2;

    while(left <= right) {
        if (l_max < r_max) { // 只先确定其中一个
            if (l_max - heights[left] > 0) ans += l_max - heights[left];
            else l_max = heights[left];

            left++;
        }
        else {
            if (r_max - heights[right] > 0) ans += r_max - heights[right];
            else r_max = heights[right];

            right--;
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);

    for(int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    cout << trap(heights) << endl;
    
    return 0;
}