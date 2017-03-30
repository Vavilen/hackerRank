#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

//https://www.hackerrank.com/challenges/closest-numbers

using namespace std;

int compare (const void * a, const void * b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    int diff;
    int min;
    vector< pair <int, int> > pairs;
    for (int i=0; i < n; i++) {
        cin >> arr[i];
    }

    qsort(arr, n, sizeof(int), compare);
    min = arr[n -1] - arr[0];
    for (int i=0; i < n - 1; i++) {
        diff = arr[i + 1] - arr[i];
        if (diff < min) {
            if (pairs.size() > 0) {
                pairs.clear();
            }
            min = diff;
            pairs.push_back(make_pair(arr[i], arr[i + 1]));
        }
        else if (diff == min) {
            pairs.push_back(make_pair(arr[i], arr[i + 1]));
        }
    }
    for (int i = 0; i < pairs.size(); i++ ) {
        cout <<  pairs[i].first << " " << pairs[i].second << " ";
    }
    return 0;

}

