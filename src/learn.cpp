#include "wordlearn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 10

void Learn(s2* w)
{
    int i = 0;
    char wo[15], ex[5] = {"exit"};

    while (i < n) {
        printf("%s - ", w[i].en);
        scanf("%s", wo);
        if (strcmp(wo, w[i].ru) == 0)
            i++;
        if (strcmp(wo, ex) == 0)
            break;
    }
}
