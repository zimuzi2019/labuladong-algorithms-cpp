#include <bits/stdc++.h>
using namespace std;

bool is_valid(string s) {
    stack<char> t;

    for(int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            t.push(s[i]);
        }
        else if (s[i] == ')') {
            if (!s.empty() && t.top() == '(') t.pop();
            else return false;
        }
        else if (s[i] == ']') {
            if (!s.empty() && t.top() == '[') t.pop();
            else return false;
        }
        else if (s[i] == '}') {
            if (!s.empty() && t.top() == '{') t.pop();
            else return false;
        }
        else {
            return false;
        }
    }

    return t.empty();
}

int main() {
    string s;
    cin >> s;

    if (is_valid(s)) cout << "Valid!" << endl;
    else cout << "Not valid!" << endl;

    return 0;
}