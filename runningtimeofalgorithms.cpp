#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>

//https://www.hackerrank.com/challenges/runningtime

void insertionSort(int N, int arr[]) {
    int i,j;
    int value;
    int movesCnt = 0;
    for(i=1;i<N;i++)
    {
        value=arr[i];
        j=i-1;
        int steps = 0;
        while(j>=0 && value<arr[j])
        {
            arr[j+1]=arr[j];
            j=j-1;
            movesCnt++;
        }
        arr[j+1]=value;
    }
    std::cout << movesCnt;
}
int main(void) {

    int N;
    scanf("%d", &N);
    int arr[N], i;
    for(i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    insertionSort(N, arr);

    return 0;
}

