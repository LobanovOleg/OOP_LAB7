#include "Trapeze.h"
#include <iostream>

Trapeze::Trapeze() : Trapeze(0, 0, 0) { }
Trapeze::Trapeze(size_t i, size_t j, size_t k) : side_a(i), side_b(j), side_c(k){
    std::cout << "Трапеция создана: " << side_a <<std::endl;  
}

Trapeze::Trapeze(std::istream &is){
    is >> side_a;
    is >> side_b;
    is >> side_c;
}

Trapeze::Trapeze(const Trapeze& orig){
    std::cout << "Копия трапеции создана: " << std::endl;
    side_a = orig.side_a;
    side_b = orig.side_b;
    side_c = orig.side_c;
}

int Trapeze::WAT(){
    return 2;
}

double Trapeze::Square(){
    return ((side_a + side_b) * side_c);
}

std:: ostream& operator << (std::ostream& os, const Trapeze& obj){
    os << "a= " << obj.side_a << ", b= " << obj.side_b << ", c= " << obj.side_c << std::endl;
    return os;
}

Trapeze *Trapeze::Get(){
    return this;
}

void Trapeze::Print(){
    std::cout << "a= " << side_a << ", b=" << side_b << ", c=" << side_c << std::endl;
}

Trapeze& Trapeze::operator = (const Trapeze& right) {
    if (this == &right){
        return *this;
    }
    side_a = right.side_a;
    side_b = right.side_b;
    side_c = right.side_c;
    return *this;
}

Trapeze::~Trapeze(){
    std::cout << "Трапеция удалена" << std::endl;
}