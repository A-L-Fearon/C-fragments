#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DICT_SIZE 45427
#define NOT_FOUND -1 

char *NewToUpper(char *string);
int main(char args, char *argv[]){
									//TODO Remove personal comments before cubmitting to sir.
	FILE *dict, *input, *output;
	int i, len, suggNum, choice;
	char dictionary[DICT_SIZE][183], word[183], temp[183], suggestion[10][183];

	if(args != 3){
		printf("Nah Bro \n Please use format: SpellCheck inputfile outputfile \n");
	}else{
		const char *filename = "linux.words";
		if((dict = fopen(filename, "r")) == NULL){
			printf("\n Please place dictionary file in folder so program can find it!");
			exit(1);
		}
		if((input = fopen(argv[1], "r")) == NULL){
			printf("\n Please enter an input file accessable by the program!");
			exit(1);
		}
		if((output = fopen(argv[2], "w")) == NULL){ //not necessary as the file will be created if not present.. but I want the check.. for reasons.. 
			printf("\n Please enter an output file accessable by the program!");
			exit(1);
		}
		i =0;
		while(fscanf(dict, "%s", dictionary[i]) != EOF){
			i++;
			//printf("hi no errors yet");
		}
		fclose(dict);
		
		while(fscanf(input, "%s", word) != EOF){
			len = strlen(word);
			//printf("then len %d\n", len);
			suggNum = 0;
			//printf("Debug time \n");
			if(Search(dictionary, 0, DICT_SIZE -1, word) != NOT_FOUND){
				fprintf(output, "%s \n", word);
				//printf("%s    %d \n", word, Search(dictionary, 0, DICT_SIZE -1, word));
			}else{
				//printf("Debug timeasss \n");
				while(len >= 0 && suggNum < 10){
					//printf("Debug time \n");
					//printf(" len len %d\n", len);
					for(i=0; i < len; i++){
						//printf("Temp");
						temp[i] = word[i];
					}
					temp[i] = '\0';
					if(Search(dictionary, 0, DICT_SIZE -1, temp) != NOT_FOUND){
						strcpy(suggestion[suggNum], temp);
						suggNum++;
					}
					len --; 
				}
				if(suggNum != 0){
					printf("The word %s was not found. Here are are some suggestions: \n", word);
					for(i=0;i<suggNum;i++){
						printf("%d| %s\n", (i + 1), suggestion[i]);
					}
					printf("Please select the word you originally meant:");
					scanf("%d", &choice);
					fprintf(output,"%s \n",suggestion[choice-1]);
				}else{
					printf("Nothing even close Exits. (I suggest Buying a dictionary and studying it)\n");
				}
				
			}
		}
	}
	printf("Successful Completion. Please Grade Generously! :) \n");
	return 0;
}

int Search(char diction[][183], int first, int last, char *key){
	int mid;
	//printf("no \n");
	if(first > last)
		return NOT_FOUND;
	mid = last + ((first - last)/2);
	if(strcmp(NewToUpper(diction[mid]), NewToUpper(key)) == 0){
		//printf("1st[%s]-[%s]\n", NewToUpper(diction[mid]), NewToUpper(key));
		return mid;
	}else if(strcmp(NewToUpper(diction[mid]), NewToUpper(key)) > 0){ // problem was here 
		//printf("2nd[%s]-[%s]\n", NewToUpper(diction[mid]), NewToUpper(key));
		return Search(diction, first, mid-1, key);
	}else{
		//printf("3rd[%s]-[%s]\n", NewToUpper(diction[mid]), NewToUpper(key));
		return Search(diction, mid+1, last, key);
	}

}



char *NewToUpper(char *string){ //created to change to upper case as som words in ditctionary had mixed
	int i;
	char *temp = malloc(strlen(string));
	for(i = 0; i < strlen(string); i++)
		temp[i] = toupper(string[i]);
	temp[i] = '\0';
	return temp;
}
