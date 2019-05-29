#include "WordLearn.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pch.h"
#pragma warning(disable : 4996)
#pragma warning(disable : 4430)
#define n 30

void Voc(s2 *w) {
	int i, j, g, B[n];

	for (i = 0; i < n; i++) B[i] = i;

	for (i = 1; i < n; i++) {
		g = B[i];
		j = i - 1;
		while (j >= 0 and strcmp(w[g].en, w[B[j]].en) < 0) {
			B[j + 1] = B[j];
			j = j - 1;
		}
		B[j + 1] = g;
	}
	//for (i = 0; i < n; i++) printf("%s - %s\n", w[B[i]].en, w[B[i]].ru);


}
