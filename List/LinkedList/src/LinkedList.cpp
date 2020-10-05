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
    listSize = 0;

} // end class constructor

int LinkedList::get_listSize()
{
    return listSize;

} // end get_listSize

LinkedListNode* LinkedList::get_firstNodePtr()
{
    return firstNodePtr;

} // end get_firstNodePtr

LinkedListNode* LinkedList::get_NodePtr(int index)
{
    LinkedListNode* accessNode = firstNodePtr;

    for(int i = 0; i < index; i++)
    {
        accessNode = accessNode->get_nextNodePtr();

    } // end for

    return accessNode;

} // end get_NodePtr

int LinkedList::get(int index)
{   
    LinkedListNode* accessNode = firstNodePtr;

    for(int i = 0; i < index; i++)
    {
        accessNode = accessNode->get_nextNodePtr();

    } // end for

    return accessNode->get_nodeData();

} // end accessNodeData

bool LinkedList::insertFirstNode(int data)
{
    LinkedListNode* newNode;

    try
    {
        newNode = new LinkedListNode;

    }catch(std::bad_alloc&)
    {            
        std::cout << "Memory allocaton fail. " << std::endl;
        return false;
 
    } // end try/catch

    if(listSize == 0)
    {
        newNode->set_nextNodePtr(nullptr);

    }
    else if(listSize > 0)
    {
        newNode->set_nextNodePtr(firstNodePtr);

    } // end if/else if

    firstNodePtr = newNode;

    newNode->set_firstNodePtr(&firstNodePtr);
    newNode->set_nodeData(data);

    listSize++;

    return true;

} // end insertNodeAtStart

bool LinkedList::insertLastNode(int data)
{
    LinkedListNode* newNode;

    try
    {
        newNode = new LinkedListNode;

    }catch(std::bad_alloc&)
    {            
        std::cout << "Memory allocaton fail. " << std::endl;
        return false;
 
    } // end try/catch

    newNode->set_nextNodePtr(nullptr);
    newNode->set_firstNodePtr(&firstNodePtr);
    newNode->set_nodeData(data);

    if(listSize > 0)
    {
        LinkedListNode* previousLastNode = this->get_NodePtr(listSize - 1);
        previousLastNode->set_nextNodePtr(newNode);

    } // end if

    listSize++;

    return true;

} // end insertNodeAtEnd

bool LinkedList::insertNodeAt(int index, int data)
{   
    if(index == 0)
    {
        bool status = this->insertFirstNode(data);
        
        if(status) 
            return true;
        else 
            return false;

    } // end if

    if(index == (listSize - 1))
    {
        bool status = this->insertLastNode(data);
        
        if(status) 
            return true;
        else 
            return false;

    } // end if

    LinkedListNode* newNode;

    try
    {
        newNode = new LinkedListNode;

    }catch(std::bad_alloc&)
    {            
        std::cout << "Memory allocaton fail. " << std::endl;
        return false;
 
    } // end try/catch

    LinkedListNode* previousNode = this->get_NodePtr(index - 1);

    newNode->set_nextNodePtr(previousNode->get_nextNodePtr());
    previousNode->set_nextNodePtr(newNode);

    newNode->set_firstNodePtr(&firstNodePtr);
    newNode->set_nodeData(data);

    listSize++;

    return true;

} // end insertNodeAfter

bool LinkedList::deleteNode(int index)
{   
    LinkedListNode* deletedNode = this->get_NodePtr(index);

    if(index == 0)
    {
        firstNodePtr = deletedNode->get_nextNodePtr();

    } // end if

    else if(index == (listSize - 1))
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

    listSize--;
    
    return true;

} // end deleteNode