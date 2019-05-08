#include "wordlearn.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define n 10


int main()
{ 	
	int i, r=0,j=0;
  	char ch, eng[15], rus[15];
  	FILE *t;
  	struct d w[n];
  	t=fopen("file1.txt","r"); 
  
 	i=0;
  	while (!feof(t))
  	{ 	
		ch=getc(t);
		if(i == -1){
			i=0;
			continue;		
		}
		if(r == 0){
			if(ch != '=')
				eng[i]=ch;
			else {
				eng[i]='\0';
				r=1;
				i=0;
				strcpy(w[j].en,eng);
				continue;}
		}
		if(r == 1){
			if(ch != '.')
				rus[i]=ch;
			else {
				rus[i]='\0'; 
				r=0;
				i=-1;
				strcpy(w[j].ru,rus);
				//w[j]=d;
				j++;
				continue;}
		}
		i++;
		
  	}
	
	Voc(w);
	Learn(w);	


	return 0;
}


