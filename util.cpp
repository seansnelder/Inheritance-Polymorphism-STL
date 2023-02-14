#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"
#include <string>

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{

std::set<std::string> newkeywords; 
std::stringstream readrawwords(rawWords); 

while(readrawwords >> rawWords){
std::string newword; 

    for(std::string::iterator it=rawWords.begin(); it!=rawWords.end(); ++it){
        if(isalnum(*it)){
            newword += tolower(*it); 

        }
        else{
          if(newword.length() >= 2){
            newkeywords.insert(newword); 
          }
            newword.clear(); 
            
        }

        } 

         
        if(newword.length() >= 2)
            {
                newkeywords.insert(newword); 

            }
        
    }
return newkeywords; 
}


/*Complete the parseStringToWords() in util.cpp according to the 
specification given above for taking a string of many words and 
splitting them into individual keywords (split at punctuation, 
with at least 2 character words)*/









/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
