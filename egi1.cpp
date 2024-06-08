#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

void displayMatrix(vector<vector<int>>& matrix, vector<string>& cities) {
    int V = cities.size();
    cout << setw(12) << " ";
    for (int i = 0; i < V; i++) {
        cout << setw(12) << cities[i];
    }
    cout << endl;

    for (int i = 0; i < V; i++) {
        cout << setw(12) << cities[i];
        for (int j = 0; j < V; j++) {
            cout << setw(12) << matrix[i][j];
        }
        cout << endl;
    }
}

int main() {
    
    cout << "NIM: 2311110042" << endl << endl;
    
    int V;
    cout << "Silakan masukan jumlah simpul:";
    cin >> V;

    vector<string> cities(V);
    cin.ignore(); 
    for (int i = 0; i < V; i++) {
        cout << "Silakan masukan nama simpul wangon" << i + 1 << ": ";
        getline(cin, cities[i]);
    }

    vector<vector<int>> matrix(V, vector<int>(V, 0));

    cout << "Silakan masukan bobot antar simpul\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << cities[i] << "--> " << cities[j] << " = ";
            cin >> matrix[i][j];
        }
    }

    cout << "\nAdjacency Matrix:\n";
    displayMatrix(matrix, cities);

    return 0;
}
