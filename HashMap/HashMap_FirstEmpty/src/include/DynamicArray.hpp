/*
 *  Dynamic Array
 * 
 *  Author: Carlos Henrique Silva Correia de Araujo
 *  Computer engineering - UFPB (Undergraduate)
 *  github.com/Ch94Ca
 * 
 *  Description:
 *     
 *    Dynamic Array implementation.
 * 
 *     Supported operations:
 *      
 *      - resize:
 *          resize array size
 *
 *      - get:
 *          return array content by index
 *
 *      - get_size:
 *          return array size
 *
 *      - print:
 *          print entire array data
 *
 *      - insertFirst:
 *          insert element in the first position of array
 *
 *      - insertLast:
 *          insert element in the last position of array
 *
 *      - insertAt:
 *          insert element in array middle by index
 *
 *      - modifyElement:
 *          modify array element by index
 *
 *      - deleteElement:
 *          delete array element by index
 *
 *      - deleteArray:
 *          delete entire array
 */

#ifndef DYNAMICARRAY_HPP
#define DYNAMICARRAY_HPP

#include <string>

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