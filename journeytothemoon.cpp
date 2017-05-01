#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <cassert>

using namespace std;

void bfs(uint64_t currentItem, bool visited[], vector < vector<uint64_t> > &edges, uint64_t &chainCount) {
    queue<uint64_t> bfsq;
    bfsq.push(currentItem);
    while (!bfsq.empty()) {
        uint64_t u = bfsq.front();
        bfsq.pop();
        if (!visited[u]) {
            chainCount++;
            visited[u] = true;
            for (vector<uint64_t>::iterator it = edges[u].begin(); it != edges[u].end(); ++it) {
                bfsq.push(*it);
            }
        }
    }
}

int main()
{
    uint64_t N, I;
    cin >> N >> I;
    vector<vector<uint64_t> > pairs(N);
    for (uint64_t i = 0; i < I; ++i) {
        uint64_t a, b;
        cin >> a >> b;
        pairs[a].push_back(b);
        pairs[b].push_back(a);
    }

    long long result = 0;

    bool *visited = new bool[N];
    for (uint64_t i = 0; i < N; i++) {
        visited[i] = false;
    }
    /** Write code to compute the result using N,I,pairs **/
    vector <uint64_t> groupsChainCount;
    uint64_t restChainCount = 0;
    for (uint64_t i = 0; i < N; i++) {
        uint64_t chainCount = 0;
        if (!visited[i]) {
            if (pairs[i].size() > 0) {
                bfs(i, visited, pairs, chainCount);
                if (chainCount == 0) {
                    chainCount = 1;
                }
                groupsChainCount.push_back(chainCount);
            } else {
                restChainCount++;
            }
        }
    }

    if(restChainCount > 0) {
        groupsChainCount.push_back(restChainCount);
    }
    for (uint64_t i = 0; i < groupsChainCount.size(); i++) {
        for (uint64_t j = i + 1; j < groupsChainCount.size(); j++) {
            result += groupsChainCount[i] * groupsChainCount[j];
        }
    }
    if (restChainCount > 0) {
        for (uint64_t i = restChainCount - 1; i > 0; i--) {
            result += i;
        }
    }

    cout << result << endl;
    return 0;
}

