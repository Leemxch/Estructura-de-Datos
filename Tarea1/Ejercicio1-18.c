#include <stdio.h>
void main(void) {
	char c;
	int word=0, blank=0, tab=0;
	while ((c = getchar()) != EOF) {
       		if (c == ' ' || c == '\t') {
			if (c==' '){
            			blank++;
			}
			else{
				tab++;
			}
		}			
		else {
			if(c=='\n'){
			    if (word == 1){
				    putchar('\n');
			    }
				word=0;
				tab=0;
				blank=0;
			}
			else{
				word=1;
				if (blank != 0 || tab!=0){
					for (int i=0; i<blank-1;i++){
						putchar(' ');
					}
					for (int ii=0; ii<tab;ii++){
						putchar('\t');
					}
					tab=0;
					blank=0;
				}
				putchar(c);
			}
        }
    }
}
