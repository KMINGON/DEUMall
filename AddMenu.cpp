#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>

#include "AddMenu.h"
#include "screenControl.h"
#include "Dao.h"

using namespace std;

void AddMenu::printSrc()
{
	clrscr();

	print_screen("./screen/addproduct_screen.txt");

	char name[20];
	int price;
	char description[250];
	int stock;

	gotoxy(29, 9);
	gets_s(name);

	gotoxy(29, 11);
	scanf("%d", &price);
	getchar();

	gotoxy(29, 13);
	gets_s(description);

	gotoxy(29, 15);
	scanf("%d", &stock);
	getchar();

	int y = cursorControl(35, 21, 23, 2);

	ItemsDto item;
	strcpy(item.name, name);
	strcpy(item.description, description);
	item.price = price;
	item.stock = stock;

	switch (y) {
		// 상품명 가격 설명 개수 입력받아 디비로 넘겨줘야함
		// 뒤로가기 버튼 생성 필요 요망
	case COMPLETE:
		addItem(item);
		break;
	case BACK:
		break;
	}
}
