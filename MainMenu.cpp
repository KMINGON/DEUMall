#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#include "screenControl.h"

#include "MainMenu.h"
#include "LoginMenu.h"
#include "SingupMenu.h"

void MainMenu::printSrc()
{
	while (1) {
		clrscr();

		print_screen("./screen/shopping_mall_screen.txt");
		
		int y = cursorControl(34, 20, 24, 2);

		switch (y) {
		case LOGIN:
			LoginMenu loginmenu;
			loginmenu.printSrc();
			break;

		case SIGNUP:
			SingupMenu singupmenu;
			singupmenu.printSrc();
			break;

		case EXIT:
			exit(0);
		}
	}
}
