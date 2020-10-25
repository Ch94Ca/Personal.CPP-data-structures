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
    array = (int*) malloc(sizeof(int) * size);

    if(array == NULL)
    {
        std::cout << "Memory Allocation Failed" << std::endl;
        exit(1);

    } // end if

    this->size = size;

} // end class constructor

void DynamicArray::resize(unsigned int newSize)
{
    array = (int*) realloc(array, sizeof(int) * newSize);

    if(array == NULL)
    {
        std::cout << "Memory Re-allocation Failed" << std::endl;
        exit(1);

    } // end if

    size = newSize;

} // end resize

int DynamicArray::get(unsigned int index)
{
    return array[index];

} // end get

unsigned int DynamicArray::getSize()
{
    return size;

} // end getSize

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
    this->resize(size + 1);

    for(unsigned int i = (size - 1); i > index; i--)
    {
        array[i] = array [i - 1];

    } // end if
    
    array[index] = data;

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
    free(array);
    array = nullptr;
    size = 0;

} // end deleteArray

