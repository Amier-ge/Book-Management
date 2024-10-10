#include "student.h"
#include<stdio.h>

int main() {

	BOOK book[MAX_BOOK];
	int volume, i;
	int (*func[3])(BOOK *, int * ) = {add_book, find_book_by_ID, print_all_book};
	
	for(i = 0 ; i < 3 ; i++) func[i](book, &volume);

	return 0;
}