#include<bits/stdc++.h>
using namespace std;

bool can_finish(vector<int>& weights, int d, int cap) {
    int i = 0;

    for (int day = 0; day < d; day++) {
        int max_cap = cap;
        while((max_cap >= weights[i])) {
            max_cap -= weights[i];
            i++;

            if (i == weights.size()) return true;
        }
    }
    return false;
}

int ship_within_days(vector<int>& weights, int d) {
    int n = weights.size();

    int left = *max_element(weights.begin(), weights.end()), right = accumulate(weights.begin(), weights.end(), 0); //

    while(left < right) {
        int mid = (left + right) / 2;

        if (can_finish(weights, d, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return right;
}

int main() {
    int n, d;

    cin >> n >> d;

    vector<int> weights(n);

    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    cout << ship_within_days(weights, d) << endl;

    return 0;
}