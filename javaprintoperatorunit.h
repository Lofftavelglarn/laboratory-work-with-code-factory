#ifndef JAVAPRINTOPERATORUNIT_H
#define JAVAPRINTOPERATORUNIT_H

#include "abstractprintoperatorunit.h"

class JavaPrintOperatorUnit : public AbstractPrintOperatorUnit
{
public:
    explicit JavaPrintOperatorUnit(const std::string& text);

    std::string compile(unsigned int level = 0) const override;
};

#endif // JAVAPRINTOPERATORUNIT_H
