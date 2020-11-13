/*
 *  HashMap
 * 
 *  Author: Carlos Henrique Silva Correia de Araujo
 *  Computer engineering - UFPB (Undergraduate)
 *  github.com/Ch94Ca
 * 
 *  Description:
 *     
 *    HashMap Class Implementation
 * 
 *     Supported operations:
 *      
 *      - firstEmpty:
 *          hash function with first empty position
 *          collision handling method
 *
 *      - get_nextPrime:
 *          return next prime number after a given number
 *
 *      - get_previousPrime:
 *          return previous prime number after a given number
 *
 *      - insertCheckResize:
 *          check resize need for insert method
 *
 *      - deleteCheckResize:
 *          check resize need for delete method
 *
 *      - resize:
 *          resize hashmap
 *
 *      - insert:
 *          insert data in hashmap
 *
 *      - get:
 *          return data by a given key
 *
 *      - deleteElement:
 *          delete element by a given key
 *
 *      - deleteHashMap:
 *          delete entire hashmap
 *
 *      - printArray:
 *          print entire hashmap array
 *
 *      - printKey:
 *          printhashmap data by a given key
 *
 *      - print:
 *          print only valid data in hashmap
 *
 *      - get_mapSize:
 *          return hashmap size
 *
 *      - get_mapOccupation:
 *          return hashmap ocuppation (%)
 *
 *      - printStatus:
 *          print hashmap status
 */

#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include "DynamicArray.hpp"

class HashMap
{
    private:

        DynamicArray array;
        unsigned int mapSize;
        double mapOccupation;

        unsigned int firstEmpty(unsigned long int key, unsigned int attempt);

        unsigned int get_nextPrime(unsigned int start);
        unsigned int get_previousPrime(unsigned int start);

        bool insertCheckResize();
        bool deleteCheckResize();
        void resize(bool resizeTo);

    public:

        HashMap();

        void insert(std::string name, unsigned long int cpf);
        arrayData get(unsigned long int key);
        void deleteElement(unsigned long int key);
        void deleteHashMap();
        void printArray();
        void printKey(unsigned long int key);
        void print();

        unsigned int get_mapSize();
        double get_mapOccupation();
        void printStatus();

}; // end HashMap

#endif