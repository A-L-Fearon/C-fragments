#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main(int args, char *arg[]){

	int i,c;
	
	if(args > 1){
		printf("\n");
		for(i=0;i<args;i++){
			for(c=i+1;c<=args;c++){
				if(*arg[i] == *arg[c])
					printf("Argument %d and %d are identical. They both hold %c \n",i, c, *arg[i]);
			}
		}
	printf("\n");
	}else{
		printf("Only One Argument given! \n\n");
	}

}
