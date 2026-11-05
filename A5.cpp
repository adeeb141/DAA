
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

// Deterministic Quick Sort
int partitionDet(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortDet(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partitionDet(arr, low, high);

        quickSortDet(arr, low, pi - 1);
        quickSortDet(arr, pi + 1, high);
    }
}

// Randomized Quick Sort
int partitionRandom(vector<int>& arr, int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);

    swap(arr[randomIndex], arr[high]);

    return partitionDet(arr, low, high);
}

void quickSortRandom(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partitionRandom(arr, low, high);

        quickSortRandom(arr, low, pi - 1);
        quickSortRandom(arr, pi + 1, high);
    }
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> arr1 = arr;
    vector<int> arr2 = arr;

    srand(time(0));

    // Deterministic Quick Sort
    quickSortDet(arr1, 0, n - 1);

    cout << "\nDeterministic Quick Sort:\n";
    for (int x : arr1) {
        cout << x << " ";
    }

    // Randomized Quick Sort
    quickSortRandom(arr2, 0, n - 1);

    cout << "\n\nRandomized Quick Sort:\n";
    for (int x : arr2) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
