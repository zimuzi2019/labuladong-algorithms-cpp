#include <bits/stdc++.h>
using namespace std;

bool check_inclusion(string s, string t) {
    unordered_map<char, int> need, window; //
    for (char c : t) need[c]++;

    int left = 0, right = 0;
    int valid = 0; // 这个最重要，种类和数量都要一样

    while(right < s.size()) {
        char c = s[right];
        right++;

        if (need.count(c) > 0) {
            window[c]++;
            if (window[c] == need[c]) {
                valid++;
            }
        }

        while (right - left >= t.size()) {
            if (valid == need.size()) {
                return true;
            }

            char d = s[left];
            left++;

            if(need.count(d) > 0) {
                if (window[d] == need[d]) {
                    valid--;
                }
                window[d]--;
            }
        }
    }
    return false;
}

int main() {
    string s, t;

    cin >> s >> t;

    if(check_inclusion(s, t)) {
        cout << "Included!" << endl;
    } else {
        cout << "Not included!" << endl;
    }

    return 0;
}