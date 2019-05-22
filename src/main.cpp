#include "wordlearn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 10

int main()
{
    struct d w[n];
    Wl(w);
    Voc(w);
    Learn(w);
    Voc1(w);
    Learn1(w);

    return 0;
}
