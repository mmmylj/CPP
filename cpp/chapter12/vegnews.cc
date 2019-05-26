#include <iostream>
using std::cout;
#include "string.h"

void callme1(String & rsb);
void callme2(String & sb);
int main()
{
    using std::endl;
    {
        cout << "Starting an inner block.\n";
        String headline1("Celery Stalk at Midnight");
        String headline2("Lettuce Prey");
        String sports("Spinach Leaves Bow1 for Dollar$");
        cout << "headline1: " << headline1 << endl;
        cout << "headline2: " << headline2 << endl;
        cout << "sports: " << sports << endl;

        callme1(headline1);
        cout << "headline1： " << headline1 << endl;
        callme2(headline2);
        cout << "headline2: " << headline2 << endl;
        cout << "Intialize one object to another:\n";
        String sailor = sports;
        cout << "sailor: " << sailor << endl;
        cout << "Assign one object to another:\n";
        String knot;
        knot = headline1;
        cout << "knot: " << knot << endl;
        cout << "Exiting the block.\n"; 
    }

    cout << "End of main()\n";
    return 0;
}

void callme1(String & rsb)
{
    cout << "String passed by reference:\n";
    cout << "     \"" << rsb << "\"\n";
}

void callme2(String & sb)
{
    cout << "String passed by value：\n";
    cout << "     \"" << sb << "\"\n";
}