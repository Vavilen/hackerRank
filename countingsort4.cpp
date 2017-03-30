#include <iostream>
#include <list>
#include <vector>

//https://www.hackerrank.com/challenges/countingsort4

using namespace std;
int main() {
    int n;
    cin>>n;
    vector< list <string> > listStrs(100);
    int x;
    string str;
    for(int i=0;i<n;i++ ){
        cin >> x;
        cin >> str;
        if(i<n/2)
            str = '-';
        listStrs[x].push_back(str);
    }


    for (int i = 0; i < listStrs.size(); i++) {

        while (listStrs[i].size() > 0) {
            cout << listStrs[i].front() << " ";
            listStrs[i].pop_front();
        }
    }
    return 0;
}
