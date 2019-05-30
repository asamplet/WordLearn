#include "WordLearn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 30

void Voc1(s2* w, int B[n])
{
    int i, j, g;

    for (i = 0; i < n; i++)
        B[i] = i;

    for (i = 1; i < n; i++) {
        g = B[i];
        j = i - 1;
        while (j >= 0 and strcmp(w[g].ru, w[B[j]].ru) < 0) {
            B[j + 1] = B[j];
            j = j - 1;
        }
        B[j + 1] = g;
    }
    // for (i = 0; i < n; i++)
        // printf("%s - %s\n", w[B[i]].ru, w[B[i]].en);
}
