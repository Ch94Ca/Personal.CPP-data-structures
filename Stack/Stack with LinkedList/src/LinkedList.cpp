/*
 *   AUTOR: Carlos Henrique Silva Correia de Araujo
 *   ENGENHARIA DE COMPUTAÇÃO - UFPB
 *   https://github.com/ch94ca
 *     
 */ 

#include <iostream>
#include <new>
#include "include/LinkedList.hpp"
#include "include/LinkedListNode.hpp"

LinkedList::LinkedList()
{

    firstNodePtr = nullptr;
    size = 0;

} // end class constructor

unsigned int LinkedList::get_size()
{
    return size;

} // end get_size

void LinkedList::print()
{   

    std::cout << "{";

    for(unsigned int i = 0; i < size; i++)
        {
                std::cout << this->get(i);

                if(i != (size - 1))
                {
                    std::cout << ", ";

                } // end if

        } // end for

        std::cout << "}" << std::endl;

} // end printList

LinkedListNode* LinkedList::get_firstNodePtr()
{
    return firstNodePtr;

} // end get_firstNodePtr

LinkedListNode* LinkedList::get_NodePtr(unsigned int index)
{
    LinkedListNode* accessNode = firstNodePtr;

    for(unsigned int i = 0; i < index; i++)
    {
        accessNode = accessNode->get_nextNodePtr();

    } // end for

    return accessNode;

} // end get_NodePtr

int LinkedList::get(unsigned int index)
{   
    LinkedListNode* accessNode = firstNodePtr;

    for(unsigned int i = 0; i < index; i++)
    {
        accessNode = accessNode->get_nextNodePtr();

    } // end for

    return accessNode->get_nodeData();

} // end accessNodeData

void LinkedList::insertFirstNode(int data)
{
    LinkedListNode* newNode;

    try
    {
        newNode = new LinkedListNode;

    }catch(std::bad_alloc&)
    {            
        std::cout << "Memory allocation failure." << std::endl;
        exit(1);
 
    } // end try/catch

    if(size == 0)
    {
        newNode->set_nextNodePtr(nullptr);

    }
    else if(size > 0)
    {
        newNode->set_nextNodePtr(firstNodePtr);

    } // end if/else if

    firstNodePtr = newNode;

    newNode->set_nodeData(data);

    size++;

} // end insertNodeAtStart

void LinkedList::insertLastNode(int data)
{
    LinkedListNode* newNode;

    try
    {
        newNode = new LinkedListNode;

    }catch(std::bad_alloc&)
    {            
        std::cout << "Memory allocation failure." << std::endl;
        exit(1);
 
    } // end try/catch

    newNode->set_nextNodePtr(nullptr);
    newNode->set_nodeData(data);

    if(size > 0)
    {
        LinkedListNode* previousLastNode = this->get_NodePtr(size - 1);
        previousLastNode->set_nextNodePtr(newNode);

    } // end if

    size++;

} // end insertNodeAtEnd

void LinkedList::insertNodeAt(unsigned int index, int data)
{   
    if(index == 0)
    {
        this->insertFirstNode(data);
        return;

    } // end if

    if(index == (size - 1))
    {
        this->insertLastNode(data);
        return;

    } // end if

    LinkedListNode* newNode;

    try
    {
        newNode = new LinkedListNode;

    }catch(std::bad_alloc&)
    {            
        std::cout << "Memory allocation failure." << std::endl;
        exit(1);
 
    } // end try/catch

    LinkedListNode* previousNode = this->get_NodePtr(index - 1);

    newNode->set_nextNodePtr(previousNode->get_nextNodePtr());
    previousNode->set_nextNodePtr(newNode);

    newNode->set_nodeData(data);

    size++;

} // end insertNodeAt

void LinkedList::modifyNodeData(unsigned int index, int data)
{
    LinkedListNode *accessNode = this->get_NodePtr(index);

    accessNode->set_nodeData(data);

} // end modifyNodeData

void LinkedList::deleteNode(unsigned int index)
{   
    LinkedListNode* deletedNode = this->get_NodePtr(index);

    if(index == 0)
    {
        firstNodePtr = deletedNode->get_nextNodePtr();

    } // end if

    else if(index == (size - 1))
    {
        LinkedListNode* newLastNode = this->get_NodePtr(index - 1);
        newLastNode->set_nextNodePtr(nullptr);

    } // end else/if

    else
    {
        LinkedListNode* previousNode = this->get_NodePtr(index - 1);
        previousNode->set_nextNodePtr(deletedNode->get_nextNodePtr());

    } // end else

    delete deletedNode;

    size--;

} // end deleteNode

void LinkedList::deleteList()
{
    LinkedListNode *accessNode = firstNodePtr;
    LinkedListNode *nextNode = firstNodePtr;

    for (unsigned int i = 0; i < size; i++)
    {
        accessNode = nextNode;
        nextNode = accessNode->nextNodePtr;

        delete accessNode;

    } // end for

    firstNodePtr = nullptr;
    size = 0;

} // end deleteList
