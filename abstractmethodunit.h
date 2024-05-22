#ifndef ABSTRACTMETHODUNIT_H
#define ABSTRACTMETHODUNIT_H

#include "unit.h"

class AbstractMethodUnit : public Unit
{
public:
    enum Modifier{
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2,
        FINAL = 1 << 3,
        ABSTRACT = 1 << 4
    };

    AbstractMethodUnit(const std::string& name, const std::string& returnType, Flags flags);
protected:
    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector<std::shared_ptr<Unit>> m_body;
};

#endif // ABSTRACTMETHODUNIT_H
