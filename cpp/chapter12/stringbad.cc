#include <cstring>
#include "stringbad.h"
using std::cout;

int StringBad::num_string = 0;

StringBad::StringBad(const char * s)
{
    len = std::strlen(s);
    str = new char [len + 1];
    std::strcpy(str, s);
    cout << num_string << ": \""<< str << "\"object created\n";
}

StringBad::StringBad()
{
    len = 4;
    str = new char[4];
    std::strcpy(str, "c++");
    num_string++;
    cout << num_string << ": \"" << str << "\"default object create\n";
}

StringBad::~StringBad()
{
    cout << "\"" << str << "\" object delete, ";
    --num_string;
    cout << num_string << "left\n";
    delete [] str;
}

std::ostream & operator<<(std::ostream & os, StringBad str)
{
    os << str.str;
    return os;
}