#include <iostream>
#include "stock00.h"
const int SKTS = 4;

int main()
{
    using std::cout;
    Stock stocks[SKTS] =
    {
        Stock("NanoSmart", 12, 20.0),
        Stock("Boffo Objects", 200, 2.0),
        Stock("Monolithic Obelisks", 130, 3.25),
        Stock("Fleep Enterprises", 60, 6.5)
    };
    cout << "Stock holdings:\n";
    int st;
    
    for (st = 0; st < SKTS; st++)
    {
        stocks[st].show();
    }

    const Stock * top = &stocks[0];
    for (st = 1; st < SKTS; st++)
        top = &top->topval(stocks[st]);
    cout << "\nMost valueable holding:\n";
    top->show();
    return 0;
}