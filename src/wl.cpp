#include "wordlearn.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define n 10


//struct d1{char en[15]; char ru[15];} d1;

//typedef struct d s2;

struct d{char en[15]; char ru[15];} d;

//void Learn(d *w);

int main()
{ 	
	int i, r=0,j=0;
  	char ch, eng[15], rus[15];
  	FILE *t;
	printf("123");
  	struct d w[n];
  	t=fopen("file1.txt","r"); 
  
 	i=0;
  	while (!feof(t))
  	{ 	
		ch=getc(t);
		if(r == 0){
			if(ch != '=')
				eng[i]=ch;
			else {
				eng[i]='\0';
				r=1;
				i=0;
				strcpy(d.en,eng);
				continue;}
		}
		if(r == 1){
			if(ch != '.')
				rus[i]=ch;
			else {
				rus[i]='\0'; 
				r=0;
				i=0;
				strcpy(d.ru,rus);
				w[j]=d;
				j++;
				continue;}
		}
		i++;
		
  	}
	
	Voc(w);
	//Learn(w);	


	return 0;
}

/*
void Voc(s2 *w){
	int i,j,g,B[n],mo;
	scanf("%d",&mo);
	
	for (i=0;i<n;i++) B[i]=i;

	
	if(mo==1) {
		for(i=1;i<n;i++){
		g=B[i];
		j=i-1;
		while(j>=0 and strcmp(w[g].en,w[B[j]].en)<0){
			B[j+1]=B[j];
			j=j-1;
		}
		B[j+1]=g;
	}
		for(i=0;i<n;i++) printf("%s - %s",w[B[i]].en,w[B[i]].ru);}
	
	if(mo==2) {
		for(i=1;i<n;i++){
		g=B[i];
		j=i-1;
		while(j>=0 and strcmp(w[g].ru,w[B[j]].ru)<0){
			B[j+1]=B[j];
			j=j-1;
		}
		B[j+1]=g;
	} 
		for(i=0;i<n;i++) printf("%s - %s\n",w[B[i]].ru,w[B[i]].en);}
	
}


void Learn(d *w){
	int i=0,mo;
	char wo[15];
	scanf("%d",&mo);
	
	if(mo==1){
	while(i<n){
		printf("%s\n",w[i].en);
		scanf("%s",wo);
		if(strcmp(wo,w[i].ru)==0) i++;
	}}
	
	if(mo==2){
	while(i<n){
		printf("%s\n",w[i].ru);
		scanf("%s",wo);
		if(strcmp(wo,w[i].en)==0) i++;
	}}
}*/


