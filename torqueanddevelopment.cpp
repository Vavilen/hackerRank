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

void DFS(start ) {

}


int main(){
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int cities_count;
        int road_count;
        int lib_price;
        int road_price;
        set <pair <int, int> > roads;
        cin >> cities_count >> road_count >> lib_price >> road_price;
        for(int a1 = 0; a1 < road_count; a1++){
            int city_1;
            int city_2;
            cin >> city_1 >> city_2;
            roads.insert(make_pair(city_1, city_2));
        }
        cout << (road_count * road_price < lib_price * cities_count ? roads.size() * road_price : lib_price * cities_count) << endl;
    }
    return 0;
}

