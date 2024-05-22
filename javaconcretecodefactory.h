#ifndef JAVACONCRETECODEFACTORY_H
#define JAVACONCRETECODEFACTORY_H

#include "abstractcodefactory.h"
#include "javaclassunit.h"
#include "javamethodunit.h"
#include "javaprintoperatorunit.h"

class JavaConcreteCodeFactory : public AbstractCodeFactory
{
public:
    JavaConcreteCodeFactory() = default;
    ~JavaConcreteCodeFactory() override = default;

    std::shared_ptr<AbstractClassUnit> createClass(const std::string& name) override;
    std::shared_ptr<AbstractMethodUnit> createMethod(const std::string& name, const std::string& returnType, Flags flags) override;
    std::shared_ptr<AbstractPrintOperatorUnit> createPrintMethod(const std::string& text) override;
};

#endif // JAVACONCRETECODEFACTORY_H
