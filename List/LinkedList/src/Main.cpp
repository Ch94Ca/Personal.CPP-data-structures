/*
 *   AUTOR: Carlos Henrique Silva Correia de Araujo
 *   ENGENHARIA DE COMPUTAÇÃO - UFPB
 *   https://github.com/ch94ca
 *     
 */ 

#include <iostream>
#include "include/LinkedListNode.hpp"

using namespace std;

int main(void){

        // LinkedListNode Class test
        // needs to change 'protected' to 'public' in class to work

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

        return 0;

} // End Main
