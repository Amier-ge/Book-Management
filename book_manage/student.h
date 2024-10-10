#ifndef _STUDENT_H
#define _STUDENT_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>

#define MAX_TITLE_LEN 100
#define MAX_AUTHOR_LEN 20
#define MAX_BOOK 20

typedef struct _BOOK{

	int ID;
	char title[MAX_TITLE_LEN];
	char author[MAX_AUTHOR_LEN];
	double price;

}BOOK;

int add_book(BOOK * , int * );
int find_book_by_ID(BOOK * , int * );
int print_all_book(BOOK * , int * );
int Yes_or_No(char *);

#endif