/****************************************************************
 * Author: Jacob Wilson
 * Date: 8/7/15
 * Description: Assignment 7 (Shopping Cart). The shopping cart
 * program stores items in an array of pointers. The declaration
 * for the Item class introduces the class members name, price,
 * and quantity, and methods for setting and getting these
 * member variables.
 ****************************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

// The item class consists of objects with three variables; name,
// price, and quantity. SET/GET methods are available for each
// of the variables.

class Item
{
private:
    std::string name;
    double price;
    int quantity;
    
public:
    // CONSTRUCTORS
    Item();                              // default CONSTRUCTOR
    Item(std::string, double, int);      // second CONSTRUCTOR accepts three arguments
    
    // SET methods
    void setName(std::string);           // SET method for name accepts a string
    void setPrice(double);               // SET method for price accepts a double
    void setQuantity(int);               // SET method for quantity accepts an integer
    
    // GET methods
    std::string getName();               // GET method for name
    double getPrice();                   // GET method for price
    int getQuantity();                   // GET method for quantity
};

#endif
