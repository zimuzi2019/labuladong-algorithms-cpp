#include <bits/stdc++.h>
using namespace std;

vector<string> res;

void backtrack(string s, int left, int right) {
    if (left < 0 || right < 0) return;
    if (right < left) return; //
    if (left == 0 && right == 0) {
        res.push_back(s);
        return;
    }

    s.push_back('(');
    backtrack(s, left-1, right);
    s.pop_back();

    s.push_back(')');
    backtrack(s, left, right-1);
    s.pop_back();
}

void generate_parenthesis(int n) {
    string s = "";
    backtrack(s, n, n);
}

int main() {
    int n;

    cin >> n;
    
    generate_parenthesis(n);

    for(auto r : res) {
        cout << r << endl;
    }
    
    return 0;
}