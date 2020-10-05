/*
 *   AUTOR: Carlos Henrique Silva Correia de Araujo
 *   ENGENHARIA DE COMPUTAÇÃO - UFPB
 *   https://github.com/ch94ca
 *     
 */ 

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "LinkedListNode.hpp"

class LinkedList{

    private:

        LinkedListNode* firstNodePtr;
        int listSize;
        
    public:

        LinkedList();

        int get_listSize();
        LinkedListNode* get_firstNodePtr();
        LinkedListNode* get_NodePtr(int index);

        int get(int index);
        bool insertFirstNode(int data);
        bool insertLastNode(int data);
        bool insertNodeAt(int index, int data);
        bool deleteNode(int index);

}; // end LinkedList class

#endif
