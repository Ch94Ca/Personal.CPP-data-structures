/*
 *   AUTOR: Carlos Henrique Silva Correia de Araujo
 *   ENGENHARIA DE COMPUTAÇÃO - UFPB
 *   https://github.com/ch94ca
 *     
 */ 

#ifndef STACK_HPP
#define STACK_HPP

#include "DynamicArray.hpp"

class Queue

{
    private:

        DynamicArray queue;
        
    public:

        Queue();

        unsigned int get_size();

        void enqueue(int data);     
        int dequeue();
        int peek();
        bool isEmpty();
        void emptyQueue();

        void print();

}; // end Queue

#endif
