#ifndef TITERATOR_H
#define TITERATOR_H 

#include <memory>
#include <iostream>
#include "Vector.h"


template <class T> class TIterator {
public:
    
    TIterator(std::shared_ptr<T> *n) {
        ptr = n;
    }
    
    std::shared_ptr<T> operator * () {
        return *ptr;
    }
    
    std::shared_ptr<T> operator -> () {
        return ptr->GetValue();
    }
    
    void operator ++ () {
            ++ptr;
    }
    
    TIterator operator ++ (int) {
        TIterator iter(*this);
        ++(*this);
        return iter;
    }
    
    bool operator == (TIterator const& i) {
        return ptr == i.ptr;
    }
    
    bool operator != (TIterator const& i) {
        return !(*this == i);
    }
private:
    
    std::shared_ptr<T> *ptr;
};

#endif