#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <vector>
#include <iostream>


#include "screenControl.h"

#include "ProductChange.h"
#include "ManagerMenu.h"
#include "Dao.h"

using namespace std;

void ProductChange::printSrc()
{
	clrscr();

	print_screen("./screen/productchange_screen.txt");

	vector<ItemsDto> items = selectItems();
	ItemsDto item = items.at(itemIndex);

	gotoxy(13, 10);
	printf("%s", item.name);
	gotoxy(13, 12);
	printf("%d", item.price);
	gotoxy(13, 14);
	printf("%s", item.description);
	gotoxy(13, 16);
	printf("%d", item.stock);
	
	gotoxy(47, 10);
	gets_s(item.name);

	gotoxy(47, 12);
	scanf("%d", &item.price);
	getchar();

	gotoxy(47, 14);
	gets_s(item.description);

	gotoxy(47, 16);
	scanf("%d", &item.stock);
	getchar();

	int y = cursorControl(35, 21, 23, 2);

	switch (y) {
		// 디비 연결 후 상품 리스트 클릭 시 상품 변경 및 삭제 화면 구성해야함
	case COMPLETE:
		updateItem(item.item_id, item);
		break;

	case BACK:
		break;
	}


}

void ProductChange::setItemIndex(int i) {
	this->itemIndex = i;
}
