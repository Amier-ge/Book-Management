#include "student.h"

int Yes_or_No(char *YN, char *check) {

	int i = 0;

	while( *(YN + i) ){
		if( (YN[i] >= 'a') && (YN[i] <= 'z') ) YN[i] -= 32;
		i++;
	}

	strcpy(check, YN);

	if( strcmp(check, "NO") == 0 ) return 0;
	else if( strcmp(check, "YES") == 0 ) return 1;
	else {
		printf("Wrong Answer!\n");
		return 2;
	}
}

int add_book(BOOK *book, int *volume) {

	int gostop = 1, index = 0, count = 1;
	char YN[80];
	char *check;

	while(gostop){

		printf("INPUT BOOK ID : ");
		scanf("%d", &book[index].ID);

		printf("INPUT BOOK NAME : ");
		scanf("%s", book[index].title);

		printf("INPUT AUTHOR : ");
		scanf("%s", book[index].author);

		printf("INPUT PRICE : ");
		scanf("%lf", &book[index].price);

		do {
			printf("\nMORE ADD? (Yes or No) : ");
			scanf("%s", YN);

			if(count == 1) check = (char *)malloc( sizeof(YN) + 1 );
			else check = (char *)realloc(check, sizeof(YN) + 1 );

			if(check == NULL) {
				printf("LINE 41/42, malloc memory Error\n");
				return 0;
			}

			gostop = Yes_or_No(YN, check);
			count++;
		} while (gostop == 2);

		*volume = ++index;
		if(index > MAX_BOOK) break;

		printf("\n");
	}

	printf("--------------------------------\n\n");

	return 1;
}

int find_book_by_ID(BOOK *book, int *volume) {

	int i, find_ID, gostop = 1;
	char *check, count = 1;
	char YN[80];

	system("cls");

	while(gostop) {

		printf("Input Book ID to Find : ");
		scanf("%d", &find_ID);

		for(i = 0 ; i < *volume ; i++){

			if(find_ID == book[i].ID) {
				printf("\nBook : %s\n", book[i].title);
				printf("Author : %s\n", book[i].author);
				printf("Price : %.1lf$\n", book[i].price);
			}

			else if(i == *volume) printf("Non-existent Book\n");
		}

		do {
			printf("\nDo You Want To Find More? (Yes or No) : ");
			scanf("%s", YN);

			if(count == 1) check = (char *)malloc( sizeof(YN) + 1 );
			else check = (char *)realloc(check, sizeof(YN) + 1 );

			if(check == NULL) {
				printf("LINE 88/89, malloc memory Error\n");
				return 0;
			}

			gostop = Yes_or_No(YN, check);
			count++;
		} while(gostop == 2);

		printf("\n");
	}
	printf("--------------------------------\n\n");
	
	return 1;
}

int print_all_book(BOOK *book, int *volume) {

	int i;

	system("cls");

	for(i = 0 ; i < *volume ; i++) {

		printf("<<%s(%d), %s>>\n", book[i].title, book[i].ID, book[i].author);
		printf("%.1lf$\n\n", book[i].price);
	}

	return 0;
}