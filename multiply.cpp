#include <node.h>

void Multiply(const v8::FunctionCallbackInfo<v8::Value>& args) {
  v8::Isolate* isolate = args.GetIsolate();
  v8::Local<v8::Context> context = isolate->GetCurrentContext();

  if (args.Length() < 2) {
    v8::Local<v8::String> errorMessage = v8::String::NewFromUtf8(isolate, "Wrong number of arguments").ToLocalChecked();
    isolate->ThrowException(v8::Exception::TypeError(errorMessage));
    return;
  }

  double value1 = args[0]->NumberValue(context).FromJust();
  double value2 = args[1]->NumberValue(context).FromJust();
  double result = value1 * value2;

  args.GetReturnValue().Set(v8::Number::New(isolate, result));
}

void Initialize(v8::Local<v8::Object> exports) {
  NODE_SET_METHOD(exports, "multiply", Multiply);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)
