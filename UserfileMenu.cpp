#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <vector>

#include "screenControl.h"
#include "UserfileMenu.h"
#include "ManagerMenu.h"
#include "Dao.h"

void UserfileMenu::printSrc()
{
	clrscr();

	print_screen("./screen/userfile_screen.txt");
	
	vector<MembersDto> members = selectMembers();
	int i = 0;
	for (MembersDto member : members) {
		gotoxy(23, 10 + i++);
		printf("ID : %10s\tNAME : %s", member.member_id, member.name);
	}
	

	int y = cursorControl(29, 23, 23, 2);

	switch (y) {
	case BACK:
		break;
	}


}

