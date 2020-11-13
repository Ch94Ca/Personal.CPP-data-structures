/*
 *  Stack
 * 
 *  Author: Carlos Henrique Silva Correia de Araujo
 *  Computer engineering - UFPB (Undergraduate)
 *  github.com/Ch94Ca
 * 
 *  Description:
 *     
 *    Stack implementation using DynamicArray.
 * 
 *     Supported operations:
 *      
 *      - get_size:
 *          return stack size
 *
 *      - push:
 *          push (insert) element in stack top
 *
 *      - pop:
 *          pop (return and remove) element in stack top
 *
 *      - peek:
 *          peek (return only) element in stack top
 *
 *      - isEmpty:
 *          return true if stack is empty and false if not
 *
 *      - deleteStack:
 *          delete entire stack
 *
 *      - print:
 *          print all elements in the stack
 *
 */

#include <iostream>
#include "include/Stack.hpp"

Stack::Stack()
{

} // end class constructor

// retorna o tamanho da pilha
unsigned int Stack::get_size()
{
    return stack.get_size();

} // end get_size

// insere um elemento no topo da pilha
// nesta implementação com array dinamico
// defini que o 'topo' da pilha, seria 
// o ultimo elemento do array, por ser mais fácil
// de redimensionar o array através do ultimo elemento
void Stack::push(int data)
{   
    // insere o elemento no fim do array 
    stack.insertLast(data);

} // end push

// retorna e remove o elemento no topo da lista
int Stack::pop()
{   
    // recupera o tamanho do array
    unsigned int stackSize = stack.get_size();

    // armazena o valor de retorno
    int retData = stack.get(stackSize - 1);

    // como o elemento no topo é o ultimo elemento
    // no array dinamico, basta remover uma posição
    // do array dinamico
    stack.resize(stackSize - 1);

    // retorna o valor
    return retData;

} // end pop

// apenas retorna, sem remover o elemento no topo da pilha
int Stack::peek()
{
    return stack.get(stack.get_size() - 1);

} // end peek

// retorna true caso a pilha esteja vazia
// e false caso não esteja
bool Stack::isEmpty()
{   
    // se o tamanho do array for igual a 0
    // retorna true
    if(stack.get_size() == 0)
    {
        return true;

    } // end if
    else
    {
        return false;

    } // end else

} // end isempty

// deleta a pilha
void Stack::deleteStack()
{   
    // apenas deleta o array dinamico
    stack.deleteArray();

} // end deleteStack

// imprime a pilha
void Stack::print()
{   
    unsigned int stackSize = stack.get_size();

    for(int i = (stackSize - 1); i >= 0; i--)
    {
         std::cout << stack.get(i) << std::endl;

    } // end for

    std::cout << std::endl;

} // end print