/*
 *   AUTOR: Carlos Henrique Silva Correia de Araujo
 *   ENGENHARIA DE COMPUTAÇÃO - UFPB
 *   https://github.com/ch94ca
 *     
 */ 

#include <iostream>
#include "include/DoublyLinkedList.hpp"

using namespace std;

int main(void){

        DoublyLinkedList list;

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
        list.insertNodeAt(5, 55);
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
        
        //list.deleteList();

        cout << endl << "List size: " << list.get_listSize() << endl;
        cout << "First node ptr: " << list.get_firstNodePtr() << endl << endl;

        DoublyLinkedList list1;

        list1.insertLastNode(0);
        list1.insertLastNode(1);
        list1.insertLastNode(3);

        list1.printListPtr();

        list1.insertNodeAt(2, 2);

        list1.print();

        list1.printListPtr();


        cout << endl << "List size: " << list1.get_listSize() << endl;
        cout << "First node ptr: " << list1.get_firstNodePtr() << endl << endl;

        return 0;

} // End Main
