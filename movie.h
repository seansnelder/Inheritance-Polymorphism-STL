#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>


#include "product.h" 

/* keywords() which returns the appropriate keywords 
to index the product, displayString() [to create a string
that contains the product info] and dump() [that outputs
the database format of the product info]. */

class Movie: public Product{
  public:
     Movie(const std::string category, const std::string name, double price, int qty, const std::string genre, const std::string rating);
    ~Movie(); //destructor

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
    // double getPrice() const;
    // std::string getName() const;
    // int getQty() const;
    // void subtractQty(int num);

// protected:
//     std::string name_;
//     double price_;
//     int qty_;
//     std::string category_;


private: 
    std::string genre_; 
    std::string rating_; 

}; 

#endif