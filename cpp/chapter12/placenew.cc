#include <iostream>
#include <string>
#include <new>
using namespace std;
const int BUF = 512;
class JustTesting
{
    private:
        string words;
        int number;
    public:
        JustTesting(const string & s = "JustTesting", int n = 0)
        {
            words = s;number = n; cout << words << " constructed\n";
        }
        ~JustTesting(){cout << words << " destoryes\n";}
        void Show() const {cout << words << "," << number << endl;}
};

int main()
{
    char * buffer = new char[BUF];

    JustTesting *pc1, *pc2;

    pc1 = new (buffer) JustTesting;
    //定位new会覆盖这段地址上原有字符
    //覆盖之后delete buffer不会调用类的的析构函数    
    pc2 = new JustTesting("Heap1", 20);

    cout << "Memory block addresses:\n" << "buffer: "
        << (void *)buffer << "   heap: " << pc2 << endl;
    cout << "Memory contents:\n";
    cout << pc1 << ": ";
    pc1 ->Show();
    cout << pc2 << ": ";
    pc2 ->Show();

    JustTesting *pc3, *pc4;
    pc3 = new (buffer + sizeof(JustTesting)) JustTesting("Better Idea", 6);
    // pc3 = new (buffer) JustTesting("Bad Idea", 6);
    pc4 = new JustTesting("Heap2", 10);

    cout << "Memory contants:\n";
    cout << pc3 << ": ";
    pc3->Show();
    cout << pc4 << ": ";
    pc4->Show();

    delete pc2;
    delete pc4;
    //explicitly destroy placement new objects
    pc3->~JustTesting();
    pc1->~JustTesting();
    cout << "Done\n";
    return 0;
}