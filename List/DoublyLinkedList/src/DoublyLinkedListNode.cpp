/*
 *   AUTOR: Carlos Henrique Silva Correia de Araujo
 *   ENGENHARIA DE COMPUTAÇÃO - UFPB
 *   https://github.com/ch94ca
 *     
 */ 

#include "include/DoublyLinkedListNode.hpp"

DoublyLinkedListNode::DoublyLinkedListNode()
{
    nodeData = 0;
    previousNodePtr = nullptr;
    nextNodePtr = nullptr;

} // end class constructor

int DoublyLinkedListNode::get_nodeData()
{
    return nodeData;

} // end get_nodeData

DoublyLinkedListNode* DoublyLinkedListNode::get_previousNodePtr()
{
    return previousNodePtr;

} // end get_nextNodePtr 

DoublyLinkedListNode* DoublyLinkedListNode::get_nextNodePtr()
{
    return nextNodePtr;

} // end get_nextNodePtr 

void DoublyLinkedListNode::set_nodeData(int nodeData)
{
    this->nodeData = nodeData;

} // end set_nodeData

void DoublyLinkedListNode::set_previousNodePtr(DoublyLinkedListNode* previousNodePtr)
{
    this->previousNodePtr = previousNodePtr;

} // end set_nextNodePtr

void DoublyLinkedListNode::set_nextNodePtr(DoublyLinkedListNode* nextNodePtr)
{
    this->nextNodePtr = nextNodePtr;

} // end set_nextNodePtr