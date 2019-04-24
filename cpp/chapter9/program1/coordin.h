#ifndef COORDIN_H_
//如果程序包含COORDIN_H_,则跳到endif
//如果一个文件包含同一个结构两次，则会报错。故而一个文件只能包含一个头文件一次
//使用该办法可以仅让第一次包含该头文件时有意义 
#define COORCIN_H_

struct polar
{
    double distance;
    double angle;
};

struct rect
{
    double x;
    double y;
};

polar rect_to_polar(rect xypos);
void show_polar(polar dapos);

#endif