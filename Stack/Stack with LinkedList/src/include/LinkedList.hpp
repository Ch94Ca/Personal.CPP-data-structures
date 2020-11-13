/*
 *  Linked List
 * 
 *  Author: Carlos Henrique Silva Correia de Araujo
 *  Computer engineering - UFPB (Undergraduate)
 *  github.com/Ch94Ca
 * 
 *  Description:
 *     
 *     linked list implementation.
 * 
 *     Supported operations:
 *      
 *      - get_FirstNodePtr:
 *          return first node pointer
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
 *      - insertFirstNode:
 *          insert node at list start
 * 
 *      - insertLastNode:
 *          insert node at list end
 * 
 *      - insertNodeAt:
 *          insert node in the middle list by index
 * 
 *       - modifyNodeData:
 *          modify node value by index
 *
 *      - deleteNode:
 *          delete list node by index
 * 
 *      - deleteList:
 *          delete entire list
 * 
 */

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "LinkedListNode.hpp"

class LinkedList{

    private:

        LinkedListNode *firstNodePtr;
        unsigned int size;
        
    public:

        LinkedList();

        unsigned int get_size();
        LinkedListNode* get_firstNodePtr();
        LinkedListNode* get_NodePtr(unsigned int index);

        int get(unsigned int index);
        void print();
        void insertFirstNode(int data);
        void insertLastNode(int data);
        void insertNodeAt(unsigned int index, int data);
        void modifyNodeData(unsigned int index, int data);
        void deleteNode(unsigned int index);
        void deleteList();

}; // end LinkedList class

#endif
