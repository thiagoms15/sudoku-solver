#include "getApi.h"

GetApi::GetApi(const std::string& _url)
    : url(_url)
{
    CURLcode res;
    CURL *curl;

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

        // send all data to this function
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, GetApi::WriteMemoryCallback);

        // we pass our 'chunk' struct to the callback function
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);

        // some servers do not like requests that are made without a user-agent
        //   field, so we provide one
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");

        // Perform the request, res will get the return code
        res = curl_easy_perform(curl);
        // Check for errors
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));

        // always cleanup
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
}

size_t GetApi::WriteMemoryCallback(void *contents, size_t size,
        size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *)userp;

    mem->memory.append((char*)contents);
    mem->size += realsize;

    return realsize;
}

