#include <iostream>
#include "query.h"


int main(int, char**) {

    try
    {
        std::cout << "Program start \n";
        queryUrl call("api.openweathermap.org");
        const std::string endpointotcall("/data/2.5/weather?lat=48.366512&lon=10.894446&appid=b05b2fd9019f11c4bf46a71177ec2d15");
        call.callAndSaveResponse();

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return (0);
}
