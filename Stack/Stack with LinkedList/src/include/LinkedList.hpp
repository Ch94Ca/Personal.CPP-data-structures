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
