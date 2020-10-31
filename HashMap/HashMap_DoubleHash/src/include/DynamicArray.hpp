/*
 *  Author: Carlos Henrique Silva Correia de Araujo
 *  Computer engineering - UFPB (Undergraduate)
 *  github.com/Ch94Ca
 *
 *  Description:
 *     
 *     DynamicArray class implementation
 *    
 */ 

#ifndef DYNAMICARRAY_HPP
#define DYNAMICARRAY_HPP

#include <string>
#include <array>

struct arrayData
{   
    unsigned long int cpf;
    std::string name;

}; // end arrayData

class DynamicArray
{
    private:

        arrayData *array;
        unsigned int size;

    public:

        DynamicArray();
        DynamicArray(unsigned int startSize);

        void resize(unsigned int newSize);

        arrayData get(unsigned int index);
        unsigned int get_size();
        void print();

        void insertFirst(arrayData data);
        void insertLast(arrayData data);
        void insertAt(unsigned int index, arrayData data);
        void modifyElement(unsigned int index, arrayData data);
        void deleteElement(unsigned int index);
        void deleteArray();    

}; // end DynamicArray

#endif