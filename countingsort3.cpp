#include <cmath>
#include <cstdio>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//https://www.hackerrank.com/challenges/countingsort3

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int counter = 0;
    int t;
    int num;
    string str;
    cin >> t;
    vector<int> cntr(100);
    for (int i = 0; i < t; i++) {
        cin >> num >> str;
        cntr[num]++;

    }
    for (int i = 0; i < 100; i++) {
        counter += cntr[i];
        cout << counter << " ";
    }
    return 0;
}


