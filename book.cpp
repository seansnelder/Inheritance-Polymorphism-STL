#include <sstream>
#include <iomanip>
#include "book.h"
#include <iostream>
#include "util.h"
#include "product.h"


 using namespace std;

 Book::~Book(){
   
 } 
    Book::Book(const string category, const string name, double price, int qty, const string ISBN, const string author) : Product(category, name, price, qty), isbn_(ISBN), author_(author) {
       
    }

    std::set<std::string> Book::keywords() const {

        

      
        std::set<std::string> bookkeywords; 
 
        std::set<std::string> bookname = parseStringToWords(name_); 
        std::set<std::string> author = parseStringToWords(author_); 


        
        

        bookname = setUnion(bookname, author); 
        bookkeywords = setUnion(bookname, bookkeywords);  
        bookkeywords.insert(isbn_); 

        return bookkeywords; 


       
    }

    std::string Book::displayString() const{
      
  
  stringstream ss; 
    ss << fixed << setprecision(2) << getPrice(); 
    std::string stringprice = ss.str(); 

    std::string book = name_ + '\n' + "Author: " + author_ + " ISBN: " + isbn_ + '\n' + stringprice + " " + to_string(qty_) + " left."; 
    
    return book;
    }
    /**
     * Returns a string to display the product info for hits of the search
     */

    




    /**
     * Outputs the product info in the database format
     */
   void Book::dump(std::ostream& os) const{
      // os << category_ << endl;
      // os << name_ << endl;
      // os << price_ << endl; 
      // os << qty_ << endl;  
     Product::dump(os); 
      os << isbn_ << endl;
      os << author_ << endl; 
       
      

   }