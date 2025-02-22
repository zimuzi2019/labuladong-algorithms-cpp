#include <bits/stdc++.h>
using namespace std;

string palindrome(string s, int l, int r) {
    while(l >= 0 && r < s.size() && s[l] == s[r]) {
        l--;
        r++;
    }
    return s.substr(l+1, r-l-1);
}

string longest_palindrome(string s) {
    string res;

    // 依次以每个字符为中心
    for(int i = 0; i < s.size(); i++) {
        string s1 = palindrome(s, i, i);
        string s2 = palindrome(s, i, i+1);

        res = res.size() > s1.size() ? res : s1;
        res = res.size() > s2.size() ? res : s2;
    }

    return res;
}

int main() {
    string s;
    cin >> s;

    cout << longest_palindrome(s) << endl;

    return 0;
}