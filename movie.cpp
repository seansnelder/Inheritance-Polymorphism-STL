#include <sstream>
#include <iomanip>
#include "movie.h"
#include <iostream>
#include "util.h"
using namespace std; 




    Movie::~Movie(){
   
 } 
    Movie::Movie(const string category, const string name, double price, int qty, const string genre, const string rating): Product(category, name, price, qty){
      genre_ = genre; 
      rating_ = rating; 
    }
     std::set<std::string> Movie::keywords() const {

         std::set<std::string> moviekeywords; 
 
        std::set<std::string> moviename = parseStringToWords(convToLower(name_)); 
         
        std::set <std::string> genree; 
        genree.insert(convToLower(genre_));  
        std::set<std::string>::iterator it; 
        
        // for(it = moviename.begin(); it != moviename.end(); ++it){
        //   moviekeywords.insert(*it); 
        // }
 

        moviekeywords = setUnion(genree, moviename); 

        return moviekeywords; 

    }
    /**
     * Returns a string to display the product info for hits of the search
     */
    std::string Movie::displayString() const{
      

    stringstream ss; 
    ss << fixed << setprecision(2) << getPrice(); 
    std::string stringprice = ss.str(); 


    std::string movieinfo = name_ + '\n' + "Genre: " + genre_ + " Rating: " + rating_ + '\n' + stringprice + " " + to_string(qty_) + " left."; 
    return movieinfo; 

    }

    /**
     * Outputs the product info in the database format
     */
   void Movie::dump(std::ostream& os) const{
       Product::dump(os); 
      os << genre_ << endl; 
      os << rating_ << endl; 

   }