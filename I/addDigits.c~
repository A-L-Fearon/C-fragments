#include <stdio.h>
#include <math.h>
#include <string.h>

int main(int arg, char *args[]){
	int num, pow=1, temp, sum=0;
	printf("Please enter a positive integer: ");
	scanf("%d", &num);
	if(num > 1 && num < 11){
	temp = num;
	while(temp){
		temp=temp/10;
		pow*=10;
	}
	
	while(pow>1){
		pow/=10;
		sum +=num/pow;
		num = num % pow;
	}
	printf("The sum of the individual numbers is: %d\n",sum);
	}else{
		printf("Please enter a positive integer with 10 or less digits!\n");
	}
	return 0;
}
