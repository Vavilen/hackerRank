#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;

int compare (const void * a, const void * b) {

    return (*(int*)b - *(int*)a);

}

int main(){
    int n;
    cin >> n;
    long sum = 0;
    int calories[n];
    for(int calories_i = 0; calories_i < n; calories_i++){
       cin >> calories[calories_i];
    }
    qsort(calories, n, sizeof(int), compare);
    for (int i = 0; i < n; i++) {
        sum  = sum + calories[i] * pow(2, i);
    }
    cout << sum << endl;
    // your code goes here
    return 0;
}

