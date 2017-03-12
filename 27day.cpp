#include <cstdio>
#include <iostream>

using namespace std;
void processCurrent(int current, bool needPositive, int * needCount, int * N, int * K, int * idx) {
    if (*N - *idx -3 <= *K - *needCount ) {
        current = needPositive ? abs(current) : abs(current) * -1;
        needCount++;
    } else if ((needPositive && current >= 0) || ((!needPositive && current < 0))) {
        needCount++;
    }
    cout << current << " ";
}

int main(int argc, char *argv[])
{
    int T = rand() % 100 + 5;
    bool needPositive = true;
    cout << T << endl;
    for (int i = 1; i <= T; i++) {
        int needCount = 2;
        int N = rand() % 200;
        int K = rand() % N;
        cout << N << " " << K << endl;

        int items[3] = {-1,0,1};
        for (int i = 0; i <= 2; i++ ) {
            processCurrent(items[i], needPositive, &needCount, &N, &K, &i);
        }
        for (int j = 1; j <= N - 3; j++ ) {
            int current = rand() % 2000 + (-1000);
            processCurrent(current, needPositive, &needCount, &N, &K, &j);
        }
        cout << endl;

        needPositive = needPositive ? false : true;
    }
    return 0;
}
