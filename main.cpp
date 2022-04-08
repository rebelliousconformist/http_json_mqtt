#include <iostream>
#include <httplib.h>
#include "json.hpp"

using json = nlohmann::json ;
class queryUrl
{
private:
    httplib::Client *cli;
    std::string responseBodyData;
public:
    queryUrl(std::string url);
    void queryBaseAndPrint();
    void queryConvertToJson();
    ~queryUrl();
};

queryUrl::queryUrl(std::string url)
{
    cli = new httplib::Client(url);
}

void queryUrl::queryBaseAndPrint(){
    if(auto getResponse = this->cli->Get("/")){
    std::cout << getResponse->body << std::endl;
    responseBodyData = getResponse->body;
    }
    else
    {
        std::cout << getResponse.error() << std::endl;
    }
    
}

void queryUrl::queryConvertToJson(){
    json responseJson = json::parse(responseBodyData);
    std::cout << "size" << responseJson.size() <<  "\n";
    for (size_t i = 0; i < responseJson.size(); i++)
    {
        std::cout << "count is" <<  responseJson.at(i).value("age",-1) << "\n";
    }
  
}

queryUrl::~queryUrl()
{
}


int main(int, char**) {
    std::cout << "Hello, world!\n";
    queryUrl call("http://127.0.0.1:5000");
    
   call.queryBaseAndPrint();
   call.queryConvertToJson();
}
