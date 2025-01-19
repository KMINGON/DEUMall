#pragma once

class ProductChange {
private:
	static const int COMPLETE = 21;
	static const int BACK = 23;
	int itemIndex;

public:
	void printSrc();
	void setItemIndex(int i);
};
