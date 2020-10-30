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

#include "include/HashTable.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>

unsigned int HashTable::doubleHash(unsigned long int key, unsigned int attempt)
{
    unsigned int size = array.get_size();

    unsigned int hash_0 = key % size;
    unsigned int hash_1 = (size - 1) - key % (size - 1);

    return (hash_0 + attempt * hash_1) % size; 

} // end hash_0

unsigned int HashTable::get_nextPrime(unsigned int start)
{
    int primeNumber = start + 1;

    while(true)
    {   
        int c = 0;

        for(unsigned int i = 2; i <= sqrt(primeNumber); i++) {

                if(primeNumber % i == 0) {
                        c++;
                        break;
                } // end If

        } // end for

        if(c == 0) 
        {
            return primeNumber;
        
        } // end if
        else
        {
            primeNumber++;

        } // End if

    } // end while

} // end get_prime

bool HashTable::checkResize()
{   
    if(tableOccupation > 75.0)
    {
        return true;

    } // end if

    return false;

} // end checkResize

void HashTable::resize()
{       
    DynamicArray tempArray;

    unsigned int oldSize = array.get_size();
    unsigned int newSize = get_nextPrime(oldSize);

    for(unsigned int i = 0; i < oldSize; i++)
    {
        tempArray.insertLast(array.get(i));

    } // end if

    array.deleteArray();

    tableSize = 0;
    tableOccupation = 0;

    array.resize(newSize);

    for(unsigned int i = 0; i < oldSize; i++)
    {
        if(tempArray.get(i).cpf != 0)
        {
            this->insert(tempArray.get(i).name, tempArray.get(i).cpf);

        } // end if

    } // end for

} // end Resize

HashTable::HashTable()
{   
    tableSize = 0;
    tableOccupation = 0;
    array.resize(3);

} // end class constructor

HashTable::HashTable(unsigned int startSize)
{   
    tableSize = 0;
    tableOccupation = 0;
    array.resize(startSize);

} // end class constructor

void HashTable::insert(std::string name, unsigned long int cpf)
{
    unsigned int insertIndex;
    unsigned int attempt = 0;

    arrayData insertData;
    insertData.name = name;
    insertData.cpf = cpf;

    while(true)
    {   
        insertIndex = doubleHash(cpf, attempt);
        
        arrayData indexData = array.get(insertIndex);

        if(indexData.cpf == 0)
        {
            array.modifyElement(insertIndex, insertData);
            break;

        } // end if
        else if(indexData.cpf == cpf)
        {
            std::cout << "CPF Já Cadastrado." << std::endl;
            return;

        } // end if
        else
        {
            attempt++;

        } // end else

    } // end while

    tableSize++;
    tableOccupation = ((double)tableSize / (double)array.get_size()) * 100;

    if(this->checkResize())
    {
        this->resize();

    } // end if

} // end insert

arrayData HashTable::get(unsigned long int key)
{
    unsigned int searchIndex;
    unsigned int attempt = 0;

    arrayData indexData;

    while(true)
    {   
        searchIndex = doubleHash(key, attempt);
        
        indexData = array.get(searchIndex);

        if(indexData.cpf == 0)
        {
            break;

        } // end if
        else if(indexData.cpf == key)
        {
            return indexData;

        } // end if
        else if(attempt == array.get_size())
        {
            break;

        } // end if
        else
        {
            attempt++;

        } // end else

    } // end while

    indexData.name = "NULL";
    indexData.cpf = 0;

    return indexData;

} // end get

void HashTable::print()
{
    array.print();

} // end print

void HashTable::printKey(unsigned long int key)
{
    arrayData data = this->get(key);

    std::cout << "CPF: " << data.cpf << std::endl;
    std::cout << "Nome: " << data.name << std::endl << std::endl;

} // end printKey

unsigned int HashTable::get_tableSize()
{
    return tableSize;

} // end get_tableSize

double HashTable::get_tableOccupation()
{    
    return tableOccupation;

} // end get_tableOccupation

void HashTable::printStatus()
{
    std::cout << "Hash table array size: " << array.get_size() << std::endl;
    std::cout << "Number of itens stored: " << tableSize << std::endl;
    std::cout << "Occupation: " << tableOccupation << std::endl << std::endl;

} // end printHashStatus