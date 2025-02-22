#include <bits/stdc++.h>
using namespace std;

int length_of_longest_substring(string s) {
    unordered_set<char> window; 
    int left = 0, right = 0, len = 0;
    int res = 0;

    while(right < s.size()) {
        char c = s[right];

        while (window.count(c) > 0) {
            window.erase(s[left]);
            left++;
            len--;
        }

        window.insert(c);
        right++;
        len++;

        res = max(res, len);
    }
    return res;
}

int main() {
    string s;

    cin >> s;

    cout << length_of_longest_substring(s) << endl;

    return 0;
}