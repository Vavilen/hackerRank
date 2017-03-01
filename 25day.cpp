#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void checkPrime(int num) {
    bool result = true;

    if (num == 2) {
        result = true;
    }
    else if ((num % 2 == 0 || num == 1) || (num > 10 && num % 10 == 5)) {
        result = false;
    }
    else {
        for (int j = 3; j <= int(sqrt(num)); j+=2) {
            if (num % j == 0) {
                result = false;
                break;
            }
        }
    }
    cout << (result ? "Prime" : "Not prime") << "\n";
}

int main() {
    int T, data;
    cin >> T;
    if (T > 30) {
        T = 30;
    }
    while (T-->0) {
        cin >> data;
        checkPrime(data);
    }
    return 0;
}

