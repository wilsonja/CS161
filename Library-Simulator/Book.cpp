/****************************************************************
 * Author: Jacob Wilson
 * Date: 8/15/15
 * Description: Assignment 8 (Library). The library program is a
 * simulator that uses many functions to carry out actions that
 * would be performed in a real library. The Book class sets
 * the properties and interactions of each Book object.
 ****************************************************************/

#include "Book.hpp"

// The CONSTRUCTOR sets idCode, title, and author to the arguments
// that are passed when a Book object is created. checkedOutBy and
// requestedBy variables for the object are set to NULL, and the
// Book location is set to ON_SHELF.

Book::Book(std::string idc, std::string t, std::string a)
{
    idCode = idc;               // sets idCode to passed string
    title = t;                  // sets title to passed string
    author = a;                 // sets author to passed string
    
    // variables set to NULL
    checkedOutBy = NULL;
    requestedBy = NULL;
    
    // put the Book on the shelf
    location = ON_SHELF;
}

// SET methods

void Book::setLocation(Locale loc)              // accepts a Locale and sets to location
{   location = loc;   }

void Book::setCheckedOutBy(Patron *pat)         // accepts a pointer to a Patron and sets to checkedOutBy
{   checkedOutBy = pat;   }

void Book::setRequestedBy(Patron *pat)          // accepts a pointer to a Patron and sets to requestedBy
{   requestedBy = pat;   }

void Book::setDateCheckedOut(int checkdate)     // accepts an integer and sets to dateCheckedOut
{   dateCheckedOut = checkdate;   }


// GET methods

int Book::getCheckOutLength()           // returns CHECK_OUT_LENGTH as an integer
{   return CHECK_OUT_LENGTH;   }

std::string Book::getIdCode()           // returns the idCode as a strong
{   return idCode;   }

std::string Book::getTitle()            // returns the title as a string
{   return title;   }

std::string Book::getAuthor()           // returns the author as a string
{   return author;   }

Locale Book::getLocation()              // returns the location as a Locale
{   return location;   }

Patron* Book::getCheckedOutBy()         // returns checkedOutBy as a pointer
{   return checkedOutBy;   }

Patron* Book::getRequestedBy()          // returns requestedBy as a pointer
{   return requestedBy;   }

int Book::getDateCheckedOut()           // returns dateCheckedOut as an integer
{   return dateCheckedOut;   }
