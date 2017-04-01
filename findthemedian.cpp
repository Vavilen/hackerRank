#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

//https://www.hackerrank.com/challenges/find-the-median

using namespace std;
int compare (const void * a, const void * b) {
    return (*(int*)a - *(int*)b);
}

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    qsort(arr, n, sizeof(int), compare);
    int idx = int(n / 2);
    cout << arr[idx];
    return 0;
}
