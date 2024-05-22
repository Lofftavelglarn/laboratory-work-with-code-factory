#include "javaprintoperatorunit.h"

JavaPrintOperatorUnit::JavaPrintOperatorUnit(const std::string &text)
    : AbstractPrintOperatorUnit(text){}

std::string JavaPrintOperatorUnit::compile(unsigned int level) const
{
    return generateShift(level) + "printf(\"" + m_text+"\");\n";
}

