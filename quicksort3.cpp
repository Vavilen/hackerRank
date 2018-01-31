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
    cout << "partition. startIdx: " << startIdx << ", pivotIdx: " << pivotIdx << endl;
    int lastSwappedIdx = 0;
    int newPivotIdx = pivotIdx;
    if (pivotIdx - startIdx < 1) {
        return;
    }
    // проходим от startIdx до pivotIdx
    for (int i = startIdx; i <= pivotIdx; i++) {
        // если текущий элемент меньше опорного
        if (arr->at(i) <= arr->at(pivotIdx)) {
            // тогда идем от нулевого элемента и до текущего
            for (int j = 0; j <= i; j++) {
                // если этот (j) элемент больше опорного и последний измененный элемент слева от этого (j)
                if (arr->at(j) > arr->at(pivotIdx) && lastSwappedIdx <= j) {
                    // индексом последнего измененного становится индекс j-го элемента
                    lastSwappedIdx = j;
                    // меняем j-й элемент с i-м элементом
                    std::swap(arr->at(j), arr->at(i));
                    cout << "swapped. j-idx: " << j << ", i-idx: " << i  << endl;
                    printParted(0, arr->size() - 1, arr);
                    // если i-й элемент был опорным, то i-й индекс становится pivotIdx индексом
                    if (i == pivotIdx) {
                        // новый опорный теперь под индексом j
                        newPivotIdx = j;
                    }
                    break;
                } else {
                    cout << "skip. j-idx: " << j << ", i-idx: " << i  << endl;
                }

            }
        }
    }
//    printParted(0, arr->size() - 1, arr);
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



