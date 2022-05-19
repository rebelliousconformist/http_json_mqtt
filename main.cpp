#include <iostream>
#include "query.h"


int main(int, char**) {

    try
    {
        std::cout << "Program start \n";
        queryUrl call("http://192.168.10.163");    
        call.queryBaseAndPrint();

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return (0);
}
