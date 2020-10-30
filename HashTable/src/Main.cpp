/*
 *  Author: Carlos Henrique Silva Correia de Araujo
 *  Computer engineering - UFPB (Undergraduate)
 *  github.com/Ch94Ca
 *
 *  Description:
 *     
 *     Doubly linked list class implementation
 *    
 */ 

#include <iostream>
#include "include/HashTable.hpp"
#include "include/DynamicArray.hpp"

using namespace std;

int main(void)
{       
        HashTable hash;

        hash.insert("Carlos", 11481565427);
        hash.insert("Angela", 52983676404);
        hash.insert("Isabelle", 71493466429);
        hash.insert("Iara", 73831034400);

        hash.printKey(11481565427);
        hash.printKey(52983676404);
        hash.printKey(71493466429);
        hash.printKey(73831034400);

        hash.printKey(73831032400);

        hash.printStatus();
        return 0;

} // End Main