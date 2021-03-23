#include "Product.h"

Product::Product(string _name, int _quant, float _price) : name(_name), quantity(_quant), price(_price) {

}

string Product::getName() const {
	return name;
}

int Product::getQuantity() const {
	return quantity;
}

float Product::getPrice() const {
	return price;
}

void Product::setName(string _name){
	name = _name;
}

void Product::setQuantity(int _quant){
	quantity = _quant;
}

void Product::setPrice(float _price){
	price = _price;
}

void Product::DisplayProduct() const {
	cout << "Product " << name << " has " << quantity << " quantity and price " << price;
}