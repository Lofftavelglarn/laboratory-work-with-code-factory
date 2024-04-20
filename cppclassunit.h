#ifndef CPPCLASSUNIT_H
#define CPPCLASSUNIT_H

#include "unit.h"

class CppClassUnit : public Unit
{
public:
    enum AccessModifier{
        PUBLIC,
        PROTECTED,
        PRIVATE
    };

    static const std::vector<std::string> ACCESS_MODIFIERS;

    explicit CppClassUnit(const std::string& name);

    void add(const std::shared_ptr<Unit>& unit, Flags flags) override;

    std::string compile(unsigned int level = 0) const override;

private:
    std::string m_name;
    using Fields = std::vector<std::shared_ptr<Unit>>;

    std::vector<Fields> m_fields;
};

#endif // CPPCLASSUNIT_H
