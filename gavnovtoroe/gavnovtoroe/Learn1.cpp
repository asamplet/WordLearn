#include "WordLearn.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pch.h"
#pragma warning(disable : 4996)
#pragma warning(disable : 4430)
#define n 10

void Learn1(s2 *w) {
	int i = 0;
	char wo[15], ex[5] = { "exit" };

	while (i < n) {
		//printf("%s - ", w[i].ru);
		scanf("%s", wo);
		if (strcmp(wo, w[i].en) == 0) i++;
		if (strcmp(wo, ex) == 0) break;
	}
}