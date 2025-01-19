#pragma once

class OrderManage {
private:
	static const int COMPLETE = 21;
	static const int CANCLE = 23;
	int orderIndex;
public:
	void printSrc();
	void setOrderIndex(int i);
};
