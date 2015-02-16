#include <stdio.h>
#include <math.h>
#include <string.h>

int main(int args, char *arg[]){
	int aclen, var1, var2, i = 0; 
	char *ptr;
	int ans;
	if(args != 3){
		printf("PLease enter 2 numbers! \n");
	
	}else{
		
		var1 = strtol(arg[1], &ptr, 10);
		var2 = strtol(arg[2], &ptr, 10);
		if(var1 > var2){
			ans = var1 / var2;
			printf("%d divided by %d is equal to: %d\n", var1, var2, ans);
		}else{
			printf("Pleas dont try to divide by a larger denominator! \n");
		}
	}

	printf("The number of arguments are: %d\n", args);
	printf("The arguments were: \n");
	for(i = 0; i < args; i++){
		printf("%d. %s\n",i, arg[i]);
	}
	return 0;
}
