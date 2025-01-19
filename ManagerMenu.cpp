#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#include "screenControl.h"
#include "MainMenu.h"
#include "AddMenu.h"
#include "ManagerMenu.h"
#include "ProductSearch.h"
#include "UserfileMenu.h"
#include "SaleMenu.h"
#include "OrderMenu.h"
void ManagerMenu::printSrc()
{
	while (1) {
		clrscr();

		print_screen("./screen/manager_screen.txt");

	
		int y = cursorControl(33, 9, 19, 2);

		switch (y) {
		case P_ADD:
			AddMenu addmenu;
			addmenu.printSrc();
			break;

		case P_SEARCH:
			ProductSearch productsearch;
			productsearch.printSrc();
			break;

		case USERS:
			UserfileMenu userfilemenu;
			userfilemenu.printSrc();
			break;

		case SALE:
			SaleMenu salemenu;
			salemenu.printSrc();
			break;

		case ORDER:
			OrderMenu ordermenu;
			ordermenu.printSrc();
			break;

		case FIRST:
			MainMenu mainmenu;
			mainmenu.printSrc();
		}
	}
}
