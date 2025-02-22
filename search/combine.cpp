#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> res;

void backtrack(vector<int> track, int n, int k, int start) {
    if (track.size() == k) {
        res.push_back(track);
        return;
    }
    
    for (int i = start; i < n; i++) {
        // if (count(track.begin(), track.end(), i+1) > 0) {
        //     continue;
        // }
        
        track.push_back(i+1);

        backtrack(track, n, k, i+1); //

        track.pop_back();
    }
}

void combine(int n, int k) {
    vector<int> track;
    backtrack(track, n, k, 0);
}

int main() {
    int n, k;

    cin >> n >> k;

    combine(n, k);

    for (auto r : res) {
        for (auto n : r) {
            cout << n << " ";
        }
        cout << endl;
    }

    return 0;
}