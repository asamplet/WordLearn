#include "WordLearn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 30

void Learn1(s2* w)
{
    int i = 0;
    char wo[15], ex[5] = {"exit"};

    while (i < n) {
        printf("%s - ", w[i].ru);
        scanf("%s", wo);
        if (strcmp(wo, w[i].en) == 0)
            i++;
        if (strcmp(wo, ex) == 0)
            break;
    }
}
