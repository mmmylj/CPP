#ifndef ARRY_LIST_
#define ARRY_LIST_
#include "base_liner.h"
template<class T>
class arrayList : public linearList<T>
{
    public:
        arrayList(int initialCapacity = 10);
        arrayList(const arrayList<T>&);
        ~arrayList() {delete [] element}

        //ADT function
        virtual bool empty() const;
        virtual int size() const;
        virtual T& get(int theIndex) const;
        virtual int indexOf(const T& theElement) const;
        virtual void erase(int theIndex);
        virtual void insert(int theIndex, const T& theElement);
        virtual void output(std::ostream& out) const; 

        //other function
        int capacity() const {return arrayLength}



    private:
        void checkIndex(int theIndex) const;


        T * element;
        int arrayLength;
        int listSize;
};

#endif