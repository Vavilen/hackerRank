#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char *s = malloc(128);
    int c = EOF;
    unsigned int num;
    unsigned int nnum;
    unsigned int current_size = 128;
    unsigned int ii;
    unsigned int i = 0;
    scanf("%d\n", &num);
    for (nnum =0; nnum <= num; nnum++) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT */
            while( ( ( c = fgetc(stdin) ) != '\n' || i == 0) && c!= EOF) {
                s[i++] = (char)c;
                if (i == current_size) {
                    current_size = i + 128;
                    s = realloc(s, current_size);
                }
            }
            char *odd = malloc(current_size / 2 + 1);
            char *even = malloc(current_size / 2 + 1);
            unsigned oddCnt = 0;
            unsigned evenCnt = 0;
            for (ii = 0; ii <= i; ii++) {
                if (ii % 2 == 0) {
                    even[evenCnt++] = (char)s[ii];
                } else {
                    odd[oddCnt++] = (char)s[ii];
                }
            }
            printf("%s %s\n", even, odd);
            i = 0;
            ii = 0;
            c = EOF;
            s = malloc(128);
    }
    return 0;
}

