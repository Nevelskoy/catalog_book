/*************************************************************
	������������ ������� �3-����-�110. ���������
//������������ ������ ��������
//�����
//����������
//���������� � �����
//������ �� �����
*************************************************************/
#include <iostream>
#include "book.h"
#include "card_index.h"


#define	  stop __asm nop	

//BOOK globalBook;
//BOOK book1 = { "Global", "Book", 2017, 19.99, HISTORY };


void main()
{
#if 0

	//����. ��������� �.	
//������� 1.1 �������� ��������� BOOK, ����������� �����
//(�����, ��������, ��� �������, ����, ����������).
//���������: ������ ���� ����� ���� ���� ���������.
//���������: ���������� ��������� ������������� ��������
//� ������������ ����.

	//������� 1.2. �������� ������� ��������� ���������� (�������) ���� BOOK 

	//a) ���������� ������ ���� BOOK �������� ��� �������������
	
	//�) ������������ ������ ���� BOOK �������� ����� ��� �������������
	BOOK* dynamicBook = new BOOK;
	//�) ��������� ������ ���� BOOK �������� ��� �������������, �� ������� ��������� ������� ���� ��������� ���������� ����������
	BOOK localBook;	
	strcpy_s(localBook.author, "Bjarne Stroustrup");
	strcpy_s(localBook.title, "The C++ Programming Language");
	localBook.category = PROGRAMMING;
	localBook.year = 1986;
	localBook.price = 10.55;

	//�) ����������� ������ ���� BOOK ��������  � ������������������ ��� ����������� � ������� ������ �������������.
	// 
	//static BOOK staticBook = { "Robert Martin", "Clean Architecture", 2017, 19.99, "Programming" };

	//����������� ��������� BOOK, ��������� � ���������� �������.
	//��� ����� ���������� ���������� � ���������� � ������� ����� book.h � book.cpp
	//���������� - ������� ������ ������� ���������� ��� ������ ����� ������. 
	//���������: �� ���� ������� ����� ���������� ������?
	// 
	// 
// (50+50+4+8+4), �������� ������ ���������� ������ ������� �� ����������� � ������������ 
	
	/*������� 1.3.1 �������� �������, ��������� �� ����� ��������� �����. 
	�������� ������� ��������� � ���� "book.h", � ���������� - � "book.cpp"
	���������: ��� ����������� ���������� ��������� BOOK � �������.
	��� ������ �� ������� ����������� ������� ����������� ���������� printf*/
	std::cout << "Global BOOK" << std::endl;
	printInfo(&book1);
	std::cout << std::endl;
	//������� 1.3.2
	//� ������� ������������� ������� �������� �� ������� ���������� � ������, ��������� � �.1.2 (����� ������������)
	std::cout << "Local BOOK" << std::endl;
	printInfo(&localBook);
	std::cout << std::endl;
	//������� 1.4.1 �������� ������� ��� ������������ ����� ���������.
	//�������� ������� ��������� � ���� "book.h", � ���������� - � "book.cpp"
	//��� ����� ����������� ������� ����������� ���������� scanf

	//���������: ������� �������� � ����� ������� ����������� ��������
	//������������ ���������� ��������, ��������, ��� ������� �� ����� ����
	//������, ���... (��� ��������� ������������), ��������� ������������
	//������ �������� �� ������������, ���� �� ����� ���� �������������...
	inputBook(&globalBook);
	//������� 1.4.2
	//����������� ������������� ������� ��� ���������� ����� ����������� ���������� ���������� ����� 
	//������������ ���������� ���� ����� � ������� �������, �������� � �.1.3.1 
	//
	std::cout << "NEW BOOK" << std::endl;
	printInfo(&globalBook);
	std::cout << std::endl;

#endif
//----------------------------------------------------------------------------------------------------------------
	//������� 2.1 ������� "���������".
	
	//������������ ������ ����� ����������� �� ������ ������� ���������
	//������ �������� � ���������� => ����� ����� ����������� ���
	//������������: ��� ����� ��������� ��� ����� "����" (��������
	//��������� �������� � ��������������� ������� ������������), ��������:
	//����������� ���������� ��������� (1)
	//������ ����� ����� (2)
	//������� ������������(��) (3)
	//...
	//����� �� ��������� (...)

	//"���������" - ��� ������ �������� => ����� ����� ������ �������.
	//���������: ������ ������� �������� ������������� ���� ���������� ���� => ����� ������ ���� ����� ������???	

	//������ ������ ������� ����������� ������� ������������� ������� �������� ���������� ���� � ������� ����� �������,
	//��� ��� ��� �������� ����� ���������� � �������� ������
	//��������� ��� ��������� ��������� �������, ����� ����� ���������� �� � ���������, ��������, CARD_INDEX
	// ��������� ��������� � ������ ��� ���������� ������� � �����  "���������_2021.pdf"

	//���������� ����������� ������� ������ ����������� ������ � ����������
	
	// ���������:
	//1. ����� ����� � �������� ����� ������� �� ������ �����
	//2. ��� ������ ����� �������� ���������� �������. 
	//   ��� ������ ������� �������� ��������� ���������� ���������  -	setlocale(LC_CTYPE, ".1251");
	//   (������������ ���� <clocale>)
	//   ���� ������� �� ������ ��������, �� � ������� ������� �������, �������
	//   �) ������������ ������������ ��������� �����/������ - wprintf(), wscanf()
	//   �) ������� ������ ��� ����������� - wchar_t
	//   �) ���������� ��������� ��� ����� ������� �������� - setlocale(LC_CTYPE, ".866");

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



//----------------------------------------------------------------------------------------------------------------
	//������� 2.2 (*) ������������ "���������".	

	//�������� ������� ���������� ��������� � ���� (4)
	//������� �� ����� ���������� � ��������� (5)

	//���������1:	��� ��������� �����/������ ����������� ������� fprintf � fscanf
	//				(������������ ���� <cstdio>


	// ���������2: ������ � �������� ������� ������� � ����� ������� ����������
	//			   ���� � ���������

	// ���������3:  ��� ������ �� ����� ����� ������������ ��������� ��������:
	//				���� ���� ���������� � ��� ������� �������:
	//if()
	//{
	//������ ������ �� �����
	//�) ������� ���������� ���������
	//�) ������� ������ ��������� �����������
	//�) ������� ������ �� ����� � ������
	//}

	//----------------------------------------------------------------------------------------------------------------
	//������� 3 (*). ������������ ������������ ����������� �������� �������� ����
	//� ������������ ������� => �������� ������� (�������) ���������� �������
	//�� ������ �� ����� ���������.
	// �� (!!!) ����������� ������� sort  �� 2-�� ������������ ������, � �������� 
	//�������  ���������� ����  (����  selection, ���� �����������)

	//���������: ������� - "�� ������ ���� ���������" ����� ������ � �������
	//������������.


//��� ���������� ��������� ��������� �������� ������������ ������. �� �������� ��� �������
//*********************   �������������� �������   ****************************************************
//������� 4 (*)  
// ��������� ������� 9 �� �������� ������ 
// �������� ������� ��������� � ����� "������� (���� ������)_9 (���������)_3.docx" 
//*****************************************************************************************************
}