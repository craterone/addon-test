#include <napi.h>

#ifdef _WIN32
    #define MYTEXT "windows"
#elif __APPLE__
    #define MYTEXT "macOS"
#elif __linux__
    #define MYTEXT "linux"
#else
    #define MYTEXT "unknown"
#endif


Napi::String Method(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  #ifdef _WIN32
    std::string hello = "windows";
  #elif __APPLE__
    std::string hello = "macOS";
  #elif __linux__
    std::string hello = "linux";
  #else
    std::string hello = "unknown";
  #endif

  return Napi::String::New(env, "hello "+ hello);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "hello"),
              Napi::Function::New(env, Method));
  return exports;
}

NODE_API_MODULE(hello, Init)