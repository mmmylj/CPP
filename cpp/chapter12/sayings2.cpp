#include <iostream>
#include <cstdlib>
#include <ctime>
#include "string.h"
const int ArSize = 10;
const int MaxLen = 82;
int main()
{
    using namespace std;
    String name;
    cout << "Hi, what's your name?\n";
    cin >> name;

    cout << name << ", please enter up to" << ArSize
        << "  saying <empty line to quit>:\n";
    String sayings[ArSize];
    char temp[MaxLen];
    int i;
    for (i = 0; i < ArSize; i++)
    {
        cout << i+1 << ": ";
        cin.get(temp, MaxLen);
        while (cin && cin.get() != '\n')
            continue;
        if (!cin || temp[0] == '\0') //empty line
            break;
        else
            sayings[i] = temp;
    }
    int total = i;
    if (total > 0)
    {
        cout << "Here are your saying:\n";
        for (i = 0; i < total; i++)
            cout << sayings[i];
        //using pointers to keep track of shortest,first string;
        String * shortest = &sayings[0];
        String * first = &sayings[0];
        for (i = 1; i < total; i++)
        {
            if (sayings[i].length() < shortest->length())
                shortest = &sayings[i];
            if (sayings[i] < *first)
                first = &sayings[i];
        }
        cout << "Shortest saying：\n" << *shortest << endl;
        cout << "First saying:\n" << *first << endl;
        srand(time(0));
        int choice = rand() % total;
        String * favorite = new String(sayings[choice]);
        cout << "My favorite saying:\n" << *favorite << endl;
        delete favorite;
    }
    else
        cout << "Not much to say, eh?\n";
    cout << "Bye.\n";
    return 0;
}

