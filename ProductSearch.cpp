#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <vector>


#include "screenControl.h"

#include "ProductSearch.h"
#include "ManagerMenu.h"
#include "ProductChange.h"
#include "ProductDelete.h"
#include "Dao.h"

using namespace std;

void ProductSearch::printSrc()
{
	while (1) {
		clrscr();

		print_screen("./screen/inquiryproduct_screen.txt");

		vector<ItemsDto> items = selectItems();	//아이템 리스트 받아옴
		int size = items.size();
		int i = 0;

		for (ItemsDto item : items) {	//리스트 돌면서 하나씩 출력
			gotoxy(20, 11 + i++);
			printf("%s\t%7d 원\t%4d 개", item.name, item.price, item.stock);
		}

		int prodY = cursorControl(19, 11, 11 + (size - 1), 1);	//선택한 아이템의 Y 값 반환

		int itemIndex = prodY - 11;	//아이템 인덱스값 items.at(itemIndex)로 접근하면 선택한 아이템 접근 가능 

		gotoxy(18, prodY);	//선택한 아이템 값에 마킹
		printf("*");


		int y = cursorControl(31, 22, 26, 2);

		switch (y) {

		case CHANGE:
			ProductChange productchange;
			productchange.setItemIndex(itemIndex);
			productchange.printSrc();
			
			break;

		case DELETE:
			ProductDelete productdelete;
			productdelete.setItemIndex(itemIndex);
			productdelete.printSrc();

			break;


		case RETURN:
			return;
		}
	}
}

