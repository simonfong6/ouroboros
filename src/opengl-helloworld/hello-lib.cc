#include "src/opengl-helloworld/hello-lib.h"
#include <iostream>

using namespace hello;

using std::cout;
using std::endl;

HelloLib::HelloLib() {
    
}

HelloLib::HelloLib(const std::string &greeting) {
    this->greeting_ = std::make_unique<const std::string>(greeting);

}

void HelloLib::greet(const std::string &thing) {
    cout << *(this->greeting_) << thing << endl;
}
