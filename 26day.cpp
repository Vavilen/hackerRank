#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int da, ma, ya;
    int de, me, ye;
    int fine = 0;
    cin >> da >> ma >> ya;
    cin >> de >> me >> ye;

    if (ya < ye) {
        fine = 0;
    }
    else if (ya > ye) {
        fine = 10000;
    }
    else if (ma > me ) {
        fine = (ma -me) * 500;
    }
    else if (da > de) {
        fine = (da - de) * 15;
    }

    cout << fine << endl;
    return 0;
}

