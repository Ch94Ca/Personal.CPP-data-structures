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
        int listIterator;
        
    public:

        LinkedList();
        LinkedList(LinkedListNode* firstNodePtr, int listSize);

        int get_listSize();

        int accessNodeData(int index);
        bool insertNodeAfter(int index, int data);
        bool deleteNode(int index);
        
        void set_listSize(int listSize);
        void inc_listSize();

}; // end LinkedList class

#endif
