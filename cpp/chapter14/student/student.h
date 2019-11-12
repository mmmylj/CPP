#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include <string>
#include <valarray>

class Student
{
private:
    typedef std::valarray<double> ArrayDb;
    std::string name;
    ArrayDb scores;
    //private method for scores output
    std::ostream & arr_out(std::ostream & os) const;

public:
    Student() : name("Null Student"), scores() {}

    explicit Student(const std::string & s) : name(s), scores() {}

    explicit Student(int n) : name("Nully"), scores(n) {}

    Student(const std::string & s, const int n) : name(s), scores(n) {}

    Student(const std::string & s, ArrayDb & a) : name(s), scores(a) {}

    Student(const char * str, const double * pd, int n) : name(str), scores(pd, n) {}    
    
    ~Student() {};

    double Average() const;
    const std::string & Name() const;
    double & operator[](int i);
    double operator[](int i) const;

    //friends
    //input
    friend std::istream & operator>>(std::istream & is, Student & stu); //1 word
    friend std::istream & getline(std::istream & is,
                                    Student & stu); //1 line
    //output
    friend std::ostream & operator<<(std::ostream & os,
                                        const Student & stu);
};

#endif