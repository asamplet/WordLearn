#include "wordlearn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 30

void Voc(s2* w, int S[n])
{
    int i, j, g;

    for (i = 0; i < n; i++)
        S[i] = i;

    for (i = 1; i < n; i++) {
        g = S[i];
        j = i - 1;
        while (j >= 0 and strcmp(w[g].en, w[S[j]].en) < 0) {
            S[j + 1] = S[j];
            j = j - 1;
        }
        S[j + 1] = g;
    }
    for (i = 0; i < n; i++)
        printf("%s - %s\n", w[S[i]].en, w[S[i]].ru);
/*    for (i = 0; i < n; i++)
	printf("%d ", S[i]);
*/
}
