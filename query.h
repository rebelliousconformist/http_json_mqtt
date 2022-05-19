#include <httplib.h>
#include "json.hpp"

using json = nlohmann::json ;

class queryUrl
{
private:
    httplib::Client *cli;       //this resource is being init in the constructor, hence rule of 3 needs to be implemented
    std::string urlToCall;
    std::string responseBodyData;
public:
    queryUrl(std::string url);
    queryUrl(const queryUrl& other);        //copy constructor
    queryUrl& operator=(const queryUrl& other);
    void queryBaseAndPrint();
    void queryConvertToJson();
    ~queryUrl();
};

queryUrl::queryUrl(std::string url):urlToCall(url)
{
    this->cli = new httplib::Client(this->urlToCall);
}

//copy constructor to avoid shallow copy
        
queryUrl::queryUrl(const queryUrl& other):urlToCall(other.urlToCall){

    this->cli = new httplib::Client(this->urlToCall);
}

queryUrl& queryUrl::operator=(const queryUrl& other){
    if (this == &other) {
        return (*this);    //dont copy itself into itself
    }
    else
    {
    this->urlToCall = other.urlToCall;
    this->cli = new httplib::Client(this->urlToCall);
    return *this;
    }
}


class queryUrl
{
private:
    httplib::Client *cli;       //this resource is being init in the constructor, hence rule of 3 needs to be implemented
    std::string urlToCall;
    std::string responseBodyData;
public:
    queryUrl(std::string url);
    queryUrl(const queryUrl& other);        //copy constructor
    queryUrl& operator=(const queryUrl& other);
    void queryBaseAndPrint();
    void queryConvertToJson();
    ~queryUrl();
};

queryUrl::queryUrl(std::string url):urlToCall(url)
{
    this->cli = new httplib::Client(this->urlToCall);
}

//copy constructor to avoid shallow copy
        
queryUrl::queryUrl(const queryUrl& other):urlToCall(other.urlToCall){

    this->cli = new httplib::Client(this->urlToCall);
}

queryUrl& queryUrl::operator=(const queryUrl& other){
    if (this == &other) {
        return (*this);    //dont copy itself into itself
    }
    else
    {
    this->urlToCall = other.urlToCall;
    this->cli = new httplib::Client(this->urlToCall);
    return *this;
    }
}



void queryUrl::queryBaseAndPrint(){
    if(auto getResponse = this->cli->Get("/iolinkmaster/port[1]/iolinkdevice/pdin/getdata")){
    std::cout << "string response is : " << getResponse->body << std::endl;
    responseBodyData = getResponse->body;
    }
    else
    {
        std::cout << "Error is : "  << getResponse.error() << std::endl;
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
    if(cli)
    {
        delete cli;
        cli = nullptr;
    }

}

void queryUrl::queryBaseAndPrint(){
    if(auto getResponse = this->cli->Get("/iolinkmaster/port[1]/iolinkdevice/pdin/getdata")){
    std::cout << "string response is : " << getResponse->body << std::endl;
    responseBodyData = getResponse->body;
    }
    else
    {
        std::cout << "Error is : "  << getResponse.error() << std::endl;
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
    if(cli)
    {
        delete cli;
        cli = nullptr;
    }

}
