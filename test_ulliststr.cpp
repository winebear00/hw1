#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
    ULListStr dat;
    dat.push_back("7");
    dat.push_front("8");
    dat.push_back("9");
    dat.push_back("3");
    dat.push_back("1");
    dat.push_back("0");
    dat.push_front("2");
    dat.push_front("0");
    //dat.pop_back();
   // dat.pop_front();
    std::cout << dat.get(0) << " "<<dat.get(1)<<" "<<dat.get(2)<<" "<<dat.get(3)<<" "<<dat.get(4)<<" "<<
    dat.get(5)<<" "<<dat.get(6)<<" "<<dat.get(7)<<std::endl;
    std::cout <<dat.front()<<std::endl;
    std::cout <<dat.back()<<std::endl;
    // prints: 02879310
    std::cout << dat.size() << std::endl;  // prints 3 since there are 3 strings stored

// std::vector<std::string> content = {"sup", "er", "cal", "i", "frag", "il", "istic", "expi", "alo", "doc", "ious"};
// for(int i=0; i<content.size();i++){
//     dat.push_back(content[i]);
// }
// dat.pop_back();
// std::cout << dat.get(9) << std::endl;
// }
