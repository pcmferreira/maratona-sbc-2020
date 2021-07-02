#include <bits/stdc++.h>

using namespace std;

int main() {
    bool m[10][10];
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            m[i][j] = false;
        }
    }

    int n;
    cin >> n;

    bool ans = true;

    while (n--) {
        int d, l, r, c;
        cin >> d >> l >> r >> c;
        --r; --c;

        if (ans) {
            if (d == 0) {
                if (c + l - 1 >= 10) { ans = false; break; }
                
                for (int i = c; i < c + l; ++i) {
                    if (m[r][i]) { ans = false; break; }
                    m[r][i] = true;
                }
            } else {
                if (r + l - 1 >= 10) { ans = false; break; }
                
                for (int i = r; i < r + l; ++i) {
                    if (m[i][c]) { ans = false; break; }
                    m[i][c] = true;
                }
            }
        }
    }
    cout << "NY"[ans] << endl;
    return 0;
}
