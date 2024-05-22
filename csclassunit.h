#ifndef CSCLASSUNIT_H
#define CSCLASSUNIT_H

#include "abstractclassunit.h"
#include <QObject>

class CsClassUnit : public AbstractClassUnit
{
public:
    static const std::vector<std::string> ACCESS_MODIFIERS;

    explicit CsClassUnit(const std::string &name);

    void add(const std::shared_ptr<Unit>& unit, Flags flags) override;

    std::string compile(unsigned int level = 0) const override;
};

#endif // CSCLASSUNIT_H
