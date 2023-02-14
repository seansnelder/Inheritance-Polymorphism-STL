#ifndef BOOK_H_
#define BOOK_H_
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

#include "product.h"

using namespace std; 

class Book: public Product{

public:
    Book(const std::string category, const std::string name, double price, int qty, const std::string ISBN, const std::string author); //constructor
    ~Book(); //destructor




    std::set<std::string> keywords() const;
/**
     * Allows for a more detailed search beyond simple keywords
     */
  
    /**
     * Returns a string to display the product info for hits of the search
     */
    std::string displayString() const;

    /**
     * Outputs the product info in the database format
     */
    void dump(std::ostream& os) const;

    /**
     * Accessors and mutators
     */
    //double getPrice() const;
    //std::string getName() const;
    //int getQty() const;
    //void subtractQty(int num);

// protected:
//     std::string name_;
//     double price_;
//     int qty_;
//     std::string category_;
    
private: 
    std::string author_; 
    std::string isbn_; 

    

}; 









#endif