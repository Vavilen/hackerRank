#include <cmath>
#include <cstdio>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//https://www.hackerrank.com/challenges/countingsort1

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    int item;
    cin >> t;
    vector<int> cntr(100);
    for (int i = 0; i < t; i++) {
        cin >> item;
        cntr[item]++;

    }
    for (int i = 0; i < 100; i++) {
        cout << cntr[i] << " ";

    }
    return 0;
}


