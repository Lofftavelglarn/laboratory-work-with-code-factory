#ifndef CSPRINTOPERATORUNIT_H
#define CSPRINTOPERATORUNIT_H

#include "abstractprintoperatorunit.h"

class CsPrintOperatorUnit : public AbstractPrintOperatorUnit
{
public:
    explicit CsPrintOperatorUnit(const std::string& text);

    std::string compile(unsigned int level = 0) const override;
};

#endif // CSPRINTOPERATORUNIT_H
