#pragma once
#include "pch.h"

#include "Motor.h"
#include <string>

using namespace std;

class Slot
{
protected:
	string productName;
	int id;
	int numProducts;
	int price;
	Motor *motor1;
	Motor *motor2;
public:
	Slot();
	Slot(int slotId, string productName, int price, int motor1Id, int motor2Id);

	~Slot();
	virtual void drop()=0;
	string getProductsName() {
		return this->productName;
	};
	void setProductsName(string productname) {
		this->productName = productname;
	};
	int getNumProducts() {
		return this->numProducts;
	};
	void setNumProducts(int numProducts) {
		this->numProducts += numProducts;
	}
	int getPrice() {
		return this->price;
	};
	void setPrice(int price) {
		this->price = price;
	};
	int getId();

};
