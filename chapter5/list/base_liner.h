#ifndef BASE_LINER_
#define BASE_LINER_

#include <iostream>
#include <algorithm>
using namespace std;
template<class T>
class linearList
{
    public:
        virtual ~linearList() {};
        virtual bool empty() const = 0;
        virtual int size() const = 0;
        virtual T& get(int theIndex) const = 0;
        virtual int indexOf(const T& theElement) const = 0;
        virtual void erase(int theIndex) = 0;
        virtual void insert(int theIndex, const T& theElement) = 0;
        virtual void output(std::ostream& out) const = 0; 

        void changeLength1D(T*& a, int oldLength, int newLength)
        {
            // if (newLength < 0)
            //     throw illegalParameterValue("new length must be >= 0!");
            T* temp = new T(newLength);
            int number = std::min(oldLength, newLength);
            std::copy(a, a+number, temp);
            delete [] a; //release old version arry memory
            a = temp;
        }
};

#endif