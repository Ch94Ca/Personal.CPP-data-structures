/*
 *  Doubly Linked List
 * 
 *  Author: Carlos Henrique Silva Correia de Araujo
 *  Computer engineering - UFPB (Undergraduate)
 *  github.com/Ch94Ca
 *  
 *  Started In: Oct 3, 2020
 *  Last modification: Oct 11, 2020 
 * 
 *  Description:
 *     
 *     Doubly linked list implementation.
 * 
 *     Supported operations:
 *      
 *      - get_FirstNodePtr:
 *          return first node pointer
 * 
 *      - get_LastNodePtr:
 *          return last node pointer
 * 
 *      - get_NodePtr:
 *          return node pointer by index 
 * 
 *      - get_size: 
 *          return list size
 * 
 *      - get: 
 *          return list content by index
 * 
 *      - print:
 *          print list data in forward order
 *      
 *      - printBackward:
 *          print list data in backward order  
 * 
 *      - printListPtr:
 *          print list data and pointers for each node (for debug) 
 *  
 *      - insertFirstNode:
 *          insert node at list start
 * 
 *      - insertLastNode:
 *          insert node at list end
 * 
 *      - insertNodeAt:
 *          insert node in the middle list by index
 * 
 *       - insertNodeAt:
 *          modify node value by index
 *
 *      - deleteNode:
 *          delete list node by index
 * 
 *      - deleteList:
 *          delete entire list
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
        unsigned int size;
    public:

        DoublyLinkedList();

        unsigned int get_size();
        void print();

        DoublyLinkedListNode *get_firstNodePtr();
        DoublyLinkedListNode *get_lastNodePtr();
        DoublyLinkedListNode *get_NodePtr(unsigned int index);

        int get(unsigned int index);
        void printBackward();
        void printListPtr();
        void insertFirstNode(int data);
        void insertLastNode(int data);
        void insertNodeAt(unsigned int index, int data);
        void modifyNodeData(unsigned int index, int data);
        void deleteNode(unsigned int index);
        void deleteList();


}; // end DoublyLinkedList class

#endif
