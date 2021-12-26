#ifndef SRC_OPENGL_HELLOWORLD_HELLO_LIB_H
#define SRC_OPENGL_HELLOWORLD_HELLO_LIB_H

#include <string>
#include <memory>

namespace hello {

class HelloLib {
 public:
  HelloLib();

  explicit HelloLib(const std::string &greeting);

  void greet(const std::string &thing);

 private:
  std::unique_ptr<const std::string> greeting_;
};

}  // namespace hello

#endif  // SRC_OPENGL_HELLOWORLD_HELLO_LIB_H
