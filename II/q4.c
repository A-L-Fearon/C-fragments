#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Phonebook{
	char name[30];
	char address[30];
	int telephone;
};

void getDetails(struct Phonebook contact[]);

void find(struct Phonebook contact[]);

int main(){
	struct Phonebook contacts[10];
	//struct Phonebook contact2;	

	strcpy(contacts[0].name,"John");	
	strcpy(contacts[0].address,"Somewhere, not here");
	contacts[0].telephone = 7654321;

	strcpy(contacts[1].name,"Shelly");	
	strcpy(contacts[1].address,"Over there");
	contacts[1].telephone = 1234567;

	getDetails(contacts);
	find(contacts);
}


void getDetails(struct Phonebook contact[]){
	int i;	
	//printf("%lu\n\n",(sizeof(*contact) / sizeof(struct Phonebook))); //used to find size of array
	for(i=0;i <= sizeof(*contact) / sizeof(struct Phonebook);i++){
		printf("\nContact name: %s\n", contact[i].name);
		printf("Contact Address: %s\n", contact[i].address);
		printf("Contact Number: %d\n\n", contact[i].telephone);
	}
}

void find(struct Phonebook contact[]){
	int i;	
	char name[30];
	printf("Please insert name of contact: ");	
	scanf("%s", name);
	for(i=0;i <= sizeof(*contact) / sizeof(struct Phonebook);i++){
		if(strcmp(contact[i].name,name)==0){
			printf("\nContact name: %s\n", contact[i].name);
			printf("Contact Address: %s\n", contact[i].address);
			printf("Contact Number: %d\n\n", contact[i].telephone);
			break;

		}
	}
	printf("Contact not found");
}
