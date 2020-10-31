/*
 *  Author: Carlos Henrique Silva Correia de Araujo
 *  Computer engineering - UFPB (Undergraduate)
 *  github.com/Ch94Ca
 *
 *  Description:
 *     
 *     HashMap class implementation
 *    
 */ 

#include "include/HashMap.hpp"
#include <iostream>
#include <string>
#include <cmath>

unsigned int HashMap::doubleHash(unsigned long int key, unsigned int attempt)
{
    unsigned int size = array.get_size();

    unsigned int hash_0 = key % size;
    unsigned int hash_1 = (size - 1) - key % (size - 1);

    return (hash_0 + attempt * hash_1) % size; 

} // end hash_0

unsigned int HashMap::get_nextPrime(unsigned int start)
{
    unsigned int primeNumber = start + 1;

    while(true)
    {   
        unsigned int c = 0;

        for(unsigned int i = 2; i <= sqrt(primeNumber); i++) {

                if(primeNumber % i == 0)
                {
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

} // end get_nextPrime

unsigned int HashMap::get_previousPrime(unsigned int start)
{
    unsigned int primeNumber = start - 1;

    while(true)
    {   
        unsigned int c = 0;

        for(unsigned int i = 2; i <= sqrt(primeNumber); i++) {

                if(primeNumber % i == 0) 
                {
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
            primeNumber--;

        } // End if

    } // end while

} // end get_previousPrime

bool HashMap::insertCheckResize()
{   
    if(tableOccupation > 75.0)
    {
        return true;

    } // end if

    return false;

} // end checkResize

bool HashMap::deleteCheckResize()
{
    if(tableOccupation < 50.0 && array.get_size() > 3)
    {
        return true;

    } // end if

    return false;

} // end deleteCheckResize

void HashMap::resize(bool resizeTo)
{       
    DynamicArray tempArray;

    unsigned int oldSize = array.get_size();
    unsigned int newSize;

    if(resizeTo == true)
    {
        newSize = get_nextPrime(oldSize);

    } // end if
    else
    {
        newSize = get_previousPrime(oldSize);

    } // end else

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

HashMap::HashMap()
{   
    tableSize = 0;
    tableOccupation = 0;
    array.resize(3);

} // end class constructor

HashMap::HashMap(unsigned int startSize)
{   
    tableSize = 0;
    tableOccupation = 0;
    array.resize(startSize);

} // end class constructor

void HashMap::insert(std::string name, unsigned long int cpf)
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
            std::cout << "CPF Já Cadastrado." << std::endl << std::endl;
            return;

        } // end if
        else
        {
            attempt++;

        } // end else

    } // end while

    tableSize++;
    tableOccupation = ((double)tableSize / (double)array.get_size()) * 100;

    if(this->insertCheckResize())
    {
        this->resize(true);

    } // end if

} // end insert

arrayData HashMap::get(unsigned long int key)
{
    unsigned int searchIndex;
    unsigned int attempt = 0;

    arrayData indexData;

    while(true)
    {   
        searchIndex = doubleHash(key, attempt);
        
        indexData = array.get(searchIndex);

        if(indexData.cpf == key)
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

void HashMap::deleteElement(unsigned long int key)
{
    unsigned int deleteIndex;
    unsigned int attempt = 0;

    arrayData indexData;

    while(true)
    {   
        deleteIndex = doubleHash(key, attempt);
        
        indexData = array.get(deleteIndex);

        if(indexData.cpf == key)
        {
            break;

        } // end if
        else if(attempt == array.get_size())
        {
            return;;

        } // end if
        else
        {
            attempt++;

        } // end else

    } // end while

    arrayData deletedData = array.get(deleteIndex);

    deletedData.name = "";
    deletedData.cpf = 0;

    array.modifyElement(deleteIndex, deletedData);

    tableSize--;
    tableOccupation = ((double)tableSize / (double)array.get_size()) * 100;

    if(this->deleteCheckResize())
    {   
        this->resize(false);

    } // end if

} // end deleteElement

void HashMap::deleteHashMap()
{
    array.deleteArray();
    tableSize = 0;
    tableOccupation = 0;

} // deleteHashMap

void HashMap::printArray()
{
    array.print();

} // end print

void HashMap::printKey(unsigned long int key)
{
    arrayData data = this->get(key);

    std::cout << "Nome: " << data.name << std::endl;
    std::cout << "CPF: " << data.cpf << std::endl << std::endl;
    
} // end printKey

void HashMap::print()
{   
    unsigned int arraySize = array.get_size();

    arrayData printData;

    for(unsigned int i = 0; i < arraySize; i++)
    {
        printData = array.get(i);
        
        if(printData.cpf != 0)
        {
            std::cout << "Nome: " << printData.name << std::endl;
            std::cout << "CPF: " << printData.cpf << std::endl << std::endl;

        } // end if

    } // end for

} // end print

unsigned int HashMap::get_tableSize()
{
    return tableSize;

} // end get_tableSize

double HashMap::get_tableOccupation()
{    
    return tableOccupation;

} // end get_tableOccupation

void HashMap::printStatus()
{
    std::cout << "Tamanho do array do HashMap: " << array.get_size() << std::endl;
    std::cout << "Número de itens armazenados: " << tableSize << std::endl;
    std::cout << "Taxa de ocupação (%): " << tableOccupation << std::endl << std::endl;

} // end printHashStatus