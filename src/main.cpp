#include "wordlearn.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

