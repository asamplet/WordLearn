#include "wordlearn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 30

void Wl(s2* w)
{
    int i, r = 0, j = 0;
    char ch, eng[15], rus[15];
    FILE* t;
    t = fopen("file1.txt", "r");

    i = 0;
    while (!feof(t)) {
        ch = getc(t);
        if (i == -1) {
            i = 0;
            continue;
        }
        if (r == 0) {
            if (ch != '=')
                eng[i] = ch;
            else {
                eng[i] = '\0';
                r = 1;
                i = 0;
                strcpy(w[j].en, eng);
                continue;
            }
        }
        if (r == 1) {
            if (ch != '.')
                rus[i] = ch;
            else {
                rus[i] = '\0';
                r = 0;
                i = -1;
                strcpy(w[j].ru, rus);
                // w[j]=d;
                j++;
                continue;
            }
        }
        i++;
    }
    fclose(t);
}
