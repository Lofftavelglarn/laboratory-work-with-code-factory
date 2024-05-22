#ifndef CPPCONCRETECODEFACTORY_H
#define CPPCONCRETECODEFACTORY_H

#include "abstractcodefactory.h"
#include "cppclassunit.h"
#include "cppmethodunit.h"
#include "cppprintoperatorunit.h"

class CppConcreteCodeFactory : public AbstractCodeFactory
{
public:
    CppConcreteCodeFactory() = default;
    ~CppConcreteCodeFactory() override = default;

    std::shared_ptr<AbstractClassUnit> createClass(const std::string& name) override;
    std::shared_ptr<AbstractMethodUnit> createMethod(const std::string& name, const std::string& returnType, Flags flags) override;
    std::shared_ptr<AbstractPrintOperatorUnit> createPrintMethod(const std::string& text) override;
};

#endif // CPPCONCRETECODEFACTORY_H
