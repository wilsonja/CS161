/****************************************************************
 * Author: Jacob Wilson
 * Date: 8/15/15
 * Description: Assignment 8 (Library). The library program is a
 * simulator that uses many functions to carry out actions that
 * would be performed at a real library. The library class handles
 * interactions between both the Book and Patron classes. It
 * allows for the Patron users to interact with Book objects,
 * and it tracks these interactions.
 ****************************************************************/

#include "Library.hpp"

// The DEFAULT CONSTRUCTOR initializes the currentDate to 0.

Library::Library()
{
    currentDate = 0;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                           getBook                               *
 * getBook loops through the holdings vector looking for the book  *
 * ID that was passed as the argument. When it finds the book in   *
 * holdings, it returns a pointer to that Book.                    *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

Book* Library::getBook(std::string bID)
{
    for(int index = 0; index < holdings.size(); index++)
    {
        if(holdings.at(index)->getIdCode() == bID)
            return holdings.at(index);
    }
    return NULL;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                           getPatron                           *
 * getPatron loops through the members vector looking for the    *
 * Patron ID that was passed as the argument. When it finds this *
 * Patron ID in the vector, it returns a pointer to that Patron. *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

Patron* Library::getPatron(std::string pID)
{
    for(int index = 0; index < members.size(); index++)
    {
        if(members.at(index)->getIdNum() == pID)
            return members.at(index);
    }
    return NULL;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                           addBook                               *
 * The addBook function accepts a pointer to a Book as an argument *
 * and adds this pointer to the holdings vector.                   *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void Library::addBook(Book *bk)
{
    holdings.push_back(bk);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                           addPatron                         *
 * addPatron accepts a pointer to a Patron as an argument and  *
 * adds that pointer to the members vector.                    *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void Library::addPatron(Patron *pt)
{
    members.push_back(pt);

}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                           checkOutBook                                *
 * The checkOutBook function accepts two string arguments to represent   *
 * the patron ID and the book ID. It then validates these two arguments  *
 * to see if both exist in the library. If the book is not avaiable due  *
 * to being checked out or on hold, an appropriate string will be        *
 * returned. If the book is available, it will be checked out to the     *
 * Patron, set check out date and location, reset RequestedBy to NULL    *
 * if the Patron had it on request, and will add the book to the Patrons *
 * checkedOutBooks vector.                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

std::string Library::checkOutBook(std::string pID, std::string bID)
{
    Book *bk = getBook(bID);
    Patron *pt = getPatron(pID);
    
    if(bk == NULL)
        return "book not found";
        
    if(pt == NULL)
        return "patron not found";
    
    if(bk->getLocation() == CHECKED_OUT)
        return "book already checked out";
    
    if(bk->getRequestedBy() != NULL && bk->getRequestedBy() != pt)
        return "book on hold by other patron";
        
    else
    {
        bk->setCheckedOutBy(pt);
    
        bk->setDateCheckedOut(currentDate);
    
        bk->setLocation(CHECKED_OUT);
    
        if(bk->getRequestedBy() == pt)
            bk->setRequestedBy(NULL);
    
        pt->addBook(bk);
    
        return "checkout successfull";
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                         returnBook                              *
 * The returnBook function accepts a Book ID as an argument. It    *
 * validates this book, then removes the book from the patrons     *
 * checkedOutBooks vector, updates the book location depending on  *
 * request status, and then resets CheckedOutBy to NULL.           *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

std::string Library::returnBook(std::string bID)
{
    Book *bk = getBook(bID);
    
    if(bk == NULL)
        return "book not found";
    
    if(bk->getLocation() != CHECKED_OUT)
        return "book already in library";
    
    Patron *pat = bk->getCheckedOutBy();
    
    pat->removeBook(bk);
    
    if(bk->getRequestedBy() == NULL)
        bk->setLocation(ON_SHELF);
    else
        bk->setLocation(ON_HOLD_SHELF);
    
    bk->setCheckedOutBy(NULL);
    
    return "return successfull";
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                           requestBook                         *
 * requestBook validates book and patron arguments. It then sets *
 * requestedBy to the patron and changes the book location       *
 * accordingly.                                                  *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

std::string Library::requestBook(std::string pID, std::string bID)
{
    Book *bk = getBook(bID);
    Patron *pt = getPatron(pID);
    
    if(bk == NULL)
        return "book not found";
    
    if(pt == NULL)
        return "patron not found";
    
    if(bk->getLocation() == ON_HOLD_SHELF)
        return "book on hold by other patron";
    else
    {
        bk->setRequestedBy(pt);
    
        if(bk->getLocation() == ON_SHELF)
            bk->setLocation(ON_HOLD_SHELF);
    
        return "request successful";
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                           payFine                                 *
 * payFine validates a patron argument. It then calls the amendFine  *
 * function passing the payment as a negative argument.              *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

std::string Library::payFine(std::string pID, double payment)
{
    Patron *pt = getPatron(pID);
    
    if(pt == NULL)
        return "patron not found";
    
    pt->amendFine(-payment);
    
    return "payment successfull";
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                    incrementCurrentDate                         *
 * The incrementCurrentDate function increase the currentDate when *
 * called. It will also add a 0.10 fine to overdue books for each  *
 * patron in the library.                                          *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void Library::incrementCurrentDate()
{
    ++currentDate;
    
    for(int index = 0; index < members.size(); index++)
    {
        Patron *pt = members[index];
    
        std::vector<Book*> ptbk = pt->getCheckedOutBooks();
        
        for(int i = 0; i < ptbk.size(); i++)
        {
            Book *bk = ptbk[i];
            
            if(currentDate > bk->getDateCheckedOut() + Book::CHECK_OUT_LENGTH)
                pt->amendFine(0.10);
        }
    }
}
