#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DICT_SIZE 45427
#define NOT_FOUND -1 


int main(char args, char *argv[]){

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
		if((dict = fopen(argv[1], "r")) == NULL){
			printf("\n Please enter an input file accessable by the program!");
			exit(1);
		}
		if((dict = fopen(argv[2], "w")) == NULL){
			printf("\n Please enter an output file accessable by the program!");
			exit(1);
		}
		i =0;
		while(fscanf(dict, "%s", dictionary[i]) != EOF){
			i++;
		}
		fclose(dict);
		while(fscanf(input, "%s", word) != EOF){
			len = strlen(word) -1;
			suggNum = 0;
			if(Search(dict, 0, DICT_SIZE -1, word)){
				fprintf(output, "%s\n", word);
			}else{
				while(len >= 0 && suggNum < 10){
					for(i=0; i < len; i++){
						temp[i] = word[i];
					}
					temp[i] = '\0';
					if(Search(dict, 0, DICT_SIZE -1, word) != NOT_FOUND){
						strcpy(suggestion[suggNum], temp);
						suggNum++;
					}
					len --; 
				}
				printf("The word %s was not found. Here are are some suggestions.", word);
				for(i=0;i<suggNum;i++){
					printf("%d %s\n", (i + 1), suggestion[i]);
				}
				printf("Please select the word you originally meant.");
				scanf("%d", &choice);
				fprintf(output,"%s",suggestion[choice-1]);
			}
		}
	}
	return 0;
}

int Search(char dict[][100], int first, int last, char *key){
	int mid;
	mid = ((first + last)/2);
	if(first > last)
		return NOT_FOUND;
	if(strcmp(dict[mid], key) == 0){
		return mid;
	}else if(strcmp(dict[mid], key)){
		return Search(dict, first, mid-1, key);
	}else{
		return Search(dict, mid+1, first, key);
	}

}