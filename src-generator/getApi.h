#ifndef __GETAPI__
#define __GETAPI__

#include <curl/curl.h>
#include <string>

struct MemoryStruct {
    std::string memory;
    size_t size;
};

class GetApi {
    public:
        GetApi(const std::string& _url);

        static size_t WriteMemoryCallback(void *contents, size_t size,
                size_t nmemb, void *userp);

        // TODO: create a method to get message
        struct MemoryStruct chunk;
    private:
        std::string url;

};
#endif

