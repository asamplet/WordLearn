#include "wordlearn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 10

void Voc(s2* w)
{
    int i, j, g, B[n];

    for (i = 0; i < n; i++)
        B[i] = i;

    for (i = 1; i < n; i++) {
        g = B[i];
        j = i - 1;
        while (j >= 0 and strcmp(w[g].en, w[B[j]].en) < 0) {
            B[j + 1] = B[j];
            j = j - 1;
        }
        B[j + 1] = g;
    }
    for (i = 0; i < n; i++)
        printf("%s - %s\n", w[B[i]].en, w[B[i]].ru);
}
