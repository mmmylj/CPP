#include <iostream>
#include "tabtenn.h"

int main()
{
    using std::cout;
    using std::endl;
    TableTennisPlayer play1("Chuck", "Blizzard",true);
    TableTennisPlayer play2("Tara", "Boomdea", false);
    play1.Name();
    if (play1.HasTable())
        cout << ": has a table.\n";
    else
        cout << ": has't a table\n";
    play2.Name();
    if (play2.HasTable())
        cout << ": has a table.\n";
    else
        cout << ": has't a table\n";
    return 0;
}
