#ifndef VECTOR_H
#define VECTOR_H

#include <memory>

#include "Figure.h"
#include "Rhombus.h"
#include "Pentagon.h"
#include "Trapeze.h"
#include "Iterator.h"
#include "TAllocationBlock.h"
#include <stdlib.h>

template <class T> class TLolVector{
public:
    TLolVector(int vCol); // конструктор класса
    void Push(std::shared_ptr<T> &temp); //добавление элемента в класс
    void SubPush(std::shared_ptr<Figure> &temp); //добавление элемента в класс
    void Get(int ind1, int ind2); // получение элемента класса
    void Delete(); // удаоение последнего элемента класса
    void DDelete(int ind); // удаление последнего элемента класса
    void TDelete(int ind); // удаление по индексу
    void SDelete(double ind); // удаление по индексу
    template <class A> friend std::ostream& operator << (std::ostream& os, const TLolVector<A>& vector); //вывод на стандартный поток
    ~TLolVector(); // деструктор класса
    void DeleteAll();
    TIterator<T> begin(); // установка итератора начало
    TIterator<T> end(); // установка итератора конца
    int GetSize(); // получение размра класса
    int GetCapacity(); // получить капасити
    std::shared_ptr<T> *GetArray(); // получить массив
    void MySort(int l, int r, std::shared_ptr<Figure> *array);
    void * operator new (size_t size); // переопределенный оператор выделения памяти из кучи
    void operator delete(void *p); // возвращение в кучу

private:
    void ResizeVector(std::shared_ptr<T> *&array); // изменеие размера вектора
    int size; // текущее количество элементов
    int capacity; // выделенное место 
    std::shared_ptr<T> *array; // массив

    static TAllocationBlock vector_allocator;
};

const int INCREASE = 2;
template <class T> TLolVector<T>::TLolVector(int vCol){
    array = new std::shared_ptr<T> [vCol];
    size = 0;
    capacity = vCol;
}

template <class T> std::shared_ptr<T> *TLolVector<T>::GetArray(){
    return array;
}

template <class T> TAllocationBlock TLolVector<T>::vector_allocator(sizeof(TLolVector<T>), 100);

template <class T> void TLolVector<T>::MySort(int l, int r, std::shared_ptr<Figure> *array){
    int x = l + (r - l) / 2;
    int i = l;
    int j = r;

    while (i <= j){
        while (array[i] -> Square() < array[x] -> Square()){
            i++;
        }
        while (array[j] -> Square() > array[x] -> Square()){
            j--;
        }
        if (i <= j) {
            std::shared_ptr<Figure> tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
            i++;
            j--;
        }
    }
    if (i < r){
        MySort(i, r, array);
    }
    if (l < j){
        MySort(l, j, array);
    }
}

template <class T> void TLolVector<T>::ResizeVector(std::shared_ptr<T> *&array){
    capacity *= INCREASE;
    std::shared_ptr<T> *tmp = new std::shared_ptr<T> [capacity];
    for (int i = 0; i < size; i++){
        tmp[i] = array[i];
        array[i] = nullptr;
    }
    delete [] array;
    array = nullptr;
    array = tmp;
    tmp = nullptr;
}

template <class T> void TLolVector<T>::Push(std::shared_ptr<T> &temp){
    if (size == capacity){
        ResizeVector(array);
    }
    array[size] = temp;
    ++size;
}

template <class T> void TLolVector<T>::SubPush(std::shared_ptr<Figure> &temp){
    int i =0;
    int end = size;
    while (i == 0 || i <end){
        if (size == 0 || (array[i] -> GetSize() == 5 && i + 1 == end)){
            TLolVector<Figure> *kon = new TLolVector<Figure> (5);
            std::shared_ptr<TLolVector<Figure>> pp = std::shared_ptr<TLolVector<Figure>> (kon);
            Push(pp);
            ++i;
            break;
        } else if (array[i] -> GetSize() != 5){
            break;
        }
        ++i;
    }
    if(size == i){
        --i;
    }
    printf("i = %d\n", i);
    (*(array + i)) -> Push(temp);
    if (array[i] -> GetSize() > 1){
        MySort(0, array[i] -> GetSize() - 1, (*(array + i)) -> GetArray());
    }
}

template <class T> void TLolVector<T>::Get(int ind1, int ind2){
    (*(*array[ind1]) + ind2) -> Print();
}

template <class T> void TLolVector<T>::Delete(){
    array[--size] -> ~T();
}

template <class T> void * TLolVector<T>::operator new (size_t size){
    return vector_allocator.allocate();
}

template <class T> void  TLolVector<T>::operator delete(void *p){
    vector_allocator.deallocate(p);
}

template <class T> void TLolVector<T>::TDelete(int ind){
    for(int i = 0; i < size; ++i){
        for(int j = 0; j < (*(array + i)) -> GetSize(); ++j){
            if ((*((*(array + i)) ->GetArray() + j)) -> WAT() == ind){
                (*(array + i)) -> DDelete(j);
            }
        }
    }
    for(int i = 0; i < size; ++i){
        if ((*(array + i)) -> GetSize() == 0){
            DDelete(i);
        }
    }
}

template <class T> void TLolVector<T>::SDelete(double ind){
    for(int i = 0; i < size; ++i){
        for(int j = 0; j < (*(array + i)) -> GetSize(); ++j){
            if ((*((*(array + i)) -> GetArray() + j)) -> Square() == ind){
                (*(array + i)) -> DDelete(j);
            }
        }
    }
    for(int i = 0; i < size; ++i){
        if((*(array + i)) -> GetSize() == 0){
            DDelete(i);
        }
    }
}

template <class T> void TLolVector<T>::DDelete(int ind) {
    std::shared_ptr<T> tmp;
    for (int i = ind; i < size; ++i){
        tmp = array[i];
        array[i] = array[i + 1];
    }
    Delete();
}

template <class T> TIterator<T> TLolVector<T>::begin(){
    return TIterator<T>(array);
}

template <class T> TIterator<T> TLolVector<T>::end(){
    return TIterator<T> (array + size); 
}

template <class T> TLolVector<T>::~TLolVector(){
    for(int i = 0; i <size; ++i){
        array [i] = nullptr;
    }
    delete [] array;
    array = nullptr;
    capacity = size = 0;
}

template <class T> std::ostream& operator << (std::ostream& os, const TLolVector<T>& vector){
    for(int j = 0; j < vector.size; ++j){
        printf("Array %d\n", j);
        printf("Size %d:\n", vector.array[j] -> size);
        for(int i = 0; i < vector.array[j] -> size; ++i){
            vector.array[j] -> array[i] -> Print();
        }
        printf("==================\n");
    }
    return os;
}

template <class T> int TLolVector<T>::GetSize(){
    return size;
}

template <class T> int TLolVector<T>::GetCapacity(){
    return capacity;
}

#endif