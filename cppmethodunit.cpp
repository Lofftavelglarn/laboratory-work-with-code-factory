#include "cppmethodunit.h"

CppMethodUnit::CppMethodUnit(const std::string &name, const std::string &returnType, Flags flags)
    : AbstractMethodUnit(name, returnType, flags){}

void CppMethodUnit::add(const std::shared_ptr<Unit> &unit, Flags)
{
    m_body.push_back(unit);
}

std::string CppMethodUnit::compile(unsigned int level) const
{
    std::string result = generateShift(level);
    if(m_flags & AbstractMethodUnit::STATIC){
        result += "static ";
    }else if(m_flags & AbstractMethodUnit::VIRTUAL){
        result += "virtual ";
    } else if(m_flags){
        qWarning("This modifier does not exist in c#");
    }
    result += m_returnType + " ";
    result += m_name + " () ";
    if(m_flags & AbstractMethodUnit::CONST){
        result += " const";
    }else if(m_flags & AbstractMethodUnit::FINAL){
        result += "final ";
    }
    result += " {\n";
    for(const auto& b : m_body){
        result += b->compile(level + 1);
    }
    result += generateShift(level) + "}\n";
    return result;
}
