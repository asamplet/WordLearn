#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define n 10

main()
{ 	
	int i, r=0,j=0;
  	char ch, eng[15], rus[15];
  	FILE *t;
  	struct sl{char en[15]; char ru[15];} d;  
  	struct sl w[n];  
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
	printf("%s = %s", w[4].en, w[4].ru);
	printf("123");	
	return 0;
}
