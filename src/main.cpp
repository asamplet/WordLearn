#include "wordlearn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 30

int main()
{
    struct d w[n];
    int S[n], B[n];
    Wl(w);
    Voc(w, S);
//  Learn(w);
    Voc1(w, B);
//  Learn1(w);

    return 0;
}
