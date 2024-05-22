#ifndef JAVACLASSUNIT_H
#define JAVACLASSUNIT_H

#include "abstractclassunit.h"
#include <QObject>

class JavaClassUnit : public AbstractClassUnit
{
public:
    static const std::vector<std::string> ACCESS_MODIFIERS;

    explicit JavaClassUnit(const std::string &name);

    void add(const std::shared_ptr<Unit>& unit, Flags flags) override;

    std::string compile(unsigned int level = 0) const override;
};
#endif // JAVACLASSUNIT_H
