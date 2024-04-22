#include <iostream>
#include "book.h"
#include "card_index.h"


#define	  stop __asm nop	

//BOOK globalBook;
//BOOK book1 = { "Global", "Book", 2017, 19.99, HISTORY };


void main()
{
#if 0

	//Тема. Структуры С.	


	//Задание 1.2. Создайте разными способами экземпляры (объекты) типа BOOK 

	//a) глобальный объект типа BOOK создайте без инициализации
	
	//б) динамический объект типа BOOK создайте также без инициализации
	BOOK* dynamicBook = new BOOK;
	//в) локальный объект типа BOOK создайте без инициализации, но позднее заполните вручную поля структуры некоторыми значениями
	BOOK localBook;	
	strcpy_s(localBook.author, "Bjarne Stroustrup");
	strcpy_s(localBook.title, "The C++ Programming Language");
	localBook.category = PROGRAMMING;
	localBook.year = 1986;
	localBook.price = 10.55;

	//г) статический объект типа BOOK создайте  и проинициализируйте при определении с помощью списка инициализации.
	// 
	//static BOOK staticBook = { "Robert Martin", "Clean Architecture", 2017, 19.99, "Programming" };

	//Используйте структуру BOOK, созданную в предыдущем задании.
	//Для этого достаточно переписать и подключить к проекту файлы book.h и book.cpp
	//Определите - сколько памяти отводит компилятор под каждый такой объект. 
	//Подумайте: от чего зависит объем выделяемой памяти?
	// 
	// 
// (50+50+4+8+4), итоговый размер занимаемой памяти зависит от компилятора и архитектруры 
	
	/*Задание 1.3.1 Напишите функцию, выводящую на экран реквизиты книги. 
	Прототип функции поместите в файл "book.h", а реализацию - в "book.cpp"
	Подумайте: как эффективнее передавать экземпляр BOOK в функцию.
	Для вывода на консоль используйте функцию стандартной библиотеки printf*/
	std::cout << "Global BOOK" << std::endl;
	printInfo(&book1);
	std::cout << std::endl;
	//Задание 1.3.2
	//С помощью разработанной функции выведите на консоль информацию о книгах, созданных в п.1.2 (кроме динамической)
	std::cout << "Local BOOK" << std::endl;
	printInfo(&localBook);
	std::cout << std::endl;
	//Задание 1.4.1 Напишите функцию для формирования полей структуры.
	//Прототип функции поместите в файл "book.h", а реализацию - в "book.cpp"
	//Для ввода используйте функцию стандартной библиотеки scanf

	//Замечание: неплохо заложить в такую функцию возможность проверки
	//корректности введенного значения, например, год издания не может быть
	//меньше, чем... (год появления письменности), категорию пользователь
	//должен выбирать из существующих, цена не может быть отрицательной...
	inputBook(&globalBook);
	//Задание 1.4.2
	//Используйте разработанную функцию для заполнения полей динамически созданного экземпляра книги 
	//распечатайте содержимое этой книги с помощью функции, соданной в п.1.3.1 
	//
	std::cout << "NEW BOOK" << std::endl;
	printInfo(&globalBook);
	std::cout << std::endl;

#endif
//----------------------------------------------------------------------------------------------------------------

	//Реализуйте посредством функций разные возможности работы с картотекой
	


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
