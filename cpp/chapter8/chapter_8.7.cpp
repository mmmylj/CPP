#include <iostream>
#include <string>
using namespace std;
string version1(const string & s1, const string & s2);
const string & version2(string &s1, const string & s2);
const string & version3 (string & s1, string & s2);
int main()
{
    string input;
    string copy;
    string result;

    cout<<"Enter a string: ";
    getline(cin, input);
    copy = input;
    cout <<"Your string as enter: "<<input<<endl;
    result = version1(input, "*****");

    cout<<"Your string enhanced: "<<result<<endl;
    cout<<"Your original string: "<<input<<endl;

    result = version2(input, "######");
    cout<<"Your string enhanced: "<<result<<endl;
    cout<<"Your original string: "<<input<<endl;

    //version3 Error
    // result = version3(input, "@@@@@");
    // cout<<"Your string enhanced: "<<result<<endl;
    // cout<<"Your original string: "<<input<<endl;

    return 0;
}

string version1(const string & s1, const string & s2)
{
    string temp;

    temp = s2+s1+s2;
    return temp;
}

const string & version2(string &s1, const string & s2)
{
    s1 = s2+s1+s2;
    return s1;
}


const string & version3 (string & s1,const string & s2)
{
//bad design!
//temp is new string object，when version3 completed temp will be delete，
//so return reference of temp unsafe
    string temp;
    temp = s2+s1+s2;
    return temp;
}
