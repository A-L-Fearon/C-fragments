#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int arg){
	int i, x, len;
	char jumbl[30], temp;
	printf("Please input a string: ");
	scanf("%s", jumbl);
	len = strlen(jumbl);
	//printf("%d \n",len);
	for(x=(len - 1);x > 0;x--){
		for(i=0;i < x; i++){
			if(jumbl[i] > jumbl[x]){
				temp = jumbl[i];	
				printf("%c\n", temp);
				jumbl[i] = jumbl[x];
				jumbl[x] = temp;
			}

		}

	}
	printf("%s\n",jumbl);
}
