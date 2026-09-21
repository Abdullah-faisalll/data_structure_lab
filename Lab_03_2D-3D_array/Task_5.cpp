#include <iostream>
using namespace std;

int main() {
    int labs[2][3][5] = {
        {
            {1, 0, 1, 0, 0},
            {0, 1, 1, 0, 1},
            {0, 0, 0, 1, 0}
        },
        {
            {1, 1, 0, 0, 1},
            {0, 0, 0, 0, 0},
            {1, 0, 1, 1, 0}
        }
    };

    int totalAvailable = 0, totalInUse = 0, labAvailable[2] = {0};

    for (int l = 0; l < 2; l++) {
     cout << "Lab " << l + 1 << ":\n";
    for (int r = 0; r < 3; r++) {
     cout << "  Row " << r + 1 << ": ";
    for (int c = 0; c < 5; c++) {
      cout << labs[l][r][c] << " ";
      
    if (labs[l][r][c] == 0) {
        totalAvailable++;
        labAvailable[l]++;
    } else {
            totalInUse++;
    }
    }
            cout << "\n";
    }
    }

    cout << "\nTotal Available: " << totalAvailable;
    cout << "\nTotal In Use: " << totalInUse << "\n";
    for (int l = 0; l < 2; l++) {
        cout << "Lab " << l + 1 << " Available: " << labAvailable[l] << "\n";
    }

    int l, r, c;
    cout << "\nEnter Lab (1-2), Row (1-3), Computer (1-5): ";
    if (cin >> l >> r >> c && l >= 1 && l <= 2 && r >= 1 && r <= 3 && c >= 1 && c <= 5) {
        cout << "Status: " << (labs[l - 1][r - 1][c - 1] ? "In Use" : "Available") << "\n";
    } else {
        cout << "Invalid input!\n";
    }

    return 0;
}
