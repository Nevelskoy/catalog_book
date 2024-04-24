#include <iostream>
#include "book.h"
#include "card_index.h"


#define	  stop __asm nop	

//BOOK globalBook;
//BOOK book1 = { "Global", "Book", 2017, 19.99, HISTORY };


void main()
{
#if 0
	BOOK* dynamicBook = new BOOK;	
	BOOK localBook;	
	strcpy_s(localBook.author, "Bjarne Stroustrup");
	strcpy_s(localBook.title, "The C++ Programming Language");
	localBook.category = PROGRAMMING;
	localBook.year = 1986;
	localBook.price = 10.55;

	
	//static BOOK staticBook = { "Robert Martin", "Clean Architecture", 2017, 19.99, "Programming" };


	inputBook(&globalBook);
	
	std::cout << "NEW BOOK" << std::endl;
	printInfo(&globalBook);
	std::cout << std::endl;

#endif
//----------------------------------------------------------------------------------------------------------------

	int count = 0;
	int capacity = 5;
	
	CARD_INDEX* newCatalog = new CARD_INDEX;
	newCatalog->pB = new BOOK * [capacity];
	newCatalog->count = 0;
	newCatalog->capacity = capacity;

	int cmd;
	do {
		system("cls");
		switch (cmd = menu()) {
		case 1:
			printCatalog(newCatalog);
 			break;
		case 2:
			addBook(newCatalog);
			break;
		case 3:
			exportCatalog(newCatalog);
			break;
		case 4:
			importCatalog(newCatalog);
			break;
		case 5:
			deleteBook(newCatalog);
			break;
		default:
			printf("Invalid input. Let's try again!\n");
		}

	} while (cmd);

	clearCARD(newCatalog);
