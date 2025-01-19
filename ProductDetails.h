#pragma once
#include "Dao.h"

class ProductDetails {
private:
	static const int BUY = 24;
	static const int BACK = 26;
	int index;
	MembersDto user;
public:
	void printSrc();
	void setIndex(int i);
	void setUser(MembersDto u);
};
