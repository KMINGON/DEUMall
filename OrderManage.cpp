#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <vector>

#include "screenControl.h"
#include "Dao.h"
#include "OrderManage.h"

using namespace std;

void OrderManage::printSrc()
{
	clrscr();

	print_screen("./screen/orderconfirmed_screen.txt");
	
	vector<OrdersDto> orders = selectOrders();
	OrdersDto order = orders.at(orderIndex);

	gotoxy(34, 10);
	printf("%s", findByItemId(order.item_id).name);

	gotoxy(34, 12);
	printf("%d", order.quantity);

	gotoxy(34, 14);
	printf("%s", findByMemberId(order.member_id).name);

	gotoxy(34, 16);
	printf("%d", order.quantity * findByItemId(order.item_id).price);

	gotoxy(34, 18);
	printf("%s", order.status);

	int y = cursorControl(31, 21, 25, 2);

	

	switch (y) {
		// 디비 연결 후 주문 리스트 클릭 했을 시 넘어가는 화면 구성해야함


	case COMPLETE:
		orderStatus(order.order_id, "확정");
		break;

	case CANCLE:
		orderStatus(order.order_id, "취소");
		break;
	}


}

void OrderManage::setOrderIndex(int i) {
	this->orderIndex = i;
}