#ifndef CSCONCRETECODEFACTORY_H
#define CSCONCRETECODEFACTORY_H

#include "abstractcodefactory.h"
#include "csclassunit.h"
#include "csmethodunit.h"
#include "csprintoperatorunit.h"

class CsConcreteCodeFactory : public AbstractCodeFactory
{
public:
    CsConcreteCodeFactory() = default;
    ~CsConcreteCodeFactory() override = default;

    std::shared_ptr<AbstractClassUnit> createClass(const std::string& name) override;
    std::shared_ptr<AbstractMethodUnit> createMethod(const std::string& name, const std::string& returnType, Flags flags) override;
    std::shared_ptr<AbstractPrintOperatorUnit> createPrintMethod(const std::string& text) override;
};

#endif // CSCONCRETECODEFACTORY_H
