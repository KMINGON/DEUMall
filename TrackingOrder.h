#pragma once
#include "Dao.h"

class TrackingOrder {
private:
	static const int EXIT = 23;
	MembersDto user;

public:
	void printSrc();
	void setUser(MembersDto u);
};
