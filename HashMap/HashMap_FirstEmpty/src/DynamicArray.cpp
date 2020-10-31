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
        array = new arrayData[size];

    } // end try
    catch (std::bad_alloc &)
    {
        std::cout << "Memory allocation failure." << std::endl;
        exit(1);

    } // end catch

    this->size = size;

    for(unsigned int i = 0; i < size; i++)
    {
        array[i].name = "";
        array[i].cpf = 0;

    } // end for

} // end class constructor

void DynamicArray::resize(unsigned int newSize)
{   
    arrayData *tempArray;

    try
    {
        tempArray = new arrayData[newSize];

    } // end try
    catch (std::bad_alloc &)
    {
        std::cout << "Memory allocation failure." << std::endl;
        exit(1);

    } // end catch

    for(unsigned int i = 0; i < newSize; i++)
    {
        if(i < size)
        {
            tempArray[i] = array[i];

        } // end if
        else
        {
            tempArray[i].cpf = 0;
            tempArray[i].name = "";

        } // end else

    } // end for

    delete[] array;

    try
    {
        array = new arrayData[newSize];

    } // end try
    catch (std::bad_alloc &)
    {
        std::cout << "Memory allocation failure." << std::endl;
        exit(1);

    } // end catch

    for(unsigned int i = 0; i < newSize; i++)
    {
        array[i].cpf = tempArray[i].cpf;
        array[i].name = tempArray[i].name;

    } // end for

    delete[] tempArray;

    size = newSize;
    
} // end resize

arrayData DynamicArray::get(unsigned int index)
{
    return array[index];

} // end get

unsigned int DynamicArray::get_size()
{
    return size;

} // end get_size

void DynamicArray::print()
{
    for(unsigned int i = 0; i < size; i++)
    {
        std::cout << "Array #" << i << " data:" << std::endl;
        std::cout << "Name: " << array[i].name << std::endl;
        std::cout << "CPF: " << array[i].cpf << std::endl << std::endl;

    } // end for

} // end print

void DynamicArray::insertFirst(arrayData data)
{
    this->resize(size + 1);

    for(unsigned int i = (size - 1); i > 0; i--)
    {
        array[i] = array [i - 1];

    } // end if
    
    array[0] = data;

} // end insertFirst

void DynamicArray::insertLast(arrayData data)
{
    this->resize(size + 1);

    array[size - 1] = data;

} // end insert data

void DynamicArray::insertAt(unsigned int index, arrayData data)
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
            array[i].name = " ";
            array[i].cpf = 0;

        } // end for

        array[index] = data;

    } // end if

} // end insertAt

void DynamicArray::modifyElement(unsigned int index, arrayData data)
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
    delete[] array;
    array = nullptr;
    size = 0;

} // end deleteArray

