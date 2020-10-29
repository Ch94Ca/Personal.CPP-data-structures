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

#include "include/DynamicArray.hpp"
#include <cstdlib>
#include <iostream>

DynamicArray::DynamicArray()
{
    array = nullptr;
    size = 0;

} // end class constructor

DynamicArray::DynamicArray(unsigned int size)
{
    try
    {
        array = new int[size];

    } // end try
    catch (std::bad_alloc &)
    {
        std::cout << "Memory allocation failure." << std::endl;
        exit(1);

    } // end catch

    this->size = size;

    for(unsigned int i = 0; i < size; i++)
    {
        array[i] = 0;

    } // end for

} // end class constructor

void DynamicArray::resize(unsigned int newSize)
{   
    int *tempArray;
    
    try
    {
        tempArray = new int[newSize];

    } // end try
    catch (std::bad_alloc &)
    {
        std::cout << "Memory allocation failure." << std::endl;
        exit(1);

    } // end catch

    for(unsigned int i = 0; i < size; i++)
    {
        tempArray[i] = array[i];

    } // end for

    for(unsigned int i = size; i < newSize; i++)
    {
        tempArray[i] = 0;

    } // end for

    this->size = newSize;

    delete(array);

    array = tempArray;

} // end resize

int DynamicArray::get(unsigned int index)
{
    return array[index];

} // end get

unsigned int DynamicArray::get_size()
{
    return size;

} // end get_size

void DynamicArray::print()
{
    std::cout << "{";

    for(unsigned int i = 0; i < size; i++)
    {
        std::cout << array[i];

        if(i != size - 1)
        {
            std::cout << ", ";

        } // end if

    } // end for

    std::cout << "}" << std::endl;

} // end print

void DynamicArray::insertFirst(int data)
{
    this->resize(size + 1);

    for(unsigned int i = (size - 1); i > 0; i--)
    {
        array[i] = array [i - 1];

    } // end if
    
    array[0] = data;

} // end insertFirst

void DynamicArray::insertLast(int data)
{
    this->resize(size + 1);

    array[size - 1] = data;

} // end insert data

void DynamicArray::insertAt(unsigned int index, int data)
{   
    if(index < size)
    {
        this->resize(size + 1);

        for(unsigned int i = (size - 1); i > index; i--)
        {
            array[i] = array [i - 1];

        } // end if
        

        array[index] = data;
    
    } // end if
    else
    {
        unsigned int previousSize = size;

        this->resize(index + 1);

        for(unsigned int i = previousSize; i < size; i++)
        {
            array[i] = 0;

        } // end for

        array[index] = data;

    } // end if

} // end insertAt

void DynamicArray::modifyElement(unsigned int index, int data)
{
    array[index] = data;

} // end modifyElement

void DynamicArray::deleteElement(unsigned int index)
{   
    if(size == 1)
    {
        this->deleteArray();
        return;

    } // end if

    for(unsigned int i = index; i < size; i++)
    {
        array[i] = array[i + 1];

    } // end if

    this->resize(size - 1);

} // end DynamicArray

void DynamicArray::deleteArray()
{
    delete(array);
    array = nullptr;
    size = 0;

} // end deleteArray

