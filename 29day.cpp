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


int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int k;
        int c;
        int m = 0;
        cin >> n >> k;
        for (int a = 0; a <= n; a++) {
            for (int b = a + 1; b <= n; b++) {
                c = a & b;
                if (c > m && c < k) {
                    m = c;
                }
            }
        }
        cout << m << endl;
    }
    return 0;
}

