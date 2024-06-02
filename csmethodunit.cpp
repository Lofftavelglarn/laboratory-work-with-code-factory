#include "csmethodunit.h"

CsMethodUnit::CsMethodUnit(const std::string &name, const std::string &returnType, Flags flags)
    : AbstractMethodUnit(name, returnType, flags){}

void CsMethodUnit::add(const std::shared_ptr<Unit> &unit, Flags)
{
    m_body.push_back(unit);
}

std::string CsMethodUnit::compile(unsigned int level) const
{
    std::string result = generateShift(level);
    if(m_flags & AbstractMethodUnit::STATIC){
        result += "static ";
    }else if(m_flags & AbstractMethodUnit::VIRTUAL){
        result += "virtual ";
    }else if(m_flags & AbstractMethodUnit::ABSTRACT){
        result += "abstract ";
        result += (m_returnType + "();");
        return result;
    } else if(m_flags){
        qWarning("This modifier does not exist in c#");
    }
    result += m_returnType + " ";
    result += m_name + " () ";
    if(m_flags & AbstractMethodUnit::CONST){
        result += " const";
    }
    result += " {\n";
    for(const auto& b : m_body){
        result += b->compile(level + 1);
    }
    result += generateShift(level) + "}\n";
    return result;
}
