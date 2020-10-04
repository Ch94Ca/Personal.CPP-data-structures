/*
 *   AUTOR: Carlos Henrique Silva Correia de Araujo
 *   ENGENHARIA DE COMPUTAÇÃO - UFPB
 *   https://github.com/ch94ca
 *     
 */ 

#ifndef LINKEDLISTNODE_HPP
#define LINKEDLISTNODE_HPP

class LinkedListNode
{
    private:

        int nodeData;
        LinkedListNode** firstNodePtr;
        LinkedListNode* nextNodePtr;

        friend class LinkedList;

    protected:

        LinkedListNode();
        LinkedListNode(int nodeData, LinkedListNode** firstNodePtr);

        int get_nodeData();
        LinkedListNode** get_firstNodePtr();
        LinkedListNode* get_nextNodePtr();

        void set_nodeData(int nodeData);
        void set_firstNodePtr(LinkedListNode** firstNodePtr);
        void set_nextNodePtr(LinkedListNode* nextNodePtr);

}; // end LinkedListNode class

#endif
