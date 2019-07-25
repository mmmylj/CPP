#include "arry_list.h"
#include "base_liner.h"
#include <iostream>
using namespace std;

template <class T>
arrayList<T>::arrayList(int initialCapacity)
{
    // if (initialCapacity <= 0)
    //     {
    //         std::ostringstream s;
    //         s << "InitialCapacity = " << initialCapacity << "must be > 0!";
    //         throw illegalParameterValue(s.str());
    //     }
    arrayLength = initialCapacity;
    element = new T(arrayLength);
    listSize = 0;
}

template<class T>
arrayList<T>::arrayList(const arrayList<T>& theList)
{
    arrayLength = theList.arrayLength;
    listSize = theList.listSize;
    element = new T(arrayLength);
    std::copy(theList, theList.element+arrayLength, element);
}

template <class T>
void arrayList<T>::checkIndex(int theIndex) const
{
    if (theIndex < 0 || theIndex >= listSize)
       std::cout << "error Index";
    // {
    //     std::ostringstream s;
    //     s << "index = " theIndex << "size = " << listSize;
    //     throw illegalParamentValue(s.str());
    // }
}

template <class T>
T& arrayList<T>::get(int theIndex) const
{
    checkIndex(theIndex);
    return element[theIndex];
}

template<class T>
int arrayList<T>::indexOf(const T& theElement) const
{
    int theIndex = (int) (std::find(element, element+listSize, theElement)-element);
    if(theIndex == listSize)
        return -1;
    else 
        return theIndex;
}

template <class T>
void arrayList<T>::erase(int theIndex)
{
    checkIndex(theIndex);
    copy(element+theIndex+1,element+listSize,element+theIndex);
    
    element[--listSize].~T(); //调用析构释放T内存
}

template <class T>
void arrayList<T>::insert(int theIndex, const T& theElement)
{
    checkIndex(theIndex);
    
    if (listSize == arrayLength)
        {//数组空间已满，数组长度倍增
            changeLength1D(element, arrayLength, 2 * arrayLength);
            arrayLength *= 2;
        }
    copy_backward(element+theIndex, element+listSize, element+listSize+1);

    element[theIndex] = theElement;
    listSize++;
}

template <class T>
void arrayList<T>::output(ostream& out) const
{
    copy(element, element+listSize, ostreambuf_iterator<T>(cout, " "));
}

template <class T>
ostream operator<<(ostream out, const arrayList<T>& x)
{
    x.output(out);
    return out;
}

