/*
 *  Author: Carlos Henrique Silva Correia de Araujo
 *  Computer engineering - UFPB (Undergraduate)
 *  github.com/Ch94Ca
 *
 *  Description:
 *     
 *     DynamicArray class implementation
 *    
 */ 

#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include "DynamicArray.hpp"

class HashTable
{
    private:

        DynamicArray array;
        unsigned int tableSize;
        double tableOccupation;

        unsigned int doubleHash(unsigned long int key, unsigned int attempt);

        unsigned int get_nextPrime(unsigned int start);

        bool checkResize();
        void resize();

    public:

        HashTable();
        HashTable(unsigned int tableSize);

        void insert(std::string name, unsigned long int cpf);
        arrayData get(unsigned long int key);
        void print();
        void printKey(unsigned long int key);

        unsigned int get_tableSize();
        double get_tableOccupation();
        void printStatus();

}; // end HashTable

#endif