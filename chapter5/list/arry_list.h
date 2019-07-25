#ifndef ARRY_LIST_
#define ARRY_LIST_
#include "base_liner.h"
template<class T>
class arrayList : public linearList<T>
{
    public:
        arrayList(int initialCapacity = 10);
        arrayList(const arrayList<T>&);
        ~arrayList() {delete [] element;}

        //ADT function
        bool empty() const {return listSize == 0;};
        int size() const {return listSize;};
        T& get(int theIndex) const;
        int indexOf(const T& theElement) const;
        void erase(int theIndex);
        void insert(int theIndex, const T& theElement);
        void output(std::ostream& out) const; 
        int getarrayLength() {return arrayLength;}
        int getlistSize() {return listSize;}

        //other function
        int capacity() const {return arrayLength;}



    private:
        void checkIndex(int theIndex) const;


        T * element;
        int arrayLength;
        int listSize;
};

#endif
