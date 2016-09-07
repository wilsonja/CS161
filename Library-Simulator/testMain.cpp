#include "Library.hpp"
#include <iostream>

int main()
{
    Book b1("123", "War and Peace", "Tolstoy");
    Book b2("234", "Moby Dick", "Melville");
    Book b3("345", "Phantom Tollbooth", "Juster");
    Book b4("456", "dogs", "Grant");
    Patron p1("abc", "Felicity");
    Patron p2("bcd", "Waldo");
    Library lib;
    lib.addBook(&b1);
    lib.addBook(&b2);
    lib.addBook(&b3);
    lib.addBook(&b4);
    lib.addPatron(&p1);
    lib.addPatron(&p2);
    lib.checkOutBook("bcd", "234");
    for (int i=0; i<7; i++)
        lib.incrementCurrentDate();
    lib.checkOutBook("bcd", "123");
    lib.checkOutBook("abc", "345");
    for (int i=0; i<24; i++)
        lib.incrementCurrentDate();
    lib.payFine("bcd", 0.4);
    double p1Fine = p1.getFineAmount();
    double p2Fine = p2.getFineAmount();
    
    std::cout << p1Fine << std::endl;
    std::cout << p2Fine << std::endl;
    
    std::cout << &p1 << std::endl;
    
    std::cout << b4.getRequestedBy() << std::endl;
    
    std::cout << b4.getLocation() << std::endl;
    
    std::cout << lib.requestBook("abc", "456") << std::endl;
    
    std::cout << b4.getRequestedBy() << std::endl;
    
    std::cout << b4.getLocation() << std::endl;
    
    std::cout << lib.checkOutBook("abc", "456") << std::endl;
    
    std::cout << b4.getRequestedBy() << std::endl;
    
    std::cout << b4.getCheckedOutBy() << std::endl;
    
    std::cout << b4.getLocation() << std::endl;
    
    std::cout << lib.returnBook("456") << std::endl;
    
    std::cout << b4.getCheckedOutBy() << std::endl;
    
    std::cout << b4.getLocation() << std::endl;
    
    std::cout << &p2 << std::endl;
    
    std::cout << lib.checkOutBook("bcd", "456") << std::endl;
    
    std::cout << b4.getLocation() << std::endl;
    
    //std::cout << lib.returnBook("123") << std::endl;
    
    std::cout << lib.requestBook("bcd", "123") << std::endl;
    std::cout << b1.getRequestedBy() << std::endl;
    
    std::cout << b1.getLocation() << std::endl;
    
    std::cout << lib.requestBook("abc", "123") << std::endl;
    
    std::cout << b1.getRequestedBy() << std::endl;
    
    return 0;
}
