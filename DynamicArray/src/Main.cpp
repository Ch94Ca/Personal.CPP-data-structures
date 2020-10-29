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
        DynamicArray array;

        cout << "Array Size: " << array.get_size() << endl;

        array.print();

        for(unsigned int i = 0; i < 10; i++)
        {
                array.insertLast(i + 1);

        }  // end for

        array.print();
        cout << "Array Size: " << array.get_size() << endl;

        array.resize(15);
        array.print();
        cout << "Array Size: " << array.get_size() << endl;
        
        array.resize(5);
        array.print();
        cout << "Array Size: " << array.get_size() << endl;

        array.deleteElement(1);
        array.deleteElement(2);
        array.deleteElement(3);

        array.print();
        cout << "Array Size: " << array.get_size() << endl;

        array.deleteArray();
        array.print();
        cout << "Array Size: " << array.get_size() << endl;

        return 0;

} // End Main
