#include<bits/stdc++.h>
using namespace std;

int time_of(int n, int speed) {
    if (n % speed == 0) return n / speed;
    else return n / speed + 1;
}

bool can_finish(vector<int>& piles, int h, int speed) {
    int time = 0;
    for (int pile : piles) {
        time += time_of(pile, speed);
    }

    if (time <= h) return true;
    else return false;
}

int min_eating_speed(vector<int>& piles, int h) {
    int n = piles.size();

    int left = 1, right = *max_element(piles.begin(), piles.end());

    while(left < right) {
        int mid = (left + right) / 2;

        if (can_finish(piles, h, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return right;
}

int main() {
    int n, h;

    cin >> n >> h;

    vector<int> piles(n);

    for (int i = 0; i < n; i++) {
        cin >> piles[i];
    }

    cout << min_eating_speed(piles, h) << endl;

    return 0;
}