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

#include "include/HashMap.hpp"
#include <iostream>
#include <string>
#include <cmath>

// função de dispersão com o método de primeiro de primeira posição livre
// para tratamento de colisões
unsigned int HashMap::firstEmpty(unsigned long int key, unsigned int attempt)
{   
    // armazena o tamanho do array
    unsigned int size = array.get_size();

    // metodo da divisão
    unsigned int hash = key % size;

    // o índice será o valor obtido pelo método da divisão
    // + o número de tentativas que foram feitas para tratar
    // a colisão. Quando o número de tentativas for 0, o 
    // valor retornado será apenas o índice gerado pelo
    // método da divisão
    unsigned int index = hash + attempt;

    // faz o incremento circular, caso o indice seja
    // maior que o tamanho do array
    if(index >= size)
    {
        index = index - size;

    } // end if

    // retorna o indice obtido
    return index;

} // end hash_0

// retorna o próximo numero primo a partir do número
// enviado como argumento na chamada do método
// usado para redimensionar o array
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

// retorna numero primo anterior a partir do número
// enviado como argumento na chamada do método
// usado para redimensionar o array
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

// retorna true caso a taxa de ocupação da tabela
// seja maior que 75%, utilizado no método de inserção
bool HashMap::insertCheckResize()
{   
    if(mapOccupation > 75.0)
    {
        return true;

    } // end if

    return false;

} // end checkResize

// retorna true caso a taxa de ocupação da tabela
// seja menor que 50%, utilizado no método de remoção
bool HashMap::deleteCheckResize()
{
    if(mapOccupation < 50.0 && array.get_size() > 3)
    {
        return true;

    } // end if

    return false;

} // end deleteCheckResize

// redimensiona a tabela de dispersão
void HashMap::resize(bool resizeTo)
{   

    unsigned int oldSize = array.get_size();
    unsigned int newSize;

    // se o parametro resizeTo for TRUE, a tabela
    // irá aumentar de tamanho, e o novo tamanho
    // será o próximo número primo a partir do
    // tamanho atual
    if(resizeTo == true)
    {
        newSize = get_nextPrime(oldSize);

    } // end if

    // se o parametro resizeTo for FALSE, a tabela
    // irá diminuir de tamanho, e o novo tamanho
    // será o número primo anterior a partir do
    // tamanho atual
    else
    {
        newSize = get_previousPrime(oldSize);

    } // end else

    // array temporário que irá armazenar os dados
    // contidos na tabela
    DynamicArray tempArray;

    // armazena os dados contidos na tabela no array temporário
    for(unsigned int i = 0; i < oldSize; i++)
    {
        tempArray.insertLast(array.get(i));

    } // end if

    // deleta o array atual da tabela
    array.deleteArray();

    // define como 0 os valores de tamanho da tabela
    // e ocupação da tabela
    mapSize = 0;
    mapOccupation = 0;

    // redimensiona o array com o novo tamanho
    array.resize(newSize);

    // reinsere e remapeia os elementos que foram salvos no array temporário
    // para o array da tabela
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
    mapSize = 0;
    mapOccupation = 0;
    array.resize(3);

} // end class constructor

// insere um elemento na tabela utilizando o CPF como chave
void HashMap::insert(std::string name, unsigned long int cpf)
{   
    // armazena o índice onde será inserido o elemento
    unsigned int insertIndex;
    
    // armazena o número de tentativas de inserção
    unsigned int attempt = 0;

    // cria a struct a ser inserida na tabela
    arrayData insertData;
    insertData.name = name;
    insertData.cpf = cpf;
    
    // loop infinito, o loop só é quebrado caso o elemento
    // seja inserido ou ja esteja presente na tabela
    while(true)
    {   
        // realiza o mapeamento do índice a partir da chave (CPF)
        // e o número de tentativas de inserção realizadas
        insertIndex = firstEmpty(cpf, attempt);
        
        // recupera o dado armazenado no índice obtido
        arrayData indexData = array.get(insertIndex);

        // verifica se o elemento no índice obtido está livre
        // isto é feito verificando se o CPF no elemento é igual
        // a zero, se estiver livre, o elemento é inserido no índice
        // e o loop infinito é encerrado
        if(indexData.cpf == 0)
        {
            array.modifyElement(insertIndex, insertData);
            break;

        } // end if

        // caso a chave data (CPF) seja igual a chave encontrada no índice
        // retorna uma menssagem informando que o CPF ja foi cadastrado
        else if(indexData.cpf == cpf)
        {
            std::cout << "CPF Já Cadastrado." << std::endl << std::endl;
            return;

        } // end if

        // incrementa o número de tentativas
        else
        {
            attempt++;

        } // end else

    } // end while

    // incrementa o tamanho da tabela
    // esta variável armazena o número de elementos que estão
    // inseridos na tabela, e não o tamanho do array.
    mapSize++;

    // define a taxa de ocupação (%)
    mapOccupation = ((double)mapSize / (double)array.get_size()) * 100;

    // verifica se há a necessidade de redimensionar a tabela.
    // caso a taxa de ocupação seja maior que 75%, a tabela
    // é redimensionada
    if(this->insertCheckResize())
    {
        this->resize(true);

    } // end if

} // end insert

// retorna o dado a partir de uma chave passada
// como argumento na chamada do método
arrayData HashMap::get(unsigned long int key)
{   
    // armazena o índice a ser acessado
    unsigned int searchIndex;

    // armazena o número de tentativas de inserção
    unsigned int attempt = 0;

    // cria a struct que irá armazenar o dado recuperado
    arrayData indexData;

    // loop infinito, o loop só é quebrado caso o elemento
    // seja inserido ou ja esteja presente na tabela
    while(true)
    {   
        // realiza o mapeamento do índice a partir da chave (CPF)
        // e o número de tentativas de inserção realizadas
        searchIndex = firstEmpty(key, attempt);

        // recupera o dado armazenado no índice obtido
        indexData = array.get(searchIndex);

        // se a chave (CPF) no dado armazenado for igual
        // a chave enviada como argumento na chamada 
        // do método, retorna o dado
        if(indexData.cpf == key)
        {
            return indexData;

        } // end if

        // se o número de tentativas for igual o número ao número do
        // array, encerra o loop infinito
        else if(attempt == array.get_size())
        {
            break;

        } // end if

        // incrementa o número de tentativas
        else
        {
            attempt++;

        } // end else

    } // end while

    // define um elemento "nulo" para ser retornado caso 
    // a chave dada não seja encontrada
    indexData.name = "NULL";
    indexData.cpf = 0;

    // retorna o elemento nulo
    return indexData;

} // end get

// deleta um elemento da tabela a partir de uma chave
// enviada como argumento na chamada do método
void HashMap::deleteElement(unsigned long int key)
{
    unsigned int deleteIndex;
    unsigned int attempt = 0;

    arrayData indexData;

    // loop infinito para encontrar o índice onde o elemento
    // está armazenado. Mesma lógica do método get
    while(true)
    {   
        deleteIndex = firstEmpty(key, attempt);
        
        indexData = array.get(deleteIndex);

        if(indexData.cpf == key)
        {
            break;

        } // end if
        else if(attempt == array.get_size())
        {
            return;

        } // end if
        else
        {
            attempt++;

        } // end else

    } // end while

    // inicializa um elemento vazio para inserir no local
    // do elemento a ser deletado
    arrayData deletedData;
    deletedData.name = "";
    deletedData.cpf = 0;

    // modifica o elemento no índice encontrado
    // inserindo o elemento vazio nele
    array.modifyElement(deleteIndex, deletedData);

    // diminui o tamanho da tabela
    mapSize--;

    // recalcula a taxa de ocupação da tabela
    mapOccupation = ((double)mapSize / (double)array.get_size()) * 100;

    // verifica se há a necessidade de redimensionar a tabela.
    // caso a taxa de ocupação seja menor que 50%, a tabela
    // é redimensionada
    if(this->deleteCheckResize())
    {   
        this->resize(false);

    } // end if

} // end deleteElement

// deleta toda a tabela
// apenas deleta o array e define como 0
// o tamanho da tabela e taxa de ocupação
void HashMap::deleteHashMap()
{   
    array.deleteArray();
    mapSize = 0;
    mapOccupation = 0;

} // deleteHashMap

// imprime todo o array da tabela
// inclusive os elementos 'vazios'
void HashMap::printArray()
{
    array.print();

} // end print

// imprime um elemento a partir de sua chave
void HashMap::printKey(unsigned long int key)
{
    arrayData data = this->get(key);

    std::cout << "Nome: " << data.name << std::endl;
    std::cout << "CPF: " << data.cpf << std::endl << std::endl;
    
} // end printKey

// imprime apenas o elementos válidos na tabela
void HashMap::print()
{   
    unsigned int arraySize = array.get_size();

    arrayData printData;

    for(unsigned int i = 0; i < arraySize; i++)
    {
        printData = array.get(i);
        
        // verifica se a chave (CPF) não é nula
        // e imprime o elemento caso não seja
        if(printData.cpf != 0)
        {
            std::cout << "Nome: " << printData.name << std::endl;
            std::cout << "CPF: " << printData.cpf << std::endl << std::endl;

        } // end if

    } // end for

} // end print

// retorna o tamanho da tabela (apenas elementos válidos armazenados)
unsigned int HashMap::get_mapSize()
{
    return mapSize;

} // end get_mapSize

// retorna a taxa de ocupação (%)
double HashMap::get_mapOccupation()
{    
    return mapOccupation;

} // end get_mapOccupation

// imprime o status da tabela, tamanho do array, tamanho da tabela e taxa de ocupação
void HashMap::printStatus()
{
    std::cout << "Tamanho do array do HashMap: " << array.get_size() << std::endl;
    std::cout << "Número de itens armazenados: " << mapSize << std::endl;
    std::cout << "Taxa de ocupação (%): " << mapOccupation << std::endl << std::endl;

} // end printHashStatus