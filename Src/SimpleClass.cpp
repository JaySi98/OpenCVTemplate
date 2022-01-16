#include <SimpleClass.h>

SimpleClass::SimpleClass()
{
    this->number = 10;
}

SimpleClass::~SimpleClass()
{

}

void SimpleClass::PrintNumber()
{
    std::cout << this->number << std::endl;
}

int SimpleClass::GetNumber()
{
    return this->number;
}