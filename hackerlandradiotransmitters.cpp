
#include <map>

#include <set>

#include <list>

#include <cmath>

#include <ctime>

#include <deque>

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



int compare (const void * a, const void * b) {

    return (*(int*)a - *(int*)b);

}







int main(){

    int n;

    int k;

    int transmittersCount = 0;

    int currentPositionIdx = 0;

    int currentTransmitterPositionIdx = 0;

    cin >> n >> k;

    int x[n];

    for(int x_i = 0;x_i < n;x_i++){

       cin >> x[x_i];

    }

    qsort(x, n, sizeof(int), compare);

    while (currentPositionIdx < n) {


        transmittersCount++;

        currentTransmitterPositionIdx = currentPositionIdx;

        while(currentTransmitterPositionIdx + 1 < n && x[currentTransmitterPositionIdx + 1] - x[currentPositionIdx] <= k) {
            currentTransmitterPositionIdx++;
        }
        currentPositionIdx = currentTransmitterPositionIdx;

        while(currentPositionIdx + 1 < n  && x[currentPositionIdx + 1] - x[currentTransmitterPositionIdx] <= k) {
            currentPositionIdx++;
        }

        currentPositionIdx++;
    }



    cout << transmittersCount << endl;

    return 0;

}



