#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>

#include "ShoppingMenu.h"
#include "screenControl.h"
#include "LoginMenu.h"
#include "SingupMenu.h"
#include "MainMenu.h"
#include "Dao.h"

void SingupMenu::printSrc()
{
	clrscr();

	print_screen("./screen/signup_screen.txt");

	char inputId[20];
	char inputPw[20];
	char inputName[20];

	while (1) {
		gotoxy(35, 7);	//ID 입력
		gets_s(inputId);

		MembersDto member = findByMemberId(inputId);

		if (strcmp(member.member_id, inputId) == 0) {
			print_screen("./screen/signup_screen.txt");
			gotoxy(35, 9);
			printf("이미 사용중인 아이디입니다.");
		}
		else {
			gotoxy(35, 9);
			printf("사용 가능한 아이디입니다.  ");
			break;
		}
	}
	
	gotoxy(35, 11);	//PW 입력
	gets_s(inputPw);


	gotoxy(35, 15);	//이름
	gets_s(inputName);

	MembersDto member;
	strcpy(member.member_id, inputId);
	strcpy(member.pw, inputPw);
	strcpy(member.name, inputName);

	int y = cursorControl(34, 20, 22, 2);

	switch (y) {
	case COMPLETE:
		addMember(member);
		LoginMenu loginmenu;
		loginmenu.printSrc();
		break;

	case CANCLE:
		MainMenu mainmenu;
		mainmenu.printSrc();
		break;
	}
}

