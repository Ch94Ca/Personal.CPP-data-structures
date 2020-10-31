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

class HashMap
{
    private:

        DynamicArray array;
        unsigned int tableSize;
        double tableOccupation;

        unsigned int doubleHash(unsigned long int key, unsigned int attempt);

        unsigned int get_nextPrime(unsigned int start);
        unsigned int get_previousPrime(unsigned int start);

        bool insertCheckResize();
        bool deleteCheckResize();
        void resize(bool resizeTo);

    public:

        HashMap();
        HashMap(unsigned int tableSize);

        void insert(std::string name, unsigned long int cpf);
        arrayData get(unsigned long int key);
        unsigned int get_index(unsigned long int key);
        void deleteElement(unsigned long int key);
        void printArray();
        void printKey(unsigned long int key);
        void print();

        unsigned int get_tableSize();
        double get_tableOccupation();
        void printStatus();

}; // end HashMap

#endif