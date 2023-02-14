#include <string>
#include <set>
#include <vector>
#include "util.h"
#include <map>
#include "mydatastore.h"

using namespace std; 
 /*Adds a product to the data store
     */
MyDataStore::MyDataStore(){
  
}

    
MyDataStore::~MyDataStore(){
      //delete all products and users
      
      
      // for(map<std::string, std::set<Product*>>::iterator useriterator = indexproducts.begin(); useriterator !=indexproducts.end(); ++useriterator){
        
      //   std::set<Product*> prod = useriterator->second;
      //     for (std::set<Product*>::iterator it = prod.begin(); it != prod.end(); ++it) {
      //         delete *it;
      //     }
      // }

      for(std::vector<Product*>::iterator proditerator = addproduct.begin(); proditerator != addproduct.end(); ++proditerator){
        delete *proditerator; //deleting all the products added
      }

      for(std::map<std::string, User*>::iterator it2 = users.begin(); it2 != users.end(); ++it2){
        delete it2->second; 
      }
    


    }

    void MyDataStore::viewcart(std::string username){

//if it finds a user, first, it = user.find, through an iterator, 

//it2 set to carts.find(username)
//check if there is nothing in the cart
// find cart items

//std::map<std::string,User*> users; 
    map<std::string, User*>::iterator userit; 
    userit = users.find(username); 
    if(userit == users.end()){//didn't find a username
    std::cout << "Invalid username" <<std::endl; 
    return;
    }

    //check if there is nothing in the cart
    //std::map<std::string, std::vector<Product*>> carts; 
    std::map<std::string, std::vector<Product*>>::iterator cartit; 
    cartit = carts.find(convToLower(username));

    if(cartit != carts.end()) //iterator to check if it finds the username in cart
    {
     
    std::vector<Product*> usernamecart = cartit->second;  
    
     // if(usernamecart.size() > 0){ //if it actually found a username
      //for loop to find them 
      for(size_t i = 0; i < usernamecart.size(); i++){
        cout << "Item " << i+1 << endl;
        cout << usernamecart[i]->displayString() <<endl;
      }

/*
      for(std::vector<Product*>::iterator it1 = usernamecart.begin(); it1 != usernamecart.end(); ++it1){
        //access the product through *it1
        std::cout << (*it1)->displayString() << std::endl; 
       } */

    //}



    
    }
    else{
      cout <<"Invalid username" << endl;
      return; 
    }
    } 

void MyDataStore::buycart(std::string username){

   
   /*std::map<std::string, User*>::iterator userit; 
    userit = users.find(username); 
    User* user = *userit; 
    if(userit == users.end()){//didn't find a username
    std::cout << "Invalid username" <<std::endl; 
    return;
    }*/

    //check if there is nothing in the cart
    //std::map<std::string, std::vector<Product*>> carts; 

    std::map<std::string, std::vector<Product*>>::iterator cartit; 
    username = convToLower(username);
    cartit = carts.find(username);

    if(cartit != carts.end()) //iterator to check if it finds the username in cart
    {
     
    std::vector<Product*> usernamecart = (cartit)->second;  
       
      
      if(usernamecart.size() > 0){ //if it actually found a username
      //for loop to find them 
      vector<Product*> newcart; 
      for(std::vector<Product*>::iterator it1 = usernamecart.begin(); it1 != usernamecart.end(); ++it1){


        Product* prod = *it1; 
        // if((*it1)->getQty()== 0){
        //   continue; 
        // }

        double itemprice = (prod)->getPrice();

        if(users[username]->getBalance() >= (*it1)->getPrice() && (*it1)->getQty() > 0){
          (users[username])->deductAmount(prod->getPrice());
          prod ->subtractQty(1); 
          
        }
        else{
          newcart.push_back(*it1); 
          
        }

      

      }
      carts[username] = newcart; 

      }



    
    }
    else{
      std::cout << "Invalid username" <<std::endl;
      return;
    }
    }


    



    


    void MyDataStore::addProduct(Product* p) /* = 0 */{
    
      addproduct.push_back(p);  //a set of strings that points to the keywords func. 
      std::set <std:: string> keywords = p -> keywords(); 

      for(std::set<string>::iterator it= keywords.begin(); it != keywords.end(); ++it){
        //std::map<std::string, std::set<Product*>> indexproducts; 
         //looking for keywords in keywords map
        map<std::string, std::set<Product*>>::iterator it2 = indexproducts.find(*it); 
        if(it2 == indexproducts.end()){ //if there is no product associated with keyword

            std::set<Product*> helpmakepair; 

            //helpmakepair.insert(p); 
            indexproducts.insert(make_pair((*it), helpmakepair)); 
        }

        //else{

        indexproducts[*it].insert(p); //within '[]' represents the key that it is recognised by.
        //I dereference the string, and insert the set of products, but should eb 
    //  }


      //std::map<std::string, std::set<Product*>> indexproducts;
      
      
  
    }
     
    }

    /**
     * Adds a user to the data store
     */

    void MyDataStore::addtocart(std::string u, Product* p) { //adds user to 
      std::map <std::string, User*>::iterator userit = users.find(u); 
      if(userit == users.end()){
        std::cout << "Invalid request" << endl; 
      }
       std::map<std::string, std::vector<Product*>>::iterator it1 = carts.find(u); //if "string" found, iterator points
       //to keyv
        if (it1 == carts.end()) { //checking if the iterator it1 is pointing to the end of the std::map carts.
      carts[u] = std::vector<Product*>(); //value is a newly created pointer to products creates 
  }
      carts[u].push_back(p);

    }
    

    void MyDataStore::addUser(User* u){
      
      
      
      users.insert(make_pair(convToLower(u->getName()), u)); 
            //the key is identifiable by a string,
      //and we need to access the name of the user by getname, so we have our
      //created object accessing the name
    
    }

      

    /**
     * Performs a search of products whose keywords match the given "terms"
     *  type 0 = AND search (intersection of results for each term) while
     *  type 1 = OR search (union of results for each term)
     */
    std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type){
      
      std::set<Product*> term; 
     std::set<Product*> intersectioncheck;
      std::set <Product*> unioncheck;
      //unioncheck = indexproducts[terms[0]];  
      //intersectioncheck = indexproducts[terms[0]];

      vector<Product*> vectorreturn;

    //std::vector<Product*> addproduct;
    
//std::map<std::string, std::set<Product*>> indexproducts; 
        if(type == 0){ //intersection
          std::map<std::string, std::set<Product*>>::iterator it2; 
              for(std::vector<std::string>::iterator termit = terms.begin(); termit != terms.end(); ++termit){
              
                

                std::string singleterm = convToLower(*termit);
                it2 = indexproducts.find(singleterm); 
                if(it2 != indexproducts.end()){
                   term = indexproducts[singleterm]; 
                //intersectioncheck = setIntersection(intersectioncheck, term); 
                  if(intersectioncheck.size() > 0){
                    intersectioncheck = setIntersection(intersectioncheck, term);
                    
                    //return vectorreturn;  
                  }
                  else{
                    intersectioncheck = term;
                  }
                }
                else{
                  std::cout << "Term not in database"; 
                  return vectorreturn; 
                }
          
               

              }
              
              for(std::set<Product*>::iterator it1 = intersectioncheck.begin(); it1 != intersectioncheck.end(); ++it1){
                vectorreturn.push_back(*it1); 
    
                
              } 
              return vectorreturn; 
            //this represents the "AND", setIntersection,
        }

        else if(type == 1){ //type == 1
            //this represents the "OR", setUnion
              std::map <std::string, std::set<Product*>>::iterator mapit; 

              for(std::vector<std::string>::iterator termit = terms.begin(); termit != terms.end(); ++termit){
                std::string lowercaseterm = convToLower(*termit); 
                mapit = indexproducts.find(lowercaseterm); 

                if(mapit == indexproducts.end()){
                  continue;  
                }

        
                
                 
                else{
                  term = indexproducts[lowercaseterm];
                  if(!unioncheck.empty()){
                    unioncheck = setUnion(unioncheck, term); 
                  }
                  else{
                    unioncheck = term; 
                  }
                }
              
                 
              }
              for(std::set<Product*>::iterator it2 = unioncheck.begin(); it2 != unioncheck.end(); ++it2){
                vectorreturn.push_back(*it2); 
    
                
              } 

              return vectorreturn; 
            //this represents the "AND", setIntersection, 
          }
        
          }
    

          

          
    /**


    
     * Reproduce the database file from the current Products and User values
     */
    void MyDataStore::dump(std::ostream& ofile){

          ofile << "<products>" << endl;

          for(std::vector<Product*>::iterator it1 = addproduct.begin(); it1 != addproduct.end(); ++it1 ){
            (*it1)->dump(ofile);  
          }
          ofile << "</products>" << endl; 
          ofile << "<users>" << endl; 

          for(std::map<std::string,User*>::iterator useriterator = users.begin(); useriterator !=users.end(); ++useriterator){

            (useriterator->second)->dump(ofile); 
          }
          ofile << "</users>"; 
    }
    


