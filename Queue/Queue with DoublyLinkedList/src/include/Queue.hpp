/*
 *  Queue
 * 
 *  Author: Carlos Henrique Silva Correia de Araujo
 *  Computer engineering - UFPB (Undergraduate)
 *  github.com/Ch94Ca
 * 
 *  Description:
 *     
 *    Queue implementation using DoublyLinkedList.
 * 
 *     Supported operations:
 *      
 *      - get_size:
 *          return stack size
 *
 *      - enqueue:
 *          enqueue (insert) element in the end of the queue
 *
 *      - dequeue:
 *          dequeue (return and remove) the element at queue start
 *
 *      - peek:
 *          peek (return only) element in queue start
 *
 *      - isEmpty:
 *          return true if queue is empty and false if not
 *
 *      - deleteQueue:
 *          delete entire queue
 *
 *      - print:
 *          print all elements in the queue
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
        void deleteQueue();

        void print();

}; // end Queue

#endif
