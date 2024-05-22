#include "cppconcretecodefactory.h"

std::shared_ptr<AbstractClassUnit> CppConcreteCodeFactory::createClass(const std::string& name) {
    return std::make_shared<CppClassUnit>(name);
}

std::shared_ptr<AbstractMethodUnit> CppConcreteCodeFactory::createMethod(const std::string& name, const std::string& returnType, Flags flags) {
    return std::make_shared<CppMethodUnit>(name, returnType, flags);
}

std::shared_ptr<AbstractPrintOperatorUnit> CppConcreteCodeFactory::createPrintMethod(const std::string& text) {
    return std::make_shared<CppPrintOperatorUnit>(text);
}
