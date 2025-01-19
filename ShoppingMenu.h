#pragma once
#include "Dao.h"

class ShoppingMenu {
private:
	static const int  SEARCH = 22;
	static const int  VIEW = 24;
	static const int BACK = 26;
	MembersDto user;
public:
	void printSrc();
	void setUser(MembersDto u);
};
