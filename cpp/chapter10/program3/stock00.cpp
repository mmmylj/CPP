#include <iostream>
#include "stock00.h"

Stock::Stock() //default construtor
{
    std::cout << "Default constructor called.\n";
    company = "noname";
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const std::string & co, long n, double pr)
{
    std::cout << "Constructor using " << co << " called\n";
    company = co;
    if (n < 0)
    {
        std::cout << "Number of shares can't be negative； "
                  << company << " shares set to 0.\n";
        shares = 0; 
    }
    else
        shares = n;
    share_val = pr;
    set_tot();  
}

//class destructor
Stock::~Stock()
{
    std::cout << "Bye, " << company << "!\n";
}

//other methods
void Stock::acquire(const std::string & co, long n, double pr)
{
    company = co;
    if (n < 0)
    {
        std::cout << "Number of shares can't be negative； "
                  << company << " shares set to 0.\n";
        shares = 0; 
    }
    else
        shares = n;
    share_val = pr;
    set_tot();        
}

void Stock::buy(long num, double price)
{
    if (num < 0)
    {
        std::cout << "Number of shares can't be negative. "
                << "Transaction is aborted.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    using std::cout;
    if (num < 0)
    {
        cout << "Number of shares sold can't be negative."
        << "Transaction is aborted.\n";
    }
    else if(num > shares)
    {
        cout << "You can't sell more than you have!"
        << "Transaction is aborted.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::updata(double price)
{
    share_val = price;
    set_tot();
}

void Stock::show() const
{
    //避免科学计数法
    std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    //只显示三位有效数字
    std::cout.precision(3);
    std::cout << "Company: " << company
            << " Shares: " << shares
            << " Share Price: $" << share_val
            <<" Total Worth: $" << total_val << "\n";
}

const Stock & Stock::topval(const Stock & s) const
{
    if (total_val > s.total_val)
        return *this;
    else
        return s;
}