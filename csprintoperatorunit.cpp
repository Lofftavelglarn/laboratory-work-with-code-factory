#include "csprintoperatorunit.h"

CsPrintOperatorUnit::CsPrintOperatorUnit(const std::string &text)
    : AbstractPrintOperatorUnit(text){}

std::string CsPrintOperatorUnit::compile(unsigned int level) const
{
    return generateShift(level) + "printf(\"" + m_text+"\");\n";
}
