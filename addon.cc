#include <nan.h>
#include <unordered_map>

using namespace std;

using v8::FunctionTemplate;
using v8::Handle;
using v8::Object;
using v8::String;
using Nan::GetFunction;
using Nan::New;
using Nan::Set;

NAN_METHOD(run) {
    unordered_map<int, int> m;
    m.emplace(10, 20);
}

NAN_MODULE_INIT(init) {
  Set(target, New<String>("run").ToLocalChecked(),
    GetFunction(New<FunctionTemplate>(run)).ToLocalChecked());
}

NODE_MODULE(addon, init);