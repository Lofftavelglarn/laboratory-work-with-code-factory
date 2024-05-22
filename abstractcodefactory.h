#ifndef ABSTRACTCODEFACTORY_H
#define ABSTRACTCODEFACTORY_H

#include "unit.h"
#include "abstractclassunit.h"
#include "abstractmethodunit.h"
#include "abstractprintoperatorunit.h"

class AbstractCodeFactory
{
public:
    using Flags = unsigned int;
    AbstractCodeFactory() = default;
    virtual ~AbstractCodeFactory() = default;

    virtual std::shared_ptr<AbstractClassUnit> createClass(const std::string& name) = 0;
    virtual std::shared_ptr<AbstractMethodUnit> createMethod(const std::string& name, const std::string& returnType, Flags flags) = 0;
    virtual std::shared_ptr<AbstractPrintOperatorUnit> createPrintMethod(const std::string& text) = 0;
};

#endif // ABSTRACTCODEFACTORY_H
