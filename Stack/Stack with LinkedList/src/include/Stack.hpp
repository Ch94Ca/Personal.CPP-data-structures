/*
 *   AUTOR: Carlos Henrique Silva Correia de Araujo
 *   ENGENHARIA DE COMPUTAÇÃO - UFPB
 *   https://github.com/ch94ca
 *     
 */ 

#ifndef STACK_HPP
#define STACK_HPP

#include "LinkedList.hpp"

class Stack
{
    private:

        LinkedList stack;
        
    public:

        Stack();

        unsigned int get_size();

        void push(int data);     
        int pop();
        int peek();
        bool isEmpty();
        void emptyStack();

        void print();

}; // end Stack

#endif
