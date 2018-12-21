#ifndef RHOMBUS_H
#define RHOMBUS_H

#include <iostream>
#include <cstdlib>
#include "Figure.h"

class Rhombus: public Figure{
public:
    Rhombus();
    Rhombus(std::istream &is);
    Rhombus(size_t i);
    Rhombus(const Rhombus& orig);
    friend std::ostream& operator << (std::ostream& os, const Rhombus& obj);
    Rhombus& operator = (const Rhombus& right);
    Rhombus *Get();
    void Print() override;
    int WAT() override;
    double Square() override;
    ~Rhombus();
    friend class TVector;
private:
    size_t side_a;
};

#endif