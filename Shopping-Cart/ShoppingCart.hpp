/****************************************************************
 * Author: Jacob Wilson
 * Date: 8/7/15
 * Description: Assignment 7 (Shopping Cart). The shopping cart
 * program stores items in an array of pointers. The shopping
 * cart declaration introduces the pointer array and a variable
 * for tracking the end of the array. Two member methods are used
 * for modifying and quantifying the shopping cart.
 ****************************************************************/

#ifndef SHOPPINGCART_HPP
#define SHOPPINGCART_HPP

#include "Item.hpp"

// The shopping cart class consists of an Item class array of 100 pointers pointing to
// Item class objects, and a variable representing the next available empty spot in the
// array. Two member methods are available to add items to the cart and to return total
// price of cart items.

class ShoppingCart
{
private:
    Item *ptrToItem[100];
    int arrayEnd;
    
public:
    // CONSTRUCTORS
    ShoppingCart();             // DEFAULT CONSTRUCTOR
    
    // member methods
    void addItem(Item *);       // adds item to array by passing address of Item object
    double totalPrice();        // calculates total price of items in the cart
};

#endif
