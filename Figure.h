#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>

class Figure{
public:
    virtual void Print() = 0; // изменнеия трапеции, пятиугольника и ромба
    virtual double Square() = 0; // изменение для трапеции треуголника и пятиугоьника
    virtual int WAT() = 0;
    virtual ~Figure(){};
};

#endif