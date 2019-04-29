#include <cmath>
#include "vector.h"

using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR
{
    const double Rad_to_dag = 45.0 / atan(1.0);

    //private method
    void Vector::set_mag()
    {
        mag = sqrt(x*x + y*y);
    }

    void Vector::set_ang()
    {
        if (x == 0.0 && y == 0.0)
            ang = 0.0;
        else
            ang = atan2(y, x);
    }

    void Vector::set_x()
    {
        x = mag * sin(ang);
    }

    void Vector::set_y()
    {
        y = mag * sin(ang);
        mode = RECT;
    }

    //public method

    Vector::Vector()
    {
        x = y = ang = mag = 0;
    }

    Vector::Vector(double n1, double n2, Mode form)
    {
        mode = form;
        if (mode == RECT)
        {
            x = n1;
            y = n2;
            set_ang();
            set_mag();
        } 
        else if(mode = POL)
        {
            mag = n1;
            ang = n2;
            set_x();
            set_y();
        }
        else
        {
            cout << "Incorrect 3rd argument to Vector() --";
            cout << "vector set to 0\n";
            x = y = mag = ang = 0.0;
            mode = RECT;
        }
    }

    Vector::~Vector()
    {

    }


    void Vector::reset(double n1, double n2, Mode form)
    {
        mode = form;
        if (mode == RECT)
        {
            x = n1;
            y = n2;
            set_ang();
            set_mag();
        } 
        else if(mode = POL)
        {
            mag = n1;
            ang = n2;
            set_x();
            set_y();
        }
        else
        {
            cout << "Incorrect 3rd argument to Vector() --";
            cout << "vector set to 0\n";
            x = y = mag = ang = 0.0;
            mode = RECT;
        }
    }

    void Vector::polar_mode()
    {
        mode = POL;
    }

    void Vector::rect_mode()
    {
        mode = RECT; 
    }

    Vector Vector::operator+(const Vector & b) const
    {
        return Vector(x+b.x, y+b.y);
    }

    Vector Vector::operator-(const Vector & b) const
    {
        return Vector(x-b.x, y-b.y);
    }

    Vector Vector::operator-() const
    {
        return Vector(-x, -y);
    } 

    Vector Vector::operator*(double n) const
    {
        return Vector(x*n, y*n);
    }

    Vector operator*(double n, const Vector & a)
    {
        return a * n;
    }

    std::ostream & operator<<(std::ostream & os, const Vector & a)
    {
        if (a.mode == Vector::RECT)
            os << "(x, y) = (" << a.x <<", " << a.y << ")";
        else if (a.mode == Vector::POL)
            os << "(m ,a) = (" << a.mag << ", " << a.ang <<")";
        else
            os << "Vector object mode is invaild";
        return os;
    }
} // VECTOR
