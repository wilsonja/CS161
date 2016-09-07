/****************************************************************
 * Author: Jacob Wilson
 * Date: 8/15/15
 * Description: Assignment 8 (Library). The library program is a
 * simulator that uses many functions to carry out actions that
 * would be performed at a real library. The patron class handles
 * all properties of the library users.
 ****************************************************************/

#include "Patron.hpp"

// The CONSTRUCTOR sets the idNum and name for new Patrons using
// the passed arguments. It also initializes the fineAmount to 0.

Patron::Patron(std::string idn, std::string n)
{
    idNum = idn;            // sets idNum to string argument
    name = n;               // sets name to string argument
    
    // set fineAmount to 0
    fineAmount = 0.0;
}

// GET methods

std::string Patron::getIdNum()                  // returns idNum as a string
{   return idNum;   }

std::string Patron::getName()                   // returns name as a string
{   return name;   }

std::vector<Book*> Patron::getCheckedOutBooks() // returns checkedOutBooks as a vector
{   return checkedOutBooks;   }

double Patron::getFineAmount()                  // returns fineAmount as a double
{    return fineAmount;   }


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                           addBook                               *
 * The addBook function accepts a pointer to a Book as an argument *
 * and adds this pointer to the checkedOutBooks vector             *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void Patron::addBook(Book *b)
{
    checkedOutBooks.push_back(b);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                           removeBook                                *
 * The removeBook function accepts a pointer to a Book object as the   *
 * argument. It then loops through the checkedOutBooks vector to look  *
 * for the book in the vector. When the book is found, it erases it    *
 * from the vector.                                                    *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void Patron::removeBook(Book *b)
{
    for(int index = 0; index < checkedOutBooks.size(); index++)
    {
        if(checkedOutBooks[index] == b)
            checkedOutBooks.erase(checkedOutBooks.begin() + index);
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                           amendFine                               *
 * The amendFine function accepts a double as an argument. It uses   *
 * this value to adjust the fineAmount. If the passed argument is    *
 * positive, it increases the fineAmount. If the passed argument is  *
 * negative, it decreases the fineAmount.                            *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void Patron::amendFine(double amount)
{
        fineAmount += amount;
}
