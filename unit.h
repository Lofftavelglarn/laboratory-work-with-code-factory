#ifndef UNIT_H
#define UNIT_H

#include <string>
#include <vector>
#include <memory>
#include <stdexcept>

class Unit
{
public:
    using Flags = unsigned int;

    virtual ~Unit() = default;

    virtual void add(const std::shared_ptr<Unit>&, Flags = 0);

    virtual std::string compile(unsigned int level = 0) const = 0;
protected:
    virtual std::string generateShift(unsigned int level) const;
};

#endif // UNIT_H
