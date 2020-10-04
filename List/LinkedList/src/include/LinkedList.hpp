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

        void set_listSize(int listSize);
        void inc_listSize();
        
    public:

        LinkedList();

        int get_listSize();
        int get_listIterator();
        LinkedListNode* get_firstNodePtr();

        int accessNodeData(int index);
        bool insertNodeAtStart(int data);
        bool insertNodeAtEnd(int data);
        bool insertNodeAfter(int index, int data);
        bool deleteNode(int index);
        

}; // end LinkedList class

#endif
