#include <iostream>
#include <conio.h>
#include "book.h"
#include "card_index.h"


int menu() {
	int cmd = 0;
    printf("----------------MENU------------------\n");
	printf("1 - View the book catalog.\n");
	printf("2 - Enter a new book.\n");
	printf("3 - Delete a book.\n");
	printf("0 - Exit.\n");
    printf("--------------------------------------\n");
	scanf_s("%d", &cmd);
	return cmd;
}

// Насколько корректно не указывать struct в определении?
void printCatalog(const CARD_INDEX* catalog) {
    if (catalog->count != 0) {
        for (size_t i = 0; i < catalog->count; i++) {
            std::cout << "Book " << i + 1 << " --- " << "(" \
                << "Author: " << catalog->pB[i]->author << ", " \
                << "Title: " << catalog->pB[i]->title << ", " \
                << "Year: " << catalog->pB[i]->year << ", " \
                << "Price: " << catalog->pB[i]->price << ", " \
                << "Category: ";
            switch (catalog->pB[i]->category) {
            case FICTION:
                printf("FICTION");
                break;
            case MYSTERY:
                printf("MYSTERY");
                break;
            case BIOGRAPHY:
                printf("BIOGRAPHY");
                break;
            case PROGRAMMING:
                printf("PROGRAMMING");
                break;
            case HISTORY:
                printf("HISTORY");
                break;
            default:
                printf("OTHER");
            }
            std::cout << ")" << std::endl;
        }
    }
    else {
        printf("The catalog is empty!");
    }

    printf("\nPress any key to return to the menu\n");
    _getch();
}


void clearCARD(CARD_INDEX* catalog) {

    for (size_t i = 0; i < catalog->count; i++)
    {
        delete catalog->pB[i];
    }
    delete[] catalog->pB;
    catalog->pB = nullptr;
}