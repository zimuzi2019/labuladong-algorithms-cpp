#include <bits/stdc++.h>
using namespace std;

vector<int> find_anagrams(string s, string t) {
    unordered_map<char, int> need, window; //
    for (char c : t) need[c]++;

    int left = 0, right = 0;
    int valid = 0;

    vector<int> res;

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
                res.push_back(left);
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
    return res;
}

int main() {
    string s, t;

    cin >> s >> t;

    vector<int> res = find_anagrams(s, t);

    for (auto r : res) {
        cout << r << " ";
    }
    cout << endl;

    return 0;
}