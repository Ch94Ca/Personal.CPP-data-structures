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