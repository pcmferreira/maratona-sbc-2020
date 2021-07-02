#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, d, a;
    cin >> n >> d >> a;
    cout << ((d - a + n) % n) << endl;
    return 0;
}
