#include <cstring>
#include "string.h"
using std::cin;
using std::cout;

int String::num_string = 0;

int String::HowMany()
{
    return num_string;
}

String::String(const char * s)
{
    len = std::strlen(s);
    str = new char [len + 1];
    std::strcpy(str, s);
    cout << num_string << ": \""<< str << "\"object created\n";
}

String::String()
{
    len = 4;
    str = new char[1];
    str[0] = '\0';
    num_string++;
}

//copy constructor function
String::String(const String & st)
{
    num_string++;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
}

String::~String()
{
    cout << "\"" << str << "\" object delete, ";
    --num_string;
    cout << num_string << "left\n";
    delete [] str;
}

String & String::operator=(const String & st)
{
    if (this == &st)
        return *this;
    delete [] str;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}

String & String::operator=(const char * s)
{
    delete [] str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}

char & String::operator[](int i)
{
    return str[i];
}

const char & String::operator[](int i) const
{
    return str[i];
}

bool operator<(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String &st1, const String &st2)
{
    return st2 < st1;
}

bool operator==(const String &st1, const String &st2)
{
    return(std::strcmp(st1.str, st2.str) == 0);
}

ostream & operator<<(std::ostream & os, String &str)
{
    os << str.str;
    return os;
}

istream & operator>>(istream & is, String &st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
        st = temp;
    while (is && is.get() != '\n')
        continue;
    return is;
}