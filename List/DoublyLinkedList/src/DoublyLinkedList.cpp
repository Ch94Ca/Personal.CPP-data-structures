/*
 *   AUTOR: Carlos Henrique Silva Correia de Araujo
 *   ENGENHARIA DE COMPUTAÇÃO - UFPB
 *   https://github.com/ch94ca
 *     
 */ 

#include <iostream>
#include <new>
#include "include/DoublyLinkedList.hpp"
#include "include/DoublyLinkedListNode.hpp"

DoublyLinkedList::DoublyLinkedList()
{   
    lastNodePtr = nullptr;
    firstNodePtr = nullptr;
    listSize = 0;

} // end class constructor

int DoublyLinkedList::get_listSize()
{
    return listSize;

} // end get_listSize

void DoublyLinkedList::print()
{
    for(int i = 0; i < listSize; i++)
    {
        std::cout << "Node " << i << " data: " << this->get(i) << std::endl;

    } // end for

} // end printList

void DoublyLinkedList::printListPtr()
{   
    DoublyLinkedListNode* currentNodePtr;
    DoublyLinkedListNode* previousNodePtr;
    DoublyLinkedListNode* nextNodePtr;

    for(int i = 0; i < listSize; i++)
    {   
        currentNodePtr = this->get_NodePtr(i);
        previousNodePtr = currentNodePtr->get_previousNodePtr();
        nextNodePtr = currentNodePtr->get_nextNodePtr();

        std::cout << std::endl << "Node :" << i << std::endl;
        std::cout << "Node data: " << this->get(i) << std::endl;
        std::cout << "Previous node pointer: " << previousNodePtr << std::endl;
        std::cout << "Current node pointer : " << currentNodePtr << std::endl;
        std::cout << "Next node pointer    : " << nextNodePtr << std::endl << std::endl;

    } // end for

} // end printListPtr

DoublyLinkedListNode* DoublyLinkedList::get_firstNodePtr()
{
    return firstNodePtr;

} // end get_firstNodePtr

DoublyLinkedListNode* DoublyLinkedList::get_lastNodePtr()
{
    return lastNodePtr;

} // end get_firstNodePtr

DoublyLinkedListNode* DoublyLinkedList::get_NodePtr(int index)
{
    DoublyLinkedListNode* accessNode = firstNodePtr;

    for(int i = 0; i < index; i++)
    {
        accessNode = accessNode->get_nextNodePtr();

    } // end for

    return accessNode;

} // end get_NodePtr

int DoublyLinkedList::get(int index)
{   
    DoublyLinkedListNode* accessNode = firstNodePtr;

    for(int i = 0; i < index; i++)
    {
        accessNode = accessNode->get_nextNodePtr();

    } // end for

    return accessNode->get_nodeData();

} // end accessNodeData

bool DoublyLinkedList::insertFirstNode(int data)
{
    DoublyLinkedListNode* newNode;

    try
    {
        newNode = new DoublyLinkedListNode;

    }catch(std::bad_alloc&)
    {            
        std::cout << "Memory allocation failed. " << std::endl;
        return false;
 
    } // end try/catch

    if(listSize > 0)
    {    
        newNode->set_nextNodePtr(firstNodePtr);
        firstNodePtr->set_previousNodePtr(newNode);

    } // end if/else if

    if(listSize == 0)
    {
        lastNodePtr = newNode;

    } // end if

    firstNodePtr = newNode;

    newNode->set_nodeData(data);

    listSize++;

    return true;

} // end insertNodeAtStart

bool DoublyLinkedList::insertLastNode(int data)
{
    DoublyLinkedListNode* newNode;

    try
    {
        newNode = new DoublyLinkedListNode;

    }catch(std::bad_alloc&)
    {            
        std::cout << "Memory allocation failed. " << std::endl;
        return false;
 
    } // end try/catch

    newNode->set_nodeData(data);

    if(listSize > 0)
    {
        lastNodePtr->set_nextNodePtr(newNode);
        newNode->set_previousNodePtr(lastNodePtr);
        lastNodePtr = newNode;

    } // end if
    else
    {
        firstNodePtr = newNode;
        lastNodePtr = newNode;

    } // end else/if

    listSize++;

    return true;

} // end insertNodeAtEnd

bool DoublyLinkedList::insertNodeAt(int index, int data)
{   
    if(index == 0)
    {
        bool status = this->insertFirstNode(data);
        
        if(status) 
            return true;
        else 
            return false;

    } // end if

    DoublyLinkedListNode* newNode;

    try
    {
        newNode = new DoublyLinkedListNode;

    }catch(std::bad_alloc&)
    {            
        std::cout << "Memory allocation fail. " << std::endl;
        return false;
 
    } // end try/catch

    DoublyLinkedListNode* nextNode = this->get_NodePtr(index);
    DoublyLinkedListNode* previousNode = this->get_NodePtr(index - 1);

    nextNode->set_previousNodePtr(newNode);
    previousNode->set_nextNodePtr(newNode);

    newNode->set_previousNodePtr(previousNode);
    newNode->set_nextNodePtr(nextNode);

    newNode->set_nodeData(data);

    listSize++;

    return true;

} // end insertNodeAfter

bool DoublyLinkedList::deleteNode(int index)
{   
    DoublyLinkedListNode* deletedNode = this->get_NodePtr(index);

    if(index == 0)
    {   
        DoublyLinkedListNode* nextNode = deletedNode->get_nextNodePtr();

        nextNode->set_previousNodePtr(nullptr); 
        firstNodePtr = deletedNode->get_nextNodePtr();

    } // end if

    else if(index == (listSize - 1))
    {
        DoublyLinkedListNode* newLastNode = this->get_NodePtr(index - 1);
        newLastNode->set_nextNodePtr(nullptr);

    } // end else/if

    else
    {
        DoublyLinkedListNode* previousNode = this->get_NodePtr(index - 1);
        DoublyLinkedListNode* nextNode = this->get_NodePtr(index + 1);

        previousNode->set_nextNodePtr(nextNode);
        nextNode->set_previousNodePtr(previousNode);

    } // end else

    delete deletedNode;

    listSize--;
    
    return true;

} // end deleteNode

bool DoublyLinkedList::deleteList()
{   
    int previousListSize = listSize;

    for(int i = 0; i < previousListSize; i++)
    {
        this->deleteNode(0);

    } // end for

    firstNodePtr = nullptr;
    lastNodePtr = nullptr;

    return true;
    
} // end deleteList
