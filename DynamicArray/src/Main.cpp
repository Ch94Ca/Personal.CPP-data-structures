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

        cout << "Array Size: " << array.get_size() << endl;

        for(unsigned int i = 0; i < array.get_size(); i++)
        {
                array.modifyElement(i, i);

        }

        array.print();

        array.insertLast(99);
        array.insertFirst(99);
        array.insertAt(5, 99);

        array.print();

        for(unsigned int i = 0; i < array.get_size(); i++)
        {
                array.modifyElement(i, i+1);

        } // end for

        array.print();

        array.resize(10);
        array.print();

        array.insertAt(5, 99);
        array.print();

        array.deleteElement(5);
        array.deleteElement(0);
        array.deleteElement(array.get_size());
        array.print();

        array.deleteArray();
        array.print();

        array.insertFirst(10);
        array.print();

        array.deleteArray();
        array.insertLast(10);
        array.print();

        array.insertAt(15, 99);
        array.print();

        return 0;

} // End Main
