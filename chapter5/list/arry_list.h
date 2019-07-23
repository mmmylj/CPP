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
        virtual bool empty();
        virtual int size();
        virtual T& get(int theIndex);
        virtual int indexOf(const t& theElement);
        virtual void erase(int theIndex);
        virtual void insert(int theIndex, const T& theElement);
        virtual void output(std::ostream& out); 


        //other function
        int capacity() const {return arrayLength}



    private:
        checkIndex(int theIndex) const;


        T * element;
        int arrayLength;
        int listSize;
};

#endif