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
        cout << "First node ptr: " << list.get_firstNodePtr() << endl << endl;

        list.insertFirstNode(40);
        list.insertFirstNode(30);
        list.insertFirstNode(20);

        list.insertLastNode(60);
        list.insertLastNode(70);
        list.insertLastNode(80);

        list.insertNodeAt(0, 10);
        list.insertNodeAt(4, 50);
        list.insertNodeAt((list.get_listSize() - 1), 90);

        list.print();

        cout << endl << "List size: " << list.get_listSize() << endl;
        cout << "First node ptr: " << list.get_firstNodePtr() << endl << endl;

        list.deleteNode(4);
        list.deleteNode(0);
        list.deleteNode((list.get_listSize() - 1));

        list.print();

        cout << endl << "List size: " << list.get_listSize() << endl;
        cout << "First node ptr: " << list.get_firstNodePtr() << endl << endl;
        
        list.deleteList();

        cout << endl << "List size: " << list.get_listSize() << endl;
        cout << "First node ptr: " << list.get_firstNodePtr() << endl << endl;

        list.insertNodeAt(0, 1);
        list.insertNodeAt(1, 2);
        list.insertNodeAt(2, 3);
        list.insertNodeAt(3, 4);

        list.print();

        cout << endl << "List size: " << list.get_listSize() << endl;
        cout << "First node ptr: " << list.get_firstNodePtr() << endl << endl;

        return 0;

} // End Main
