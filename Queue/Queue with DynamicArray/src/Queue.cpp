/*
 *   AUTOR: Carlos Henrique Silva Correia de Araujo
 *   ENGENHARIA DE COMPUTAÇÃO - UFPB
 *   https://github.com/ch94ca
 *     
 */ 

#include <iostream>
#include "include/Queue.hpp"

Queue::Queue()
{

} // end class constructor

unsigned int Queue::get_size()
{   
    return queue.get_size();

} // end get_size

void Queue::enqueue(int data)
{
    queue.insertLast(data);

} // end enqueue

int Queue::dequeue()
{
    int retVal = queue.get(0);
    queue.deleteElement(0);

    return retVal;

} // end dequeue

int Queue::peek()
{
    return queue.get(0);

} // end peek

bool Queue::isEmpty()
{   
    if(queue.get_size() == 0)
    {
        return true;

    } // end if
    else
    {
        return false;

    } // end else
 
} // end isEmpty

void Queue::emptyQueue()
{
    queue.deleteArray();

} // end emptyQueue

void Queue::print()
{
    queue.print();

} // end print