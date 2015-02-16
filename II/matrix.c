#include <stdio.h>
#include <math.h>

int main(int arg){
	int i, j, q, result=0, rownum=0,colnum=0;
	//float a[2][3], b[3][2], c[2][2];

	float a[2][3] = {
		{1,2,3},
		{4,5,6}
	};

	float b[3][2] = {
		{1,2},
		{4,5},
		{7,8}
	};
	
	float c[2][2];

	for(i=0; i < 2;i++){
		colnum = 0;
		for(j=0;j < 2; j++){
			result = 0;
			for(q=0; q < 3; q++){ 
				result += (a[i][j] * b[i][q]);
			}
			c[rownum][colnum] = result;
			colnum++;
		}
		rownum++;
	}
	
	for(i=0;i < 2; i++){
		for(q=0; q < 2; q++){
			printf("c[%d][%d] = %f\n", i, q, c[i][q]);
		}
	}

}
