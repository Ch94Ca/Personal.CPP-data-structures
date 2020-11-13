/*
 *  Dynamic Array
 * 
 *  Author: Carlos Henrique Silva Correia de Araujo
 *  Computer engineering - UFPB (Undergraduate)
 *  github.com/Ch94Ca
 * 
 *  Description:
 *     
 *    Dynamic Array implementation.
 * 
 *     Supported operations:
 *      
 *      - resize:
 *          resize array size
 *
 *      - get:
 *          return array content by index
 *
 *      - get_size:
 *          return array size
 *
 *      - print:
 *          print entire array data
 *
 *      - insertFirst:
 *          insert element in the first position of array
 *
 *      - insertLast:
 *          insert element in the last position of array
 *
 *      - insertAt:
 *          insert element in array middle by index
 *
 *      - modifyElement:
 *          modify array element by index
 *
 *      - deleteElement:
 *          delete array element by index
 *
 *      - deleteArray:
 *          delete entire array
 */

#include "include/DynamicArray.hpp"
#include <cstdlib>
#include <iostream>

// inicializa o array vazio
DynamicArray::DynamicArray()
{
    array = nullptr;
    size = 0;

} // end class constructor

// inicializa o array com o tamanho enviado 
// para o construtor na chamada
DynamicArray::DynamicArray(unsigned int size)
{   
    // aloca dinamicamente o espaço de memória para o array
    array = (int*) malloc(sizeof(int) * size);

    // exibe menssagem e encerra a execução em caso de 
    // erro de alocação
    if(array == NULL)
    {
        std::cout << "Memory Allocation Failed" << std::endl;
        exit(1);

    } // end if

    // inicializa com 0 os valores no array
    for(unsigned int i = 0; i < size; i++)
    {
        array[i] = 0;

    } // end for

    // armazena o tamanho do array
    this->size = size;

} // end class constructor

// redimensiona o array dinamicamente com o o tamanho
// enviado como argumento na chamada do método
void DynamicArray::resize(unsigned int newSize)
{   
    // aloca dinamicamente o novo espaço de memória para o array
    // a função realloc mantém os dados previamente armazenados
    array = (int*) realloc(array, sizeof(int) * newSize);

    // exibe menssagem e encerra a execução em caso de 
    // erro de alocação
    if(array == NULL)
    {
        std::cout << "Memory Re-allocation Failed" << std::endl;
        exit(1);

    } // end if

    // inicializa com 0 os valores das novas posições no array
    for(unsigned int i = size; i < newSize; i++)
    {
        array[i] = 0;

    } // end for

    // armazena o novo tamanho do array
    size = newSize;

} // end resize

// retorna o valor do array indicado pelo indice
// passado como argumento na chamada do método
int DynamicArray::get(unsigned int index)
{
    return array[index];

} // end get

// retorna o tamanho do array
unsigned int DynamicArray::get_size()
{
    return size;

} // end get_size

// imprime todos os valores armazenados no array
void DynamicArray::print()
{
    std::cout << "{";

    for(unsigned int i = 0; i < size; i++)
    {
        std::cout << array[i];

        if(i != size - 1)
        {
            std::cout << ", ";

        } // end if

    } // end for

    std::cout << "}" << std::endl;

} // end print

// redimensiona e insere um elemento na primeira posição
// do array, "empurrando" todos os outros elementos para o fim
// do array
void DynamicArray::insertFirst(int data)
{   
    // adiciona uma posição no array atual
    this->resize(size + 1);

    // "empurra" todos os dados do array atual 
    // uma posição
    for(unsigned int i = (size - 1); i > 0; i--)
    {
        array[i] = array [i - 1];

    } // end if
    
    // insere o dado passado como argumento na chamada
    // do método, na primeira posição do array
    array[0] = data;

} // end insertFirst

// redimensiona e insere um elemento na ultima posição
// do array
void DynamicArray::insertLast(int data)
{   
    // adiciona uma posição no array atual
    this->resize(size + 1);

    // insere o dado passado como argumento na chamada
    // do método, na última posição do array
    array[size - 1] = data;

} // end insert data

// insere o elemento no meio do array no índice passado
// como argumento na chamada do método, "empurrando" 
// os elementos subsequentes para o fim do array
void DynamicArray::insertAt(unsigned int index, int data)
{   
    // se a posição para inserção for menor
    // que o tamanho atual do array
    if(index < size)
    {   
        // adiciona uma posição ao array atual
        this->resize(size + 1);

        // "empurra" todos os dados do array atual a partir
        // da posição que o novo elemento será inserido
        for(unsigned int i = (size - 1); i > index; i--)
        {
            array[i] = array [i - 1];

        } // end if
        
        // insere o elemento no indice passado como argumento
        array[index] = data;
    
    } // end if
    
    // se a posição para inserção for maior
    // que o tamanho atual do array
    else
    {   
        unsigned int previousSize = size;

        // redimensiona o array adicionando as posições necessárias
        this->resize(index + 1);

        // atribui 0 a todas as posições adicionadas
        for(unsigned int i = previousSize; i < size; i++)
        {
            array[i] = 0;

        } // end for

        // insere o elemento no indice passado como argumento
        array[index] = data;

    } // end if

} // end insertAt

// modifica um elemento do array no índice passado como argumento
// na chamada do método
void DynamicArray::modifyElement(unsigned int index, int data)
{
    array[index] = data;

} // end modifyElement

// remove um elemento do array
void DynamicArray::deleteElement(unsigned int index)
{   
    // se o tamanho do array for 1, chama o método 
    // para apagar todo o array
    if(size == 1)
    {
        this->deleteArray();
        return;

    } // end if

    // reposiciona os elementos a partir do índice
    // "puxando" os mesmos para o inicio do array
    for(unsigned int i = index; i < size; i++)
    {
        array[i] = array[i + 1];

    } // end if

    // remove uma posição do array
    this->resize(size - 1);

} // end DynamicArray

// remove todo o array
void DynamicArray::deleteArray()
{
    free(array);
    array = nullptr;
    size = 0;

} // end deleteArray

