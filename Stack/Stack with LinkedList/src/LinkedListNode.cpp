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