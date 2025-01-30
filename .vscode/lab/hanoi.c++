#include <iostream>
#include <vector>

using namespace std;

void strassen(vector<vector<int>>& a, vector<vector<int>>& b, vector<vector<int>>& c) {
    int P, Q, R, S, T, U, V;

    P = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
    Q = (a[1][0] + a[1][1]) * b[0][0];
    R = a[0][0] * (b[0][1] - b[1][1]);
    S = a[1][1] * (b[1][0] - b[0][0]);
    T = (a[0][0] + a[0][1]) * b[1][1];
    U = (a[1][0] - a[0][0]) * (b[0][0] + b[0][1]);
    V = (a[0][1] - a[1][1]) * (b[1][0] + b[1][1]);

    c[0][0] = P + S - T + V;
    c[0][1] = R + T;
    c[1][0] = Q + S;
    c[1][1] = P + R - Q + U;

    cout << "Resultant matrix:\n";
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            cout << c[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    vector<vector<int>> a(2, vector<int>(2)), b(2, vector<int>(2)), c(2, vector<int>(2));

    cout << "Enter the first matrix of 2*2\n";
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            cin >> a[i][j];
        }
    }

    cout << "Enter the second matrix of 2*2\n";
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            cin >> b[i][j];
        }
    }

    strassen(a, b, c);

    return 0;
}