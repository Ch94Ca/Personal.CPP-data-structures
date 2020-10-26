/*
 *   AUTOR: Carlos Henrique Silva Correia de Araujo
 *   ENGENHARIA DE COMPUTAÇÃO - UFPB
 *   https://github.com/ch94ca
 *     
 */ 

#include <iostream>
#include "include/Stack.hpp"

Stack::Stack()
{

} // end class constructor

unsigned int Stack::get_size()
{
    return stack.get_size();

} // end get_size

void Stack::push(int data)
{
    stack.insertLast(data);

} // end push

int Stack::pop()
{   
    unsigned int stackSize = stack.get_size();
    int retData = stack.get(stackSize - 1);

    stack.resize(stackSize - 1);

    return retData;

} // end pop

int Stack::peek()
{
    return stack.get(stack.get_size() - 1);

} // end peek

bool Stack::isEmpty()
{
    if(stack.get_size() == 0)
    {
        return true;

    } // end if
    else
    {
        return false;

    } // end else

} // end isempty

void Stack::emptyStack()
{
    stack.deleteArray();

} // end deleteStack

void Stack::print()
{
    stack.print();

} // end print