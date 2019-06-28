#include <iostream>
#include "tabtenn.h"

int main(void)
{
    using std::cout;
    using std::endl;
    TableTennisPlayer player1("Tara", "Boomdea", false);
    RatePlayer rplayer1(1140, "Mallory", "Duck", true);
    rplayer1.Name();  //derive object use base object
    if (rplayer1.HasTable())
        cout << ": has a table.\n";
    else
        cout << ": has't a table\n";
    
    player1.Name();  //derive object use base object
    if (player1.HasTable())
        cout << ": has a table.\n";
    else
        cout << ": has't a table\n";
    

    cout << "Name: ";
    rplayer1.Name();
    cout << "; Rating: " << rplayer1.Rating() << endl;

    RatePlayer rplayer2(1212, player1);
    cout << "Name: ";
    rplayer2.Name();
    cout << "; Rating: " << rplayer2.Rating() << endl;

    return 0;
}