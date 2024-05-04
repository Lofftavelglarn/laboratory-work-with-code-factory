#ifndef CPPPRINTOPERATORUNIT_H
#define CPPPRINTOPERATORUNIT_H

#include "abstractprintoperatorunit.h"

class CppPrintOperatorUnit : public AbstractPrintOperatorUnit
{
public:
    explicit CppPrintOperatorUnit(const std::string& text);

    std::string compile(unsigned int level = 0) const override;
};

#endif // CPPPRINTOPERATORUNIT_H
