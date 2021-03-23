#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>

using namespace std;

class Product {
private:
	string name;
	int quantity;
	float price;

public:
	Product(string, int, float);
	string getName() const;
	int getQuantity() const;
	float getPrice() const;
	void setName(string);
	void setQuantity(int);
	void setPrice(float);

	void DisplayProduct() const;
};



#endif
