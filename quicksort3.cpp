#include <vector>
#include <iostream>
#include <unistd.h>

//https://www.hackerrank.com/challenges/quicksort3

using namespace std;

void printParted(int startIdx, int pivotIdx, vector<int> *arr) {
    for (int i = startIdx; i <= pivotIdx; i++) {
        cout << arr->at(i) << " ";
    }
    cout << endl;
}

void partition(int startIdx, int pivotIdx, vector <int> *arr) {
    int lastSwappedIdx = 0;
    int newPivotIdx = pivotIdx;
    if (pivotIdx - startIdx < 1) {
        return;
    }

    for (int i = startIdx; i <= pivotIdx; i++) {
        if (arr->at(i) <= arr->at(pivotIdx)) {
            for (int j = 0; j <= i; j++) {
                if (arr->at(j) > arr->at(pivotIdx) && lastSwappedIdx <= j) {
                    lastSwappedIdx = j;
                    std::swap(arr->at(j), arr->at(i));
                    if (i == pivotIdx) {
                        newPivotIdx = j;
                    }
                    break;
                }

            }
        }
    }
    printParted(0, arr->size() - 1, arr);
    partition(startIdx, newPivotIdx -1, arr);
    partition(newPivotIdx + 1, pivotIdx, arr);
}

void quickSort(vector <int> arr) {
    if (arr.size() == 0) {
        return;
    }
    partition(0, arr.size() - 1, &arr);
}

int main()

{
    int n;
    cin >> n;
    vector <int> arr(n);

    for(int i = 0; i < (int)n; ++i) {
        cin >> arr[i];
    }
    quickSort(arr);
    return 0;
}



