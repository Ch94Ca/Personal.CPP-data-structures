/*
 *  Stack
 * 
 *  Author: Carlos Henrique Silva Correia de Araujo
 *  Computer engineering - UFPB (Undergraduate)
 *  github.com/Ch94Ca
 * 
 *  Description:
 *     
 *    Stack implementation using DynamicArray.
 * 
 *     Supported operations:
 *      
 *      - get_size:
 *          return stack size
 *
 *      - push:
 *          push (insert) element in stack top
 *
 *      - pop:
 *          pop (return and remove) element in stack top
 *
 *      - peek:
 *          peek (return only) element in stack top
 *
 *      - isEmpty:
 *          return true if stack is empty and false if not
 *
 *      - deleteStack:
 *          delete entire stack
 *
 *      - print:
 *          print all elements in the stack
 *
 */

#ifndef STACK_HPP
#define STACK_HPP

#include "DynamicArray.hpp"

class Stack
{
    private:

        DynamicArray stack;
        
    public:

        Stack();

        unsigned int get_size();

        void push(int data);     
        int pop();
        int peek();
        bool isEmpty();
        void deleteStack();

        void print();

}; // end Stack

#endif
