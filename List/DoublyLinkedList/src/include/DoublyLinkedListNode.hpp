/*
 *   Author: Carlos Henrique Silva Correia de Araujo
 *   Computer engineering - UFPB (Undergraduate)
 *   github.com/Ch94Ca
 * 
 *   Description:
 *      
 *      Doubly linked list node class header 
 *      used in a doubly linked list implementation.
 *     
 */ 

#ifndef DOUBLYLINKEDLISTNODE_HPP
#define DOUBLYLINKEDLISTNODE_HPP

class DoublyLinkedListNode
{
    private:

        int nodeData;

        DoublyLinkedListNode* previousNodePtr;
        DoublyLinkedListNode* nextNodePtr;

        friend class DoublyLinkedList;

    protected:

        DoublyLinkedListNode();

        int get_nodeData();
        DoublyLinkedListNode* get_previousNodePtr();
        DoublyLinkedListNode* get_nextNodePtr();

        void set_nodeData(int nodeData);
        void set_previousNodePtr(DoublyLinkedListNode* previousNodePtr);
        void set_nextNodePtr(DoublyLinkedListNode* nextNodePtr);

}; // end DoublyLinkedListNode class

#endif
