/*
 *  Author: Carlos Henrique Silva Correia de Araujo
 *  Computer engineering - UFPB (Undergraduate)
 *  github.com/Ch94Ca
 *
 *  Description:
 *     
 *     Doubly linked list class implementation
 *    
 */ 

#include <iostream>
#include "include/DynamicArray.hpp"

using namespace std;

int main(void)
{
        DynamicArray array(10);

        cout << "Array Size: " << array.getSize() << endl;

        for(unsigned int i = 0; i < array.getSize(); i++)
        {
                array.modifyElement(i, i);

        }

        array.print();

        array.insertLast(99);
        array.insertFirst(99);
        array.insertAt(5, 99);

        array.print();

        for(unsigned int i = 0; i < array.getSize(); i++)
        {
                array.modifyElement(i, i+1);

        } // end for

        array.print();

        array.resize(10);
        array.print();

        array.insertAt(5, 99);
        array.print();

        array.deleteElement(5);
        array.print();

        array.deleteArray();
        array.print();

        return 0;

} // End Main
