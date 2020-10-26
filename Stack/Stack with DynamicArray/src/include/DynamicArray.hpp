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

class DynamicArray
{

    private:

        int *array;
        unsigned int size;

    public:

        DynamicArray();
        DynamicArray(unsigned int size);

        void resize(unsigned int newSize);

        int get(unsigned int index);
        unsigned int get_size();
        void print();

        void insertFirst(int data);
        void insertLast(int data);
        void insertAt(unsigned int index, int data);
        void modifyElement(unsigned int index, int data);
        void deleteElement(unsigned int index);
        void deleteArray();    

}; // end DynamicArray

#endif