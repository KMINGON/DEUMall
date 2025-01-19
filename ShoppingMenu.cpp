#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <vector>

#include "ManagerMenu.h"
#include "ShoppingMenu.h"
#include "screenControl.h"
#include "LoginMenu.h"
#include "Dao.h"
#include "ProductDetails.h"
#include "TrackingOrder.h"

void ShoppingMenu::printSrc()
{
	while (1) {
		clrscr();

		print_screen("./screen/order_screen.txt");

		vector<ItemsDto> items = selectItems();	//아이템 리스트 받아옴
		int size = items.size();
		int i = 0;

		for (ItemsDto item : items) {	//리스트 돌면서 하나씩 출력
			gotoxy(19, 10 + i++);
			printf("%s\t%7d 원\t%4d 개", item.name, item.price, item.stock);
		}

		int prodY = cursorControl(18, 10, 10 + (size - 1), 1);	//선택한 아이템의 Y 값 반환

		int itemIndex = prodY - 10;	//아이템 인덱스값 items.at(itemIndex)로 접근하면 선택한 아이템 접근 가능 

		gotoxy(17, prodY);	//선택한 아이템 값에 마킹
		printf("*");

		int y = cursorControl(19, 22, 26, 2);

		switch (y) {
		case SEARCH:
			ProductDetails p;
			p.setIndex(itemIndex);
			p.setUser(this->user);
			p.printSrc();
			break;


		case VIEW:
			TrackingOrder t;
			t.setUser(user);
			t.printSrc();
			break;

		case BACK:
			return;
		}
	}

}


void ShoppingMenu::setUser(MembersDto u) {
	this->user = u;
}

