#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>


main()
{ 	
	int i, r=0;
  	char c, ch, eng[10], rus[10];
  	FILE *t;
  	system("CLS");
  	t=fopen("file1.txt","r"); 
  
 	i=0;
  	while (!feof(t))
  	{ 	
		ch=getc(t);
		if(r == 0)
			if(ch != '=')
				eng[i]=ch;
			else {
				eng[i]='\0';
				r=1;
				i=0;
				continue;}
		
		if(r == 1){
			if(ch != '.')
				rus[i]=ch;
			else
				rus[i]='\0'; 
		}
		i++;
		
  	}
  	printf("-%s-%s-",eng,rus);
  	getch();
}
