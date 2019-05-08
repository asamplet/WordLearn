#include "wordlearn.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define n 10

void Learn(s2 *w){
	int i=0,mo;
	char wo[15],ex[5]={"exit"};
	scanf("%d",&mo);
	
	if(mo==1){
	while(i<n){
		printf("%s - ",w[i].en);
		scanf("%s",wo);
		if(strcmp(wo,w[i].ru)==0) i++;
		if(strcmp(wo,ex)==0) break;
	}}
	
	if(mo==2){
	while(i<n){
		printf("%s - ",w[i].ru);
		scanf("%s",wo);
		if(strcmp(wo,w[i].en)==0) i++;
		if(strcmp(wo,ex)==0) break;
	}}
}
