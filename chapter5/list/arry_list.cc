#include "arry_list.h"
template <class T>
arrayList<T>::arrayList(int initialCapacity)
{
    if (initialCapacity <= 0)
        {
            std::ostringstream s;
            s << "InitialCapacity = " << initialCapacity << "must be > 0!";
            throw illegalParameterValue(s.str());
        }
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
    
}