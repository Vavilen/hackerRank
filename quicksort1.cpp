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

//https://www.hackerrank.com/challenges/quicksort1

using namespace std;

void printIt(vector<int> ar) {
    for (int i = 0; i < ar.size(); i++) {
        cout << ar[i] << " ";
    }
}

void partition(vector <int>  ar) {
    vector <int> left, equal, right;
    if (ar.size() == 0) {
            return;
        }
    equal.push_back(ar[0]);
    for (int i = 1; i < ar.size(); i++) {
        if (ar[i] < ar[0]) {
            left.push_back(ar[i]);
        }
        else if (ar[i] > ar[0]) {
            right.push_back(ar[i]);
        }
        else {
            equal.push_back(ar[i]);
        }
    }
   printIt(left);
   printIt(equal);
   printIt(right);
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

   partition(_ar);

   return 0;
}

