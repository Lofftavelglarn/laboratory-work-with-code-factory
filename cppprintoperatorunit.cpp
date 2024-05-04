#include "cppprintoperatorunit.h"

CppPrintOperatorUnit::CppPrintOperatorUnit(const std::string &text)
    : AbstractPrintOperatorUnit(text){}

std::string CppPrintOperatorUnit::compile(unsigned int level) const
{
    return generateShift(level) + "printf(\"" + m_text+"\");\n";
}
