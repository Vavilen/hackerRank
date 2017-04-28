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

void dfs(int v, bool vertexes[], vector< vector<uint64_t> > &edges, uint64_t &chainCount) {
    chainCount++;
    vertexes[v] = true;
    for(vector<uint64_t>::iterator it = edges[v].begin(); it != edges[v].end(); ++it) {
        if (!vertexes[*it]) {
            dfs(*it, vertexes, edges, chainCount);
        }
    }
}

int main(){
    int q;
    cin >> q;

    for(int a0 = 0; a0 < q; a0++){
        uint64_t n;
        uint64_t m;
        uint64_t x;
        uint64_t y;
        uint64_t cost = 0;
        cin >> n >> m >> x >> y; //  (the number of cities),  (the number of roads),  (the cost to build a library), and  (the cost to repair a road)
        vector < vector <uint64_t> > edges(n+1);
        bool *vertexes = new bool[n+1];
        for(int a1 = 0; a1 < m; a1++){
            int city_1;
            int city_2;
            cin >> city_1 >> city_2;
            edges[city_1].push_back(city_2);
            edges[city_2].push_back(city_1);
        }

        for (int i = 1; i <= n; i++) {
            vertexes[i] = false;
        };

        if (x <= y || m == 0) {
            cost = x * n;
        } else {
            for (int i = 1; i <= n; i++) {
                if (edges[i].empty()) {
                    cost += x;
                } else if (!vertexes[i]) {
                    uint64_t chainCount = 0;
                    dfs(i, vertexes, edges, chainCount);
                    cost += x + y * (chainCount - 1);
                }
            };

        }
        cout << cost << endl;
    }

    return 0;
}

