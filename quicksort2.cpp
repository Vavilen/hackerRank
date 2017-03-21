#include <vector>
#include <iostream>

//https://www.hackerrank.com/challenges/quicksort2

using namespace std;

void printIt(vector<int> ar) {
    for (int i = 0; i <= ar.size() - 1; i++) {
        cout << ar[i] << " ";
    }
    cout << endl;
}

vector <int> mergeIt(vector<int>left, int pivot, vector<int> right) {
    left.push_back(pivot);
    left.insert(left.end(), right.begin(), right.end());
    return left;
}

void quickSort(vector <int> &arr) {
    if (arr.size() < 2) {
        return;
    }
    int pivot = arr[0];
    vector <int> left, right;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] <= pivot) {
            left.push_back(arr[i]);
        }
        else {
            right.push_back(arr[i]);
        }
    }
    quickSort(left);
    quickSort(right);
    arr = mergeIt(left, pivot, right);
    printIt(arr);
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

