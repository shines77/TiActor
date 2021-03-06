
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <string>

#include <TiActor/utils/ToString.h>
#include <TiActor/actor/ActorSystem.h>
#include <TiActor/actor/ActorSystemImpl.h>

#include <TiActor/basic/static_link.h>

using namespace TiActor;

class NoToStringTest {};

class ToStringTest {
public:
    // Class have inner toString() method
    std::string toString() const {
        return std::string("[ ClassName is ToStringTest() ]");
    }
};

int main(int argn, char * argv[])
{
    std::cout << "Function toString() Test..." << std::endl << std::endl;

    {
        ActorSystem * system = ActorSystem::create("Factorial N");
        std::string className;
        className = StringUtils::toString(*system);
        std::cout << "[ActorSystem] Class Name is: " << className << std::endl;

        ToStringTest toStringTest;
        className = StringUtils::toString(toStringTest);
        std::cout << "[ToStringTest] Class Name is: " << className << std::endl;
    }

    std::cout << std::endl;

    {
        ActorSystem * system = ActorSystem::create("Factorial N");
        std::string className;
        className = StringUtils::toString2(*system);
        std::cout << "[ActorSystem] Class Name is: " << className << std::endl;

        ToStringTest toStringTest;
        className = StringUtils::toString2(toStringTest);
        std::cout << "[ToStringTest] Class Name is: " << className << std::endl;
    }

    std::cout << std::endl;

    std::cout << MemberFunctionIsExists(ToStringTest, toString) << std::endl;
    std::cout << MemberFunctionIsExists(NoToStringTest, toString) << std::endl;

    std::cout << std::endl;
    ::system("pause");
    return 0;
}
