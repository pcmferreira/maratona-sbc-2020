#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    bool saque = false;
    int pontos[] = {0, 0};
    int jogos[] = {0, 0};

    bool haVencedor = false;
    bool vencedor = false;

    for (char c : s) {
        if (c == 'Q') {
            for (int i = 0; i < 2; ++i) {
                cout << jogos[i];
                if (haVencedor) {
                    if (vencedor == i)
                        cout << " (winner)";
                } else {
                    cout << " (" << pontos[i];
                    if (saque == i) cout << "*";
                    cout << ")";
                }
                if (i == 0) cout << " - ";
                else cout << endl;
            }
        } else if (!haVencedor) {
            if (c == 'R') saque = !saque;
            ++pontos[saque];
            if (
                pontos[saque] >= 5 &&
                (
                    pontos[saque] - pontos[!saque] >= 2 ||
                    pontos[saque] == 10
                )
            ) {
                pontos[0] = pontos[1] = 0;
                ++jogos[saque];
            }
            if (jogos[saque] == 2) {
                haVencedor = true;
                vencedor = saque;
            }
        }
    }
    return 0;
}
