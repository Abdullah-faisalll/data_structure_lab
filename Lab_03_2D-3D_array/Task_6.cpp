#include <iostream>
using namespace std;

int main() {
    int arr[2][2][2] = {
        {
            {5, 15},
            {25, 35}
        },
        {
            {45, 55},
            {65, 75}
        }
    };

    int searchValue = 25;

    cout << "3D Array:\n\n";

    for (int l = 0; l < 2; l++) {
     cout << "Layer " << l + 1 << ":\n";
    for (int r = 0; r < 2; r++) {
       for (int c = 0; c < 2; c++) {
       cout << arr[l][r][c] << " ";
    }
        cout << "\n";
    }
    cout << "\n";
    }

    cout << "Searching for: " << searchValue << "\n\n";

    bool found = false;
    for (int l = 0; l < 2; l++) {
    for (int r = 0; r < 2; r++) {
    for (int c = 0; c < 2; c++) {
     	
      if (arr[l][r][c] == searchValue) {
        cout << "Element found!\n";
        cout << "Layer: " << l + 1 << "\n";
        cout << "Row: " << r + 1 << "\n";
        cout << "Column: " << c + 1 << "\n";
    found = true;
    break;
    }
}
    if (found) break;
    }
    if (found) break;
    }

    if (!found) {
    cout << "Element not found!\n";
    }

    return 0;
}
