/*
 *  Linked List Node
 * 
 *  Author: Carlos Henrique Silva Correia de Araujo
 *  Computer engineering - UFPB (Undergraduate)
 *  github.com/Ch94Ca
 *  
 * 
 *  Description:
 *     
 *     Linked list node implementation.
 * 
 *     Supported operations:
 *      
 *      - set_nodeData:
 *          set node data
 * 
 *      - set_previousNodePtr:
 *          set previous node pointer
 * 
 *      - get_nodeData:
 *          get node data
 * 
 *      - get_previousNodePtr:
 *          get previous node pointer
 * 
 */

#ifndef LINKEDLISTNODE_HPP
#define LINKEDLISTNODE_HPP

class LinkedListNode
{
    private:

        int nodeData;
        LinkedListNode *nextNodePtr;

        friend class LinkedList;

    protected:

        LinkedListNode();

        int get_nodeData();
        LinkedListNode* get_nextNodePtr();

        void set_nodeData(int nodeData);
        void set_nextNodePtr(LinkedListNode *nextNodePtr);

}; // end LinkedListNode class

#endif
