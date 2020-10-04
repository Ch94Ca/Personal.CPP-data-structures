/*
 *   AUTOR: Carlos Henrique Silva Correia de Araujo
 *   ENGENHARIA DE COMPUTAÇÃO - UFPB
 *   https://github.com/ch94ca
 *     
 */ 

#include "include/LinkedListNode.hpp"


LinkedListNode::LinkedListNode()
{
    nodeData = 0;
    firstNodePtr = nullptr;
    nextNodePtr = nullptr;

} // end class constructor

LinkedListNode::LinkedListNode(int nodeData, LinkedListNode** firstNodePtr)
{
    nodeData = nodeData;
    firstNodePtr = firstNodePtr;
    nextNodePtr = nullptr;

} // end class constructor

int LinkedListNode::get_nodeData()
{
    return nodeData;

} // end get_nodeData

LinkedListNode** LinkedListNode::get_firstNodePtr()
{
    return firstNodePtr;

} // end get_firstNodePtr

LinkedListNode* LinkedListNode::get_nextNodePtr()
{
    return nextNodePtr;

} // end get_nextNodePtr 

void LinkedListNode::set_nodeData(int nodeData)
{
    this->nodeData = nodeData;

} // end set_nodeData

void LinkedListNode::set_firstNodePtr(LinkedListNode** firstNodePtr)
{
    this->firstNodePtr = firstNodePtr;

} // end set_firstNodePtr

void LinkedListNode::set_nextNodePtr(LinkedListNode* nextNodePtr)
{
    this->nextNodePtr = nextNodePtr;

} // end set_nextNodePtr