#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

#include "Product.h"

class App {
public:
	vector<Product*> products;

	App() {
		vector <Product*> products;
	}

	void Run() {
		ifstream inFile;
		string line, temp_str;
		inFile.open("Data.txt");

		while (getline(inFile, line))
		{
			string name;
			int quantity;
			float price;
			vector<string> tokens;
			stringstream linestream(line);
			while (getline(linestream, temp_str, ' ')) {
				tokens.push_back(temp_str);
			}

			name = tokens[0];
			quantity = stoi(tokens[1]);
			price = stof(tokens[2]);

			Product* product = new Product(name, quantity, price);
			products.push_back(product);

			cout << '\n';

		}

		inFile.close();

	}

	void insertProduct() {
		string name;
		bool found = false;
		int quantity, index = -1;
		float price;
		cout << "Name of the product: ";
		cin >> name;
		cout << "Quantity: ";
		cin >> quantity;
		cout << "Price: ";
		cin >> price;

		auto it = products.begin();

		for (; it != products.end() && found == false; it++) {
			if ((*it)->getName() == name)
				found = true;
		}

		if (found == true)
		{
			cout << "Product found already in the list. \nWould you like to modify it? [y/n]";
			char choice;
			cin >> choice;
			if (choice == 'y')
				ModifyProduct(products.at(index));
			else return;

		}
		else {
			Product* product = new Product(name, quantity, price);
			products.push_back(product);
		}



	}

	void deleteProduct() {
		string name;
		bool found = false;
		cout << "Which product do you want to delete? ";
		cin >> name;
		auto it = products.begin();
		for (; it != products.end() && found == false ; it++) {
			if ((*it)->getName() == name) {
				products.erase(it);
				found = true;
			}
		}

		if (found == false)
			cout << "Invalid product";
		else {
			cout << "Product deleted";
			delete *it;
		}
	}

	void ModifyProductOption() {
		string name;
		int index = -1;
		bool found = false;
		cout << "Which product do you want to modify? ";
		cin >> name;

		auto it = products.begin();

		for (; it != products.end() && found == false; it++) {
			if ((*it)->getName() == name)
				found = true;
			index++;
		}

		if (found == true)
			ModifyProduct(products.at(index));
		else
			cout << "Product not found";
	}

	void ModifyProduct(Product* product) {
		int choice, quantity;
		float price;
		string name;
		system("CLS");
		do {
			product->DisplayProduct();
			cout << '\n';
			cout << "What do you want to modify?\n 1.Name\n 2.Quantity\n 3.Price\n 4.Quit\n Insert your choice ";
			cin >> choice;
			switch (choice) 
			{
			case 1:
				system("CLS");
				cout << "Insert new name ";
				cin >> name;
				product->setName(name);
				break;

			case 2:
				system("CLS");
				cout << "Insert new quantity ";
				cin >> quantity;
				product->setQuantity(quantity);
				break;


			case 3:
				system("CLS");
				cout << "Insert new price ";
				cin >> price;
				product->setPrice(price);
				break;

			}
			cin.get();
			if (cin.get() == '\n')
				system("CLS");
		} while (choice != 4);
	}

	void DisplayProducts() {
		cout << "\tName \t\tQuantity \tPrice";
		cout << '\n';
		auto it = products.begin();
		for (; it != products.end(); it++)
		{
			cout << "\t"<<(*it)->getName() << setw(15) << (*it)->getQuantity() << setw(15) << (*it)->getPrice();
			cout << '\n';
		}
	}

	void onQuit() {
		ofstream FileOut;
		FileOut.open("data.txt");
		auto it = products.begin();
		for (; it != products.end(); it++)
		{
			FileOut << (*it)->getName() << " "<< (*it)->getQuantity() << " "<< (*it)->getPrice();
			FileOut << '\n';
		}

		FileOut.close();
	}
	

};

int main() {
	App a;
	int choice;

	a.Run();

	cout << "\t\t           Menu Options";
	do {
		cout << "\n\n";
		cout << "\t\t Insert new product          '1'";
		cout << '\n';
		cout << "\t\t Modify a product            '2'";
		cout << '\n';
		cout << "\t\t Delete a product            '3'";
		cout << '\n';
		cout << "\t\t Display products            '4'";
		cout << '\n';
		cout << "\t\t Quit                        '5'";
		cout << '\n';
		cout << "\n\t\t Enter option ";

		cin >> choice;

		switch (choice)
		{
		case 1:
			system("CLS");
			a.insertProduct();
			break;
		case 2:
			system("CLS");
			a.ModifyProductOption();
			break;
		case 3:
			system("CLS");
			a.deleteProduct();
			break;
		case 4:
			system("CLS");
			a.DisplayProducts();
			break;
		case 5: 
			system("CLS");
			a.onQuit();
			break;
		
		}

		cin.get();
		if (cin.get() == '\n')
			system("CLS");
	} while (choice != 5);

	
}