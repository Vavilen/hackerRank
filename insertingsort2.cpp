#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <cassert>
#include <iostream>
using namespace std;

void printIt(vector<int> ar) {
    for (int i = 0; i <= ar.size() - 1; i++) {
        cout << ar[i] << " ";
    }
    cout << endl;
}


void insertionSort(int ar_size, int *  ar) {
    for (int i=0; i < ar_size; i++) {
        int tmp = ar[i];
        for (int j = i; j > 0; j--) {
            if (ar[j] < ar[j -1]) {
                ar[j - 1] = ar[j];
            }
            else {
                arr[j] = tmp;
                goto INNER;
            }
        }
        INNER:
        printIt(ar);
    }

}


int main(void) {

    int _ar_size;
    cin >> _ar_size;
    //scanf("%d", &_ar_size);
    int _ar[_ar_size], _ar_i;
    for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) {
        cin >> _ar[_ar_i];
        //scanf("%d", &_ar[_ar_i]);
    }

   insertionSort(_ar_size, _ar);

   return 0;
}

