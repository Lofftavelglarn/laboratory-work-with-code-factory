#include "javaclassunit.h"

const std::vector<std::string> JavaClassUnit::ACCESS_MODIFIERS = {"public", "protected", "private"}; // Статическое поле класса должно быть проинициализровано вне него.

JavaClassUnit::JavaClassUnit(const std::string &name)
    :AbstractClassUnit(name){
    AbstractClassUnit::m_fields.resize(ACCESS_MODIFIERS.size());
}

void JavaClassUnit::add(const std::shared_ptr<Unit> &unit, Flags flags)
{
    int accessModifier = PRIVATE;
    if(flags < ACCESS_MODIFIERS.size()){
        accessModifier = flags;
    } else {
        qWarning("It's not a java modifier");
    }

    m_fields[accessModifier].push_back(unit);
}

std::string JavaClassUnit::compile(unsigned int level) const
{
    std::string result = generateShift(level) + "class " + m_name + " {\n";
    for(size_t i = 0;i < ACCESS_MODIFIERS.size();++i){
        if(m_fields[i].empty()){
            continue;
        }
        result += ACCESS_MODIFIERS[i] + ":\n";
        for(const auto& f : m_fields[i]){
            result += f->compile(level + 1);
        }
        result += "\n";
    }
    result += generateShift(level) + "};\n";
    return result;
}
