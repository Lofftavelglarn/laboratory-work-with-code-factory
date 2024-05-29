#include <QCoreApplication>

#include "abstractcodefactory.h"
#include "cppconcretecodefactory.h"
#include "csconcretecodefactory.h"
#include "javaconcretecodefactory.h"
#include <iostream>
#include <QObject>

std::string generateProgram(std::shared_ptr<AbstractCodeFactory>& factory){
    if(!factory){
        qWarning("The factory has not been selected. Factory will be set to default (cpp)");
        factory = std::make_shared<CppConcreteCodeFactory>();
    }
    std::shared_ptr<AbstractClassUnit> myClass = factory->createClass("MyClass");
    myClass->add(
        factory->createMethod("testFunc1", "void", 0),
        AbstractClassUnit::PUBLIC
    );
    myClass->add(
        factory->createMethod("testFunc3", "void", AbstractMethodUnit::STATIC),
        AbstractClassUnit::PRIVATE
    );
    myClass->add(
        factory->createMethod(
            "testFunc3",
            "void",
            AbstractMethodUnit::VIRTUAL | AbstractMethodUnit::CONST
        ),
        AbstractClassUnit::PRIVATE
    );
    auto method = factory->createMethod( "testFunc4", "void", AbstractMethodUnit::STATIC );
    method->add(factory->createPrintMethod( R"(Hello, world!\n)" ) );
    myClass->add( method, AbstractClassUnit::PROTECTED );
    return myClass->compile();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::shared_ptr<AbstractCodeFactory> factory = std::make_shared<CppConcreteCodeFactory>();
    factory = nullptr;
    std::cout << generateProgram(factory) << std::endl;

    return a.exec();
}
