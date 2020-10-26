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
    stack.insertFirstNode(data);

} // end push

int Stack::pop()
{
    int retData = stack.get(0);
    stack.deleteNode(0);

    return retData;

} // end pop

int Stack::peek()
{
    return stack.get(0);

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
    stack.deleteList();

} // end deleteStack

void Stack::print()
{
    stack.print();

} // end print