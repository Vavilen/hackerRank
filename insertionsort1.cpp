#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

//https://www.hackerrank.com/challenges/insertionsort1

void printIt(vector<int> ar) {
    for (int i = 0; i <= ar.size() - 1; i++) {
        cout << ar[i] << " ";
    }
    cout << endl;
}

void insertionSort(vector <int>  ar) {
    int tmp = ar[ar.size() - 1];
    for (int i = ar.size() - 1; i >= 0; i--) {
        if (ar[i -1] > tmp) {
            ar[i] = ar[i - 1];
            printIt(ar);
        }
        else {
            ar[i] = tmp;
            printIt(ar);
            break;
        }

    }
}


int main(void) {
    vector <int>  _ar;
    int _ar_size;
    cin >> _ar_size;
    for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
        int _ar_tmp;
        cin >> _ar_tmp;
        _ar.push_back(_ar_tmp);
    }

    insertionSort(_ar);
    return 0;
}

