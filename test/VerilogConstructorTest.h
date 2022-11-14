#ifndef __VERILOG_CONSTRUCTOR_TEST_H_
#define __VERILOG_CONSTRUCTOR_TEST_H_

#include "VerilogConstructor.h"

class VerilogConstructorTest: public naja::verilog::VerilogConstructor {
  public:
    void startModule(std::string&& name) override;
    void moduleInterfaceSimplePort(std::string &&name) override;
    void moduleImplementationPort(naja::verilog::Port&& port) override;
    void moduleInterfaceCompletePort(naja::verilog::Port&& port) override;
    struct Module {
      using Ports = std::vector<naja::verilog::Port>;
      std::string name_;
      Ports       ports_;
      
      Module(const std::string& name):
        name_(name)
      {}
    };
    using Modules = std::vector<Module>;
    Modules modules_;
};

#endif /* __VERILOG_CONSTRUCTOR_TEST_H_ */
