#ifndef ABSTRACTCLASSUNIT_H
#define ABSTRACTCLASSUNIT_H

#include "unit.h"

class AbstractClassUnit : public Unit
{
public:
    enum AccessModifier{
        PUBLIC,
        PROTECTED,
        PRIVATE,
        PRIVATE_PROTECTED,
        FILE,
        INTERNAL,
        PROTECTED_INTERNAL
    };
    AbstractClassUnit(const std::string &name);

protected:
    std::string m_name;
    using Fields = std::vector<std::shared_ptr<Unit>>;

    std::vector<Fields> m_fields;
};

#endif // ABSTRACTCLASSUNIT_H
