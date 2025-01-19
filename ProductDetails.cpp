#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <vector>

#include "screenControl.h"

#include "ProductDetails.h"
#include "ManagerMenu.h"
#include "TrackingOrder.h"
#include "Dao.h"

void ProductDetails::printSrc()
{
	clrscr();

	print_screen("./screen/productdetails_screen.txt");

	vector<ItemsDto> items = selectItems();
	ItemsDto item = items.at(index);

	

	gotoxy(16, 9);
	printf("%s", item.name);

	gotoxy(16, 11);
	printf("%d", item.price);

	gotoxy(16, 13);
	printf("%s", item.description);

	gotoxy(16, 15);
	printf("%d", item.stock);

	int quantity;
	gotoxy(42, 22);
	scanf("%d", &quantity);
	getchar();

	int y = cursorControl(29, 24, 26, 2);

	OrdersDto order;
	order.item_id = item.item_id;
	strcpy(order.member_id, user.member_id);
	order.quantity = quantity;
	strcpy(order.status, "´ë±â");

	switch (y) {

	case BUY:
		item.stock -= quantity;
		updateItem(item.item_id, item);
		adddorder(order);
		break;

	case BACK:

		break;
	}


}

void ProductDetails::setIndex(int i) {
	this->index = i;
}


void ProductDetails::setUser(MembersDto u) {
	this->user = u;
}