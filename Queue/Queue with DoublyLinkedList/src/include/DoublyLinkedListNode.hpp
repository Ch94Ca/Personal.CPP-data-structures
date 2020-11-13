/*
 *  Doubly Linked List Node
 * 
 *  Author: Carlos Henrique Silva Correia de Araujo
 *  Computer engineering - UFPB (Undergraduate)
 *  github.com/Ch94Ca
 * 
 *  Description:
 *     
 *     Doubly linked list node implementation.
 * 
 *     Supported operations:
 *      
 *      - set_nodeData:
 *          set node data
 * 
 *      - set_previousNodePtr:
 *          set previous node pointer
 * 
 *      - set_nextNodePtr:
 *          set next node pointer
 * 
 *      - get_nodeData:
 *          get node data
 * 
 *      - get_previousNodePtr:
 *          get previous node pointer
 * 
 *      - get_nextNodePtr:
 *          get next node pointer
 * 
 */

#ifndef DOUBLYLINKEDLISTNODE_HPP
#define DOUBLYLINKEDLISTNODE_HPP

class DoublyLinkedListNode
{
    private:

        int nodeData;

        DoublyLinkedListNode *previousNodePtr;
        DoublyLinkedListNode *nextNodePtr;

        friend class DoublyLinkedList;

    protected:

        DoublyLinkedListNode();

        void set_nodeData(int nodeData);
        void set_previousNodePtr(DoublyLinkedListNode *previousNodePtr);
        void set_nextNodePtr(DoublyLinkedListNode *nextNodePtr);

    public:
    
        int get_nodeData();
        DoublyLinkedListNode *get_previousNodePtr();
        DoublyLinkedListNode *get_nextNodePtr();

}; // end DoublyLinkedListNode class

#endif
