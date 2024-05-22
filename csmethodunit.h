#ifndef CSMETHODUNIT_H
#define CSMETHODUNIT_H

#include "abstractmethodunit.h"

class CsMethodUnit : public AbstractMethodUnit
{
public:
    CsMethodUnit(const std::string& name, const std::string& returnType, Flags flags);

    void add(const std::shared_ptr<Unit>& unit, Flags /*flags*/ = 0) override;

    std::string compile(unsigned int level = 0) const override;
};

#endif // CSMETHODUNIT_H
