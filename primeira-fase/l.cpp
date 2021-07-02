#include <bits/stdc++.h>

using namespace std;

int l, c;
vector<string> av(40);
int n;
vector<string> bv(20);
vector<vector<set<int>>> cvv(40, vector<set<int>>(40));

void f(int bidx, string s, int ci, int cj, int tx, int pi, int pj) {
    int slen = s.size();
    string t;
    for (int i = ci, j = cj, x = 0; x < tx; i += pi, j += pj, ++x) {
        t.push_back(av[i][j]);
        int tlen = t.size();
        if (tlen == slen) {
            string st = t;
            sort(st.begin(), st.end());
            if (st == s) {
                for (int k = 0; k < slen; k++) {
                    cvv[ci + (x - slen + 1 + k) * pi][cj + (x - slen + 1 + k) * pj].insert(bidx);
                }
            }
            t.erase(0, 1);
        }
    }
}

int main() {
    cin >> l >> c;
    for (int i = 0; i < l; ++i) {
        cin >> av[i];
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> bv[i];
    }

    for (int x = 0; x < n; ++x) {
        string s = bv[x];
        sort(s.begin(), s.end());
        for (int i = 0; i < l; ++i) {
            f(x, s, i, 0, c, 0, 1);
        }
        for (int i = 0; i < c; ++i) {
            f(x, s, 0, i, l, 1, 0);
        }
        for (int i = 0; i < l; ++i) {
            f(x, s, i, 0, min(l - i, c), 1, 1);
        }
        for (int i = 0; i < c; ++i) {
            f(x, s, 0, i, min(c - i, l), 1, 1);
        }
        for (int i = 0; i < l; ++i) {
            f(x, s, i, c - 1, min(l - i, c), 1, -1);
        }
        for (int i = 0; i < c; ++i) {
            f(x, s, 0, i, min(i + 1, l), 1, -1);
        }
    }
    int ans = 0;
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < c; ++j) {
            if (cvv[i][j].size() >= 2) ++ans;
        }
    }
    cout << ans << endl;

    return 0;
}
