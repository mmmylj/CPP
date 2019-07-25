#include "arry_list.h"
#include <iostream>
using namespace std;
template  <class T>
void checklist(arrayList<T> & arraylist);

int main()
{
    arrayList<double> y(10);
    // checklist(y);
}

template  <class T>
void checklist(arrayList<T> & arraylist)
{
    cout << "arrayLength is " << arraylist.getarrayLength();
    cout << "listSize is" << arraylist.getlistSize();
}