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
        LinkedListNode* nextNodePtr;

        friend class LinkedList;

    protected:

        LinkedListNode();

        int get_nodeData();
        LinkedListNode* get_nextNodePtr();

        void set_nodeData(int nodeData);
        void set_nextNodePtr(LinkedListNode* nextNodePtr);

}; // end LinkedListNode class

#endif
