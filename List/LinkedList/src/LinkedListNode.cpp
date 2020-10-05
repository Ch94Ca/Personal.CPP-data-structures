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
    nextNodePtr = nullptr;

} // end class constructor

int LinkedListNode::get_nodeData()
{
    return nodeData;

} // end get_nodeData

LinkedListNode* LinkedListNode::get_nextNodePtr()
{
    return nextNodePtr;

} // end get_nextNodePtr 

void LinkedListNode::set_nodeData(int nodeData)
{
    this->nodeData = nodeData;

} // end set_nodeData

void LinkedListNode::set_nextNodePtr(LinkedListNode* nextNodePtr)
{
    this->nextNodePtr = nextNodePtr;

} // end set_nextNodePtr