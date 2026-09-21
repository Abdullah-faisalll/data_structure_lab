#include <iostream>
using namespace std;

int main() {
    int hospital[3][3][4] = {
        {{1, 0, 1, 0}, {0, 0, 1, 1}, {1, 1, 0, 0}},
        {{0, 1, 0, 1}, {1, 0, 0, 0}, {1, 1, 1, 0}},
        {{0, 0, 0, 0}, {1, 1, 1, 1}, {0, 1, 0, 1}}
    };

    int totalOccupied = 0, totalAvailable = 0, floorOccupied[3] = {0};

    for (int f = 0; f < 3; f++) {
     cout << "Floor " << f + 1 << ":\n";
    for (int w = 0; w < 3; w++) {
     cout << " Ward " << w + 1 << ": ";
    for (int b = 0; b < 4; b++) {
     cout << hospital[f][w][b] << " ";
     
    if (hospital[f][w][b] == 1) {
    	
        totalOccupied++;
        floorOccupied[f]++;
        }
	else {
        totalAvailable++;
        }
    }
    cout << "\n";
        }
    }

    cout << "\nTotal Occupied: " << totalOccupied;
    cout << "\nTotal Available: " << totalAvailable << "\n";
    for (int f = 0; f < 3; f++) {
        cout << "Floor " << f + 1 << " Occupied: " << floorOccupied[f] << "\n";
    }

    int f, w, b;
    cout << "\nEnter Floor 1-3, Ward 1-3, Bed 1-4: ";
    if (cin >> f >> w >> b && f >= 1 && f <= 3 && w >= 1 && w <= 3 && b >= 1 && b <= 4) {
        cout << "Status: " << (hospital[f - 1][w - 1][b - 1] ? "Occupied" : "Available") << "\n";
    } else {
        cout << "Invalid input!\n";
    }

    return 0;
}
