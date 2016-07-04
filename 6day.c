#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    unsigned int num;
    unsigned int nnum;
    unsigned int current_size = 128;
    unsigned int ii;
    unsigned int i = 0;
    scanf("%d\n", &num);
    for (nnum = 0; nnum < num; nnum++) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT */
            char string[10000];
            scanf(" %[^\n]s",string);
            char *odd = malloc(10000 / 2 + 1);
            char *even = malloc(10000 / 2 + 1);
            unsigned oddCnt = 0;
            unsigned evenCnt = 0;
            for (ii = 0; ii <= strlen(string) - 1; ii++) {
                if (ii % 2 == 0) {
                    even[evenCnt++] = (char)string[ii];
                } else {
                    odd[oddCnt++] = (char)string[ii];
                }
            }
            printf("%s %s\n", even, odd);
            i = 0;
            ii = 0;
    }
    return 0;
}

