#include "csconcretecodefactory.h"

std::shared_ptr<AbstractClassUnit> CsConcreteCodeFactory::createClass(const std::string& name) {
    return std::make_shared<CsClassUnit>(name);
}

std::shared_ptr<AbstractMethodUnit> CsConcreteCodeFactory::createMethod(const std::string& name, const std::string& returnType, Flags flags) {
    return std::make_shared<CsMethodUnit>(name, returnType, flags);
}

std::shared_ptr<AbstractPrintOperatorUnit> CsConcreteCodeFactory::createPrintMethod(const std::string& text) {
    return std::make_shared<CsPrintOperatorUnit>(text);
}
