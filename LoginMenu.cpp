#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>

#include "ShoppingMenu.h"
#include "screenControl.h"
#include "MainMenu.h"
#include "LoginMenu.h"
#include "SingupMenu.h"
#include "Dao.h"
#include "ManagerMenu.h"


void LoginMenu::printSrc()
{
	while (1) {
		clrscr();

		print_screen("./screen/login_screen.txt");

		char id[20];
		char pw[20];

		gotoxy(35, 8);
		gets_s(id);

		gotoxy(35, 10);
		gets_s(pw);

		int y = cursorControl(34, 18, 20, 2);

		switch (y) {

		case SINGIN:
			if (strcmp(pw, (findByMemberId(id)).pw) == 0) {
				if (strcmp(id, "admin") == 0) {
					ManagerMenu managerMenu;
					managerMenu.printSrc();
					break;
				}
				ShoppingMenu shoppingmenu;
				shoppingmenu.setUser(findByMemberId(id));
				shoppingmenu.printSrc();
				break;
			}
			break;

		case BACK:
			return;
		}
	}
}
