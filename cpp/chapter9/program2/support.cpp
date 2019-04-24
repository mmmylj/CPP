#include <iostream>
extern double warming; //use warming form other file

//function prototype
void updata(double dt);
void local();

using std :: cout;
void updata(double dt)
{
    //extern 使用全局变量
    extern double warming;
    warming += dt;
    cout << "Updating global warming to " << warming;
    cout << " degress.\n";
}

void local()
{
    double warming = 0.8;
    cout << "Local warming = " << warming << " degress.\n";
     //:: 作用域解析运算符，放在变量前，使用变量的1全局版本
    cout <<"But global warming = " << ::warming; 
    cout <<" degress.\n";
}