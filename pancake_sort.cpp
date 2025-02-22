#include <bits/stdc++.h>
using namespace std;

vector<int> res;

void reverse(vector<int>& a, int i, int j) {
    while(i < j) {
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
        i++;
        j--;
    }
}

void pancake_sort(vector<int>& cakes, int n) {
    if (n == 1) {
        return;
    }

    int max_cake_index = 0;
    int max_cake = cakes[0];

    for (int i = 1; i < n; i++) {
        if (cakes[i] > max_cake) {
            max_cake_index = i;
            max_cake = cakes[i];
        }
    }

    reverse(cakes, 0, max_cake_index);
    res.push_back(max_cake_index+1);

    reverse(cakes, 0, n-1);
    res.push_back(n);

    pancake_sort(cakes, n-1);
}

int main() {
    int n;
    cin >> n;

    vector<int> cakes(n);

    for(int i = 0; i < n; i++) {
        cin >> cakes[i];
    }

    pancake_sort(cakes, n);

    for(auto r : res) {
        cout << r << " ";
    }
    cout << endl;

    return 0;
}