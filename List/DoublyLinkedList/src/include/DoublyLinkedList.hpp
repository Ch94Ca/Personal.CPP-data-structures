/*
 *   AUTOR: Carlos Henrique Silva Correia de Araujo
 *   ENGENHARIA DE COMPUTAÇÃO - UFPB
 *   https://github.com/ch94ca
 *     
 */ 

#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP

#include "DoublyLinkedListNode.hpp"

class DoublyLinkedList{

    private:

        DoublyLinkedListNode* firstNodePtr;
        DoublyLinkedListNode* lastNodePtr;
        int listSize;
        
    public:

        DoublyLinkedList();

        DoublyLinkedListNode* get_firstNodePtr();
        DoublyLinkedListNode* get_lastNodePtr();
        DoublyLinkedListNode* get_NodePtr(int index);

        int get_listSize();
        int get(int index);
        void print();
        void printBackward();
        void printListPtr();
        bool insertFirstNode(int data);
        bool insertLastNode(int data);
        bool insertNodeAt(int index, int data);
        bool deleteNode(int index);
        bool deleteList();

}; // end DoublyLinkedList class

#endif
