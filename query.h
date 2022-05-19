#include <httplib.h>
#include "json.hpp"

using json = nlohmann::json ;
class queryUrl
{
private:
    httplib::Client *cli;       //this resource is being init in the constructor, hence rule of 3 needs to be implemented
    httplib::SSLClient *cli_https;
    std::string mUrlToCall;     //base Url
    std::string mEndpointToCall;//end Point
    std::string mResponseData;  //responsedata
public:
    queryUrl() = delete;        //disable default constructor, it has to be init with url or copied
    queryUrl(std::string url);
    queryUrl(const queryUrl& other);        //copy constructor
    queryUrl& operator=(const queryUrl& other);
    void setEndpointToCall(const std::string &);
    void callAndSaveResponse();
    void queryConvertToJson();
    ~queryUrl();
};

queryUrl::queryUrl(std::string url):mUrlToCall(url)
{
    //this->cli = new httplib::Client(this->mUrlToCall);

    #ifdef CPPHTTPLIB_OPENSSL_SUPPORT
        cli_https = new httplib::SSLClient(this->mUrlToCall);
        cli_https->enable_server_certificate_verification(true);
    #else
        cli = new httplib::Client(this->mUrlToCall);
    #endif
}

//copy constructor to avoid shallow copy
queryUrl::queryUrl(const queryUrl& other):mUrlToCall(other.mUrlToCall){

    #ifdef CPPHTTPLIB_OPENSSL_SUPPORT
        cli_https = new httplib::SSLClient(this->mUrlToCall);
        cli_https->enable_server_certificate_verification(true);
    #else
        cli = new httplib::Client(this->mUrlToCall);
    #endif
}

queryUrl& queryUrl::operator=(const queryUrl& other){
    if (this == &other) {
        return (*this);    //dont copy itself into itself
    }
    else
    {
    this->mUrlToCall = other.mUrlToCall;

    #ifdef CPPHTTPLIB_OPENSSL_SUPPORT
        cli_https = new httplib::SSLClient(this->mUrlToCall);
        cli_https->enable_server_certificate_verification(true);
    #else
        cli = new httplib::Client(this->mUrlToCall);
    #endif

    return *this;
    }
}

void queryUrl::setEndpointToCall(const std::string &endpoint){

    this->mEndpointToCall = endpoint;
    
}


void queryUrl::callAndSaveResponse(){

    #ifdef CPPHTTPLIB_OPENSSL_SUPPORT
        if(auto getResponse = this->cli_https->Get(mEndpointToCall.c_str()))
    #else
        if(auto getResponse = this->cli->Get(mEndpointToCall.c_str()))
    #endif
    {
    std::cout << "string response is : " << getResponse->body << std::endl;
    mResponseData = getResponse->body;
    }
    else
    {
        std::cout << "Error is : "  << getResponse.error() << std::endl;
    }
}

void queryUrl::queryConvertToJson(){
    json responseJson = json::parse(mResponseData);
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
