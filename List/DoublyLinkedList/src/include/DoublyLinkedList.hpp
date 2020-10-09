/*
 *   Author: Carlos Henrique Silva Correia de Araujo
 *   Computer engineering - UFPB (Undergraduate)
 *   github.com/Ch94Ca
 * 
 *   Description:
 *      
 *      Header for the doubly linked list implementation.
 *     
 */ 

#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP

#include "DoublyLinkedListNode.hpp"

class DoublyLinkedList
{
    private:

        DoublyLinkedListNode *firstNodePtr;
        DoublyLinkedListNode *lastNodePtr;
        int size;
        
    public:

        DoublyLinkedList();

        DoublyLinkedListNode* get_firstNodePtr();
        DoublyLinkedListNode* get_lastNodePtr();
        DoublyLinkedListNode* get_NodePtr(int index);

        int get_size();
        int get(int index);
        void print();
        void printBackward();
        void printListPtr();
        bool insertFirstNode(int data);
        bool insertLastNode(int data);
        bool insertNodeAt(int index, int data);
        void updateNode(int index, int data);
        void deleteNode(int index);
        void deleteList();

}; // end DoublyLinkedList class

#endif
