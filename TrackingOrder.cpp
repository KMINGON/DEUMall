#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <vector>

#include "screenControl.h"
#include "TrackingOrder.h"
#include "MainMenu.h"
#include "Dao.h"

using namespace std;

void TrackingOrder::printSrc()
{
	clrscr();

	print_screen("./screen/ordertracking_screen.txt");

	vector<OrdersDto> orders = selectOrder(user.member_id);
	int i = 0;
	for (OrdersDto order : orders) {
		MembersDto member = findByMemberId(order.member_id);
		ItemsDto item = findByItemId(order.item_id);
		gotoxy(10, 11 + i++);
		printf("주문 품목 : %s\t주문 개수 : %d\t주문상태 : %s", item.name, order.quantity, order.status);
	}

	int y = cursorControl(35, 24, 24, 2);

	switch (y) {
	case EXIT:
		break;
	}
}


void TrackingOrder::setUser(MembersDto u) {
	this->user = u;
}
