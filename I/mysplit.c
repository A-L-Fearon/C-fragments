#include <stdio.h>
#include <string.h>

int main(int arg){

	char name[50],first[25],last[25], temp[25];
	int i, pos1=0, size;
	printf("Please enter name: ");
	scanf("%s",name);

	size=strlen(name);
	for(i=1; i < size; i++){
		if(isupper(name[i])){
			strncpy(first, name, i);
			strncpy(last, name + i, strlen(name));
			printf("%s %s\n",first,last);
			break;
		}
	}
	printf("\n The first name is: %s and Last name is: %s\n", first, last);
	
	return 0;
}
