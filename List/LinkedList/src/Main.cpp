/*
 *   AUTOR: Carlos Henrique Silva Correia de Araujo
 *   ENGENHARIA DE COMPUTAÇÃO - UFPB
 *   https://github.com/ch94ca
 *     
 */ 

#include <iostream>
#include "include/LinkedList.hpp"
#include "include/LinkedListNode.hpp"

using namespace std;

int main(void){

        // LinkedListNode Class test
        // needs to change 'protected' to 'public' in class to work

        /*

        LinkedListNode* node;

        try{

                node = new LinkedListNode;

        }catch(std::bad_alloc&){
                
                cout << "Memory allocaton fail. " << endl;
 
        } // end try/catch

        LinkedListNode** pointerToFirst = &node;

        cout << "Node data: " << node->get_nodeData() << endl;
        cout << "First node ptr: " << node->get_firstNodePtr() << endl;
        cout << "Next node ptr: " << node->get_nextNodePtr() << endl << endl;

        node->set_nodeData(99);
        node->set_firstNodePtr(pointerToFirst);
        node->set_nextNodePtr(node);

        cout << "Node data: " << node->get_nodeData() << endl;
        cout << "First node ptr:   " << *node->get_firstNodePtr() << endl;
        cout << "Next node ptr:    " << node->get_nextNodePtr() << endl;
        cout << "Current node ptr: " << node << endl << endl;

        */

        // LinkedList Class test

        LinkedList list;

        cout << "List size: " << list.get_listSize() << endl;
        cout << "First node ptr: " << list.get_firstNodePtr() << endl;
        cout << "List iterator: " << list.get_listIterator() << endl << endl;

        list.insertNodeAtStart(50);
        list.insertNodeAtStart(40);
        list.insertNodeAtStart(30);
        list.insertNodeAtStart(20);
        list.insertNodeAtStart(10);

        cout << "List size: " << list.get_listSize() << endl;
        cout << "First node ptr: " << list.get_firstNodePtr() << endl;
        cout << "List iterator: " << list.get_listIterator() << endl << endl;

        cout << "Node 0 data: " << list.accessNodeData(0) << endl;
        cout << "Node 1 data: " << list.accessNodeData(1) << endl;
        cout << "Node 2 data: " << list.accessNodeData(2) << endl;
        cout << "Node 3 data: " << list.accessNodeData(3) << endl;
        cout << "Node 4 data: " << list.accessNodeData(4) << endl;


        return 0;

} // End Main
