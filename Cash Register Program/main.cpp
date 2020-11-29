#include "Store.h"
#include "StoreObject.hpp"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>

void addToCart(std::vector<StoreObject*>&, StoreObject*, int);
void printTitle();
void printInfo();

int main() {
	printTitle();
	try{
		// variables

		std::vector<StoreObject*> userShoppingCart;

		// individually specified products
		const StoreObject Tulip("Flower", 3.99, "D-5", "Tulip", 53101);
		const StoreObject Rose("Flower",4.59, "E-3", "Rose", 53102);
		const StoreObject Lily("Flower", 17.49, "B-2", "Potted Lily Set", 53103);
		const StoreObject twoxfour("Lumber", 12.98, "A-1", "2x4", 53111);
		const StoreObject twoxsix("Lumber", 15.98, "C-6", "2x6", 53112);
		const StoreObject plywood("Lumber", 23.99, "A-3", "Plywood Sheet", 53113);
		const StoreObject drill("Tool", 98.99, "B-3", "Craftsman Drill", 53121);
		const StoreObject toolKit("Tool", 179.99, "B-7", "Deqault Electric Drill Kit", 53122);
		const StoreObject skillSaw("Tool",129.99, "D-8", "Skill Saw (Deluxe) Package", 53123);

		// data arrays
		std::array<StoreObject,3> gardenArr = {Tulip, Rose, Lily};
		std::array<StoreObject,3> lumberArr = {twoxfour, twoxsix, plywood};
		std::array<StoreObject,3> toolArr = {drill, toolKit, skillSaw};
		Store::setTotalPrice(0.0f);

		// array of product IDs
		std::array<int,9> productIDs = {53101, 53102, 53103, 53111, 53112, 53113, 53121, 53122, 53123};

		// Body
		while(true)
        {
			std::cout << std::endl;
			printInfo();
			std::cout << "1. Add Product to Your Cart\n";
			std::cout << "2. Remove Product from your Cart\n";
			std::cout << "3. View Shopping Cart\n";
			std::cout << "4. Go-to Checkout\n";
			std::cout << "5. Exit\n\n";

			std::cout << "Enter your choice: ";
			int userInput1;
			std::cin >> userInput1;
			std::cin.ignore();
			std::cout << std::endl;

			switch(userInput1)
			{
            case 1:
                {
                    std::cout << "Which Product Category?: \n";
                    std::cout << "1. Garden Center\n";
                    std::cout << "2. Lumber Center\n";
                    std::cout << "3. Tool Center\n\n";

                    std::cout << "Enter your choice: ";
                    int userInput2;
                    std::cin >> userInput2;
                    std::cin.ignore();
                    std::cout << std::endl;
                    std::array<StoreObject,3>* objArr;
                    switch(userInput2)
                    {
                    case 1:
                        objArr = &gardenArr;
                        break;
                    case 2:
                        objArr = &lumberArr;
                        break;
                    case 3:
                        objArr = &toolArr;
                        break;
                    default:
                        break;
                    }
                    {
                        std::cout << "Enter the product ID: ";
                        int userIDinput;
                        std::cin >> userIDinput;
                        std::cin.ignore();

                        // checks if ID exists
                        bool IDfound = (std::find(productIDs.begin(),productIDs.end(), userIDinput) != productIDs.end());
                        try {
                            if (IDfound == false) {
                                std::string e = "*Error* Product ID not Found\n";
                                throw e;
                            } // if
                        }
                        catch (std::string e) {
                            std::cerr << e;
                            break;
                        }

                        std::cout << "Enter the desired Quantity: ";
                        int productQuantity;
                        std::cin >> productQuantity;
                        std::cin.ignore();

                        for (int i = 0; i < 3; i++) {
                            if ((*objArr)[i].getProductID() == userIDinput)
                            {
                                addToCart(userShoppingCart,&((*objArr)[i]),productQuantity);
                                break;
                            }
                        }
                    }
                break;
                }
			case 2:
			    {
                    std::cout << "Enter the product ID: ";
                    int userIDinput;
                    std::cin >> userIDinput;
                    std::cin.ignore();

                    // checks if ID exists
                    bool IDfound = (std::find(productIDs.begin(),productIDs.end(), userIDinput) != productIDs.end());
                    try {
                        if (IDfound == false) {
                            std::string e = "*Error* Product ID not Found\n";
                            throw e;
                        } // if
                    }
                    catch (std::string e) {
                        std::cerr << e;
                        break;
                    }

                    std::cout << "Enter the desired Quantity: ";
                    int productQuantity;
                    std::cin >> productQuantity;
                    std::cin.ignore();
                    try
                    {
                        for(unsigned int i = 0; i < userShoppingCart.size(); i++)
                        {
                            if(userShoppingCart[i]->getProductID() == userIDinput)
                            {
                                if(i + productQuantity > userShoppingCart.size())
                                    throw std::string("*Error* Desired Deletion Qauntity is Greater Than Number of Said Item in Your Cart!\n");
                                else if(userShoppingCart[i] != userShoppingCart[i+productQuantity-1])
                                    throw std::string("*Error* Desired Deletion Qauntity is Greater Than Number of Said Item in Your Cart!\n");
                                else
                                    break;
                            }
                        }
                        for (unsigned int i = 0; i < userShoppingCart.size(); i++)
                        {
                            if (userShoppingCart[i]->getProductID() == userIDinput)
                            {
                                userShoppingCart.erase(userShoppingCart.begin() + i, userShoppingCart.begin() + i + productQuantity);
                                float priceReduced = userShoppingCart[i]->getPrice() * productQuantity;
                                Store::setTotalPrice(Store::getTotalPrice() - priceReduced);
                                break;
                            }
                        }
                    }
                    catch (std::string str)
                    {
                        std::cerr << str;
                    }
                    break;
			    }
			case 3:
			    {
                    std::cout << "======================================\n";
                    std::cout << "\t   Your Shopping Cart\t\n";
                    std::cout << "======================================\n\n";
                    std::cout << "--------------------------------------\n";
                    // prints all of the data about the shopping cart

                    // declaration of dynamic objects to use for searching in array
                    for (unsigned int i = 0; i < userShoppingCart.size(); i++)
                    {
                        StoreObject* cur = userShoppingCart[i];
                        std::cout << std::endl;
                        std::cout << *cur;
                        std::cout << "-----\n";
                    }
                    std::cout << "--------------------------------------\n";
                    break;
			    }
			case 4:
			    {
                    std::cout << "======================================\n";
                    std::cout << "\tYour Official Store Receipt\t\n";
                    std::cout << "======================================\n\n";

                    std::cout << "--------------------------------------\n";
                    // prints all of the data about the shopping cart

                    for (unsigned int i = 0; i < userShoppingCart.size(); i++)
                    {
                        StoreObject* cur = userShoppingCart[i];
                        std::cout << std::endl;
                        std::cout << *cur;
                        std::cout << "-----\n";
                    }

                    if (Store::getTotalPrice() <= 0.0f) {
                        Store::setTotalPrice(0.0f);
                    } // if

                    std::cout << "\n--------------------------------------\n";
                    std::cout << "Your Total Price (Before Taxation): \n";
                    std::cout << "\t $" << std::setprecision(3) << Store::getTotalPrice() << std::endl;
                    std::cout << "-----\n";
                    std::cout << "Your Total Price (After Taxation): \n";
                    std::cout << "\t $" << std::setprecision(3) << Store::getTotalPrice() + Store::getTax() << std::endl;
                    std::cout << "-----\n";
                    std::cout << "--------------------------------------\n\n";

                    std::cout << "You may now enter the wearhouse and collect your products!\n";
                    std::cout << "Thank You For Shopping With Us! Have A Great Day!\n\n";
                    std::cout << "*Exiting Program...*\n";
                    std::cout << std::endl;
                    break;
                }
			case 5:
			    {
                    std::cout << "You have chosen to exit the store...\n";
                    std::cout << "*ALL USER DATA WILL BE LOST*\n";
                    std::cout << "Are You Sure You Want to Exit? (input \"yes\" or \"no\"): ";

                    std::string userInput3;
                    std::cin >> userInput3;
                    std::cin.ignore();
                    std::cout << std::endl;

                    if (userInput3 == "yes")
                    {
                        std::cout << "Goodbye!\n";
                        std::cout << std::endl;
                        break;
                    } // if
                    else if (userInput3 == "no") {
                        std::cout << "*Going Back to Program*\n";
                    } // else if
                    break;
                }
			}
		} // body whille loop

		// deletes all objects in the users shopping cart
		for (unsigned int i = 0; i < userShoppingCart.size(); i++) {
			delete userShoppingCart[i];
		} // for loop

	} // try
	catch (std::bad_alloc& e) {
        std::cerr << e.what() << std::endl;
        exit(EXIT_FAILURE);
    } // catch

	// terminate
  	return 0;
} // main function

void printTitle() {
	std::cout << "=============================================\n";
	std::cout << "\tWelcome to Spencer's Shopping\t\n";
	std::cout << "=============================================\n\n";
	std::cout << "------------------------------------------------------------------------------\n";
	std::cout << "You will first look at our list of product data presented below\n";
	std::cout << "to determine which products from what center you would like to purchase.\n";
	std::cout << "Once you have selected all your desired items, you may procede to checkout\n";
	std::cout << "where you will have your Product Info, Total Price, and Net Price printed onto\n";
	std::cout << "your reciept. Finally you may enter the wearhouse to retrieve your items.\n";
	std::cout << "------------------------------------------------------------------------------\n";
} // printTitle function

// function prints all essential user information
void printInfo() {
	std::cout << "------------------------------------------------------------------------------\n";
	std::cout << "Our Product List (Name (ID#), Price):\n";
	std::cout << "\tGarden Center: \n";
	std::cout << "\t\t" << "Tulip (53101)" << std::setw(35) << "$3.99" << std::endl;
	std::cout << "\t\t" << "Rose (53102)" << std::setw(36) << "$4.59" << std::endl;
	std::cout << "\t\t" << "Potted Lily Set (053103)" << std::setw(25) << "$17.49" << std::endl << std::endl;
	std::cout << "\tLumber Center: \n";
	std::cout << "\t\t" << "2x4 (53111)" << std::setw(38) << "$12.98" << std::endl;
	std::cout << "\t\t" << "4x6 (53112)" << std::setw(38) << "$15.98" << std::endl;
	std::cout << "\t\t" << "Plywood Sheet (53113)" << std::setw(28) << "$23.99" << std::endl << std::endl;
	std::cout << "\tTool Center: \n";
	std::cout << "\t\t" << "Craftsman Drill (53121)" << std::setw(26) << "$98.99" << std::endl;
	std::cout << "\t\t" << "Dewault Electric Tool Kit (53122)" << std::setw(17) << "$179.99" << std::endl;
	std::cout << "\t\t" << "Skill Saw (Deluxe) Package (53123)" << std::setw(16) << "$129.99" << std::endl;
	std::cout << "------------------------------------------------------------------------------\n";
} // printInfo function

// allows sorting on float and string arrays
// **Ascending order**
void addToCart(std::vector<StoreObject*>& vec, StoreObject* val, int amount)
{
    if(vec.size() == 0)
    {
        for(int i = 0; i < amount; i++)
            vec.push_back(val);
    }
    else
    {
        int low = 0, high = vec.size() - 1, medium = (high+low)/2;
        while(low != high && low + 1 != high)
        {
            if(vec[medium]->getPrice() > val->getPrice())
                high = medium;
            else if(vec[medium]->getPrice() < val->getPrice())
                low = medium;
            else if(vec[medium]->getPrice() == val->getPrice())
                break;
            medium = (high+low)/2;
        }
        if(low != high)
        {
            if(val->getPrice() > vec[high]->getPrice())
                medium = high;
            else
                medium = low;
        }
        for(int i = 0; i < amount; i++)
            vec.push_back(val);
        for(int j = vec.size() - 1; j > medium + amount; j--)
        {
            std::cout << j-amount;
            std::swap(vec[j],vec[j-amount]);
        }
    }
}
