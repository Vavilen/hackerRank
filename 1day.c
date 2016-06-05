#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int i = 4;
    double d = 4.0;
    char s[] = "HackerRank ";

    unsigned int len_max = 128;
    unsigned int current_size = 0;

    int ii;
    double dd;
    char *ss = malloc(len_max);
    current_size = len_max;

    scanf("%d\n", &ii);
    scanf("%lf\n", &dd);
    int c = EOF;
    unsigned int id = 0;
        while((( c = fgetc(stdin) ) != '\n' || id == 0) && c != EOF)
    {
        ss[id++] = (char)c;
        if (id == current_size)
        {
            current_size = id+len_max;
            ss = realloc(ss, current_size);
        }
    }

    printf("%d\n", i + ii);
    printf("%.1lf\n", (d + dd));
    printf("%s%s", s, ss);
    free(ss);
}
