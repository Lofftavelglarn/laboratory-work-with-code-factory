#include "javamethodunit.h"

JavaMethodUnit::JavaMethodUnit(const std::string &name, const std::string &returnType, Flags flags)
    : AbstractMethodUnit(name, returnType, flags){}

void JavaMethodUnit::add(const std::shared_ptr<Unit> &unit, Flags)
{
    m_body.push_back(unit);
}

std::string JavaMethodUnit::compile(unsigned int level) const
{
    std::string result = generateShift(level);
    if(m_flags & STATIC){
            result += "static ";
    }else if(m_flags & ABSTRACT){
        result += "abstract ";
        result += (m_returnType + "();");
        return result;
    }else if(m_flags & FINAL){
        result += "final ";
    }
    result += m_returnType + " ";
    result += m_name + " () ";
    if(m_flags & CONST){
        qWarning("The const modifier does not exist in java");
    }
    result += " {\n";
    for(const auto& b : m_body){
        result += b->compile(level + 1);
    }
    result += generateShift(level) + "}\n";
    return result;
}
