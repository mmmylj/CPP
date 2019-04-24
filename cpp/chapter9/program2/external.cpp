#include <iostream>
using namespace std;
double warming = 0.3;
void updata(double dt);
void local();
int main()
{
    cout << "Global warming is " << warming <<" degress.\n";
    updata(0.1);
    cout << "Global warming is " << warming << " degress.\n";
    local();
    cout << "Global warming is " << warming << " degress.\n";
    return 0;
}

