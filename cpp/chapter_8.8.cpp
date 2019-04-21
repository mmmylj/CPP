#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void file_it (ostream & os, double fo, const double fe[], int n);
const int LIMIT = 5;
int main()
{
    ofstream fout;
    const char * fn  = "ep-data.txt";
    fout.open(fn);
    if (!fout.is_open())
    {
        cout << "can't open "<< fn << ". Bye.\n";
        exit(EXIT_FAILURE);
    }
    double objective;
    cout << "Enter the focal length of you "
     << "telescope objective in mm:";
    cin >>objective;
    double eps[LIMIT];
    cout << "Enter the focal lengths, in mm, of " << LIMIT <<" eyepiece:\n";
    for (int i = 0; i < LIMIT; i++)
    {
        cout << "Eyepiece #" << i +1 <<": ";
        cin >> eps[i];
    }
    file_it(fout, objective, eps, LIMIT);
    file_it(cout, objective, eps, LIMIT);
    cout << "Done\n";
    return 0;
}

void file_it (ostream & os, double fo, const double fe[], int n)
{
    ios_base::fmtflags initial;//fmtflags 存储格式的数据类型
    //如果初始化没有做出修改将一直保留格式直到修改
    initial = os.setf(ios_base::fixed);//save initial formatting 定点表示 
    os.precision(0); //指定显示多少位小数
    os<<"Focal length of objective: "<< fo << "mm\n";
    os.setf(ios::showpoint);//显示小数
    os.precision(1);
    os.width(12);//输出字段宽度 只在显示下个值的时候有效，之后恢复默认0宽度
    os<<"f.1. eyepiece";
    os.width(15);
    os<<"magnificantion"<<endl;
    for (int i = 0; i<n; i++)
    {
        os.width(12);
        os<<fe[i];
        os.width(15);
        os<< int (fo/fe[i] +0.5)<<endl;
    }
    os.setf(initial);
}