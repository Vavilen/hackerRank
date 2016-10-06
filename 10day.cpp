#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <math.h>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int n;
    int maxConsequence = 0;
    int currentConsequence = 0;
    int currentValue;
    int cnt = 0;
    cin >> n;
    while (n > 0) {
        currentValue = n % 2;
        n = n / 2;

        if(currentValue == 1) {
            currentConsequence++;
        } else {
            if (currentConsequence > maxConsequence) {
                maxConsequence = currentConsequence;
            }
            currentConsequence = 0;
        }
    };
    if (currentConsequence > maxConsequence) {
        maxConsequence = currentConsequence;
    }
    cout << maxConsequence;
    return 0;
}
