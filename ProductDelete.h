#pragma once

class ProductDelete {
private:
	static const int REMOVE = 20;
	static const int BACK = 22;
	int itemIndex;

public:
	void printSrc();
	void setItemIndex(int i);
};
