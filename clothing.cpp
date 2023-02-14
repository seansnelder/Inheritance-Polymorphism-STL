#include <sstream>
#include <iomanip>
#include "clothing.h"
#include <iostream> 
#include "util.h"


 
 using namespace std; 
 //which returns the appropriate keywords to index the product

    Clothing::~Clothing(){

    }
    
    Clothing::Clothing(const string category, const string name, double price, int qty, const string size, const string brand) :Product(category, name, price, qty){
      size_ = size; 
      brand_ = brand; 
    }
    std::set<std::string> Clothing::keywords() const {

      std::set<std::string> clothingkeywords; 
 
        std::set<std::string> clothingname = parseStringToWords(name_);  
        std::set<std::string> brand = parseStringToWords(brand_); 
          

        clothingkeywords = setUnion(clothingname, brand); 

        return clothingkeywords; 
      
    }

 
    /**
     * Returns a string to display the product info for hits of the search
     */
    std::string Clothing::displayString() const {
    
    stringstream ss; 
    ss << fixed << setprecision(2) << getPrice(); 
    std:string stringprice = ss.str(); 

    std::string clothinginfo = name_ + '\n' + "Size: " + size_ + " Brand: " + brand_ + '\n' + stringprice + " " + to_string(qty_) + " left.";
  return clothinginfo; 
    }

    /**
     * Outputs the product info in the database format
     */
   void Clothing::dump(std::ostream& os) const{

      Product::dump(os); 
      os << size_ << std::endl; 
      os << brand_ << std::endl; 
      
       

   }