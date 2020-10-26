/*
 *   AUTOR: Carlos Henrique Silva Correia de Araujo
 *   ENGENHARIA DE COMPUTAÇÃO - UFPB
 *   https://github.com/ch94ca
 *     
 */ 

#ifndef STACK_HPP
#define STACK_HPP

#include "DoublyLinkedList.hpp"

class Queue

{
    private:

        DoublyLinkedList queue;
        
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
