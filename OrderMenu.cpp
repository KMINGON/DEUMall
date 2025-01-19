#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <vector>

#include "screenControl.h"
#include "Dao.h"
#include "OrderManage.h"
#include "OrderMenu.h"

using namespace std;



void OrderMenu::printSrc()
{
	while (1) {
		clrscr();

		print_screen("./screen/ordermanagement_screen.txt");

		vector<OrdersDto> orders = selectOrders();

		int i = 0;
		for (OrdersDto order : orders) {
			MembersDto member = findByMemberId(order.member_id);
			ItemsDto item = findByItemId(order.item_id);
			gotoxy(5, 11 + i++);
			printf("주문 품목 : %s\t주문 개수 : %d\t주문자 : %10s\t주문상태 : %s", item.name, order.quantity, member.name, order.status);
		}

		int s = cursorControl(4, 11, 11 + orders.size() - 1, 1);
		gotoxy(3, s);
		printf("*");

		int orderIndex = s - 11;


		int y = cursorControl(31, 23, 25, 2);

		switch (y) {
			// 디비 연결 후 주문 리스트 클릭 했을 시 넘어가는 화면 구성해야함


		case CLICK:
			OrderManage ordermanage;
			ordermanage.setOrderIndex(orderIndex);
			ordermanage.printSrc();
			break;

		case BACK:
			return;
		}
	}

}

