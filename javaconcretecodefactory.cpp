#include "javaconcretecodefactory.h"

std::shared_ptr<AbstractClassUnit> JavaConcreteCodeFactory::createClass(const std::string& name) {
    return std::make_shared<JavaClassUnit>(name);
}

std::shared_ptr<AbstractMethodUnit> JavaConcreteCodeFactory::createMethod(const std::string& name, const std::string& returnType, Flags flags) {
    return std::make_shared<JavaMethodUnit>(name, returnType, flags);
}

std::shared_ptr<AbstractPrintOperatorUnit> JavaConcreteCodeFactory::createPrintMethod(const std::string& text) {
    return std::make_shared<JavaPrintOperatorUnit>(text);
}
