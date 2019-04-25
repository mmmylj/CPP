#include <iostream>
#include "mytime0.h"

int main()
{
    using std::cout;
    using std::endl;
    Time planning;
    Time coding(2, 40);
    Time fixing = Time(5, 55);
    Time total = Time();

    cout << "planning time = ";
    planning.show();
    cout << endl;

    cout << "coding time = ";
    coding.show();
    cout << endl;

    cout << "fixinf time = ";
    fixing.show();
    cout << endl;

    total = coding.Sum(fixing);
    cout << "total time = ";
    total.show();
    cout << endl;

    return 0;
}