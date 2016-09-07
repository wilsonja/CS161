/****************************************************************
 * Author: Jacob Wilson
 * Date: 8/7/15
 * Description: Assignment 7 (Shopping Cart). The shopping cart
 * program stores items in an array of pointers. The Item class
 * implementation offers methods for setting and getting Item
 * member variables.
 ****************************************************************/

#include "Item.hpp"

// DEFAULT CONSTRUCTOR initializes all variables to empty or zero

Item::Item()
{
    setName("");
    setPrice(0.0);
    setQuantity(0);
}

// second CONSTRUCTOR accepts three arguments to set each variable

Item::Item(std::string x, double y, int z)
{
    setName(x);
    setPrice(y);
    setQuantity(z);
}

// SET methods

void Item::setName(std::string x)       // accepts a string and sets it to name
{   name = x;   }

void Item::setPrice(double y)           // accepts a double and sets it to price
{   price = y;  }

void Item::setQuantity(int z)           // accepts an integer and sets it to quantity
{   quantity = z;   }

// GET methods

std::string Item::getName()             // returns the name as a string
{   return name;    }

double Item::getPrice()                 // returns the price as a double
{   return price;   }

int Item::getQuantity()                 // returns the quantity as an integer
{   return quantity;    }
