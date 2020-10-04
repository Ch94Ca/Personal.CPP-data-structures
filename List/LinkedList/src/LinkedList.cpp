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
    listIterator = 0;

} // end class constructor

int LinkedList::get_listSize()
{
    return listSize;

} // end get_listSize

int LinkedList::get_listIterator()
{
    return listIterator;

} // end get_listIterator

LinkedListNode* LinkedList::get_firstNodePtr()
{
    return firstNodePtr;

} // end get_firstNodePtr

int LinkedList::accessNodeData(int index)
{   
    LinkedListNode* accessNode = firstNodePtr;

        for(int i = 0; i < index; i++)
        {   
            accessNode = accessNode->get_nextNodePtr();
            
        } // end for

    return accessNode->get_nodeData();

} // end accessNodeData

bool LinkedList::insertNodeAtStart(int data)
{
    LinkedListNode* node;

    try
    {
        node = new LinkedListNode;

    }catch(std::bad_alloc&)
    {            
        std::cout << "Memory allocaton fail. " << std::endl;
        return false;
 
    } // end try/catch

    if(listSize == 0)
    {
        node->set_nextNodePtr(nullptr);

    }
    else if(listSize > 1)
    {
        node->set_nextNodePtr(firstNodePtr);

    } // end if/else if

    firstNodePtr = node;

    node->set_firstNodePtr(&firstNodePtr);

    node->set_nodeData(data);

    listSize++;

    return true;

} // end insertNodeAtStart

bool LinkedList::insertNodeAtEnd(int data)
{
    return false;

} // end insertNodeAtEnd

bool LinkedList::insertNodeAfter(int index, int data)
{
    return false;

} // end insertNodeAfter

bool LinkedList::deleteNode(int index)
{
    return false;

} // end deleteNode
        
void LinkedList::set_listSize(int listSize)
{
    this->listSize = listSize;

} // end set_listSize

void LinkedList::inc_listSize()
{
    listSize++;

} // end inc_listSize