#include <vector>
#include <iostream>
#include <unistd.h>

//https://www.hackerrank.com/challenges/quicksort3

using namespace std;
int quickSortCounter = 0;
int insertionSortCounter = 0;

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
                    printf("swapped: j: %d <=> i: %d\n", j, i);
                    j != i ? quickSortCounter += 2 : quickSortCounter++;
                    if (i == pivotIdx) {
                        newPivotIdx = j;
                    }
                    break;
                }

            }
        }
    }
    partition(startIdx, newPivotIdx -1, arr);
    partition(newPivotIdx + 1, pivotIdx, arr);
}

void insertionSort(int ar_size, vector<int> ar) {
    for (int i=1; i < ar_size; i++) {
        int tmp = ar[i];
        for (int j = i; j > 0; j--) {
            if (tmp < ar[j - 1]) {
                insertionSortCounter++;
                ar[j] = ar[j - 1];
                ar[j - 1] = tmp;
            }
            else {
                ar[j] = tmp;
                break;
            }
        }
    }

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
    insertionSort(arr.size(), arr);
    quickSort(arr);
    printf("quickSortCounter: %d, insertionSortCounter: %d\n", quickSortCounter, insertionSortCounter);
    cout << insertionSortCounter - quickSortCounter;
    return 0;
}



