/***************************************************************
 * Author: Jacob Wilson
 * Date: 8/7/15
 * Description: Assignment 7 (Shopping Cart). The shopping cart
 * program stores items in an array of pointers. The shopping
 * cart implemenation offers methods for intializing a NULL
 * pointer array, adding items to the shopping cart, and
 * calculating the total price of items in the cart.
 **************************************************************/

#include "ShoppingCart.hpp"

// DEFAULT CONSTRUCTOR sets all array elements to NULL and sets arrayEnd to 0

ShoppingCart::ShoppingCart()
{
    // loop through the array setting all 100 elements to NULL
    for(int index = 0; index < 100; index++)
    {
        ptrToItem[index] = NULL;
    }
    arrayEnd = 0;
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                              addItem                                    *
 * The addItem function takes an Item objects address as an argument and   *
 * assigns that address to a pointer in the array. It then increments the  *
 * arrayEnd variable to reflect the space taken by the additional item.    *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void ShoppingCart::addItem(Item *cartInput)
{
    ptrToItem[arrayEnd] = cartInput;        // assign Item object address to a pointer in the array
    arrayEnd++;                             // move to the next open array position
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                              totalPrice                                   *
 * The totalPrice function calculates the price of all items present in a    *
 * shopping cart object. It utilizes the arrow operator to access the get    *
 * methods for both price and quantity of each pointer present in the array. *
 * It multiplies these two values and keeps a running total of the shopping  *
 * cart. The shopping cart total is returned.                                *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

double ShoppingCart::totalPrice()
{
    double totalPrice = 0.0;
    double shoppingCartTotal = 0.0;
    
    for(int index = 0; index < arrayEnd; index++)       // access each element in the pointer array
    {
        // multiply the price by the quantity to determine the total price
        totalPrice = (ptrToItem[index]->getPrice()) * (ptrToItem[index]->getQuantity());
        
        // keep a cumulative total for the shopping cart
        shoppingCartTotal += totalPrice;
    }
    return shoppingCartTotal;
}
