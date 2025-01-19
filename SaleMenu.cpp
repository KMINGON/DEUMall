#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <vector>

#include "screenControl.h"

#include "SaleMenu.h"
#include "ManagerMenu.h"
#include "Dao.h"

using namespace std;

void SaleMenu::printSrc()
{
	clrscr();

	print_screen("./screen/sales_screen.txt");

	vector<OrdersDto> orders = selectOrders();
	int sale = 0;
	for (OrdersDto order : orders) {
		ItemsDto item = findByItemId(order.item_id);
		if (strcmp(order.status, "»Æ¡§") == 0) {
			sale += order.quantity * item.price;
		}
	}

	gotoxy(28, 14);
	printf("√— ∏≈√‚ : %d", sale);

	int y = cursorControl(29, 23, 23, 2);

	switch (y) {
	case BACK:
		break;

	}


}

