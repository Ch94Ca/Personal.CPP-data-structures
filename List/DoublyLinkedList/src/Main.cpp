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

        list.printListPtr();
        list.print();

        list.insertFirstNode(4);
        list.insertFirstNode(2);
        list.insertFirstNode(1);

        list.insertNodeAt(0, 0);
        list.insertNodeAt(3, 3);

        list.insertLastNode(5);
        list.insertLastNode(7);
        list.insertLastNode(8);

        list.insertNodeAt(6, 6);

        list.printListPtr();
        list.print();

        list.deleteNode(6);     
        list.deleteNode(0);
        list.deleteNode(list.get_listSize() - 1);

        list.print();
        
        list.insertNodeAt(5, 6);
        list.insertNodeAt(0, 0);
        list.insertLastNode(8);

        list.printListPtr();
        list.print();

        list.deleteList();

        list.printListPtr();
        list.print();

        list.insertLastNode(0);
        list.insertLastNode(1);
        list.insertLastNode(2);
        list.insertNodeAt(3, 3);
        list.insertNodeAt(10, 10);

        list.printListPtr();
        list.print();

        list.deleteList();

        list.printListPtr();
        list.print();

        return 0;

} // End Main
