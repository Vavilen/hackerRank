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
#include <regex>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Names {
private:
    list<string> names;
public:
    Names(list<string> n) {
        names = n;
    }
    void addName(string);
    void printSortedNames();
};

void Names::addName(string name) {
    names.push_front(name);
}

void Names::printSortedNames() {
    names.sort();
    while(!names.empty()) {
        cout << names.front() << endl;
        names.pop_front();
    }
}



int main(){
    list<string> names;
    Names n(names);
    int N;
    cin >> N;
    for(int a0 = 0; a0 < N; a0++){
        string firstName;
        string emailID;
        cin >> firstName >> emailID;
        if (regex_match(emailID, regex("(.*)(@gmail.com)"))) {
            n.addName(firstName);
        }
    }
    n.printSortedNames();
    return 0;
}

