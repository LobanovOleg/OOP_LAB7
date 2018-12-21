#ifndef PENTAGON_H
#define PENTAGON_H

#include <iostream>
#include <cstdlib>
#include "Figure.h"

class Pentagon: public Figure{
public:
    Pentagon();
    Pentagon(std::istream &is);
    Pentagon(size_t i, size_t j);
    Pentagon(const Pentagon& orig);
    friend std::ostream& operator << (std::ostream& os, const Pentagon& obj);
    Pentagon& operator = (const Pentagon& right);
    Pentagon *Get();
    void Print() override;
    int WAT() override;
    double Square() override;
    ~Pentagon();
    friend class TVector;
private:
    size_t side_a;
    size_t side_b;
};

#endif