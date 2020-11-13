/*
 *  Stack
 * 
 *  Author: Carlos Henrique Silva Correia de Araujo
 *  Computer engineering - UFPB (Undergraduate)
 *  github.com/Ch94Ca
 * 
 *  Description:
 *     
 *    Stack implementation using LinkedList.
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
// nesta implementação com lista encadeada
// defini que o 'topo' da pilha, seria
// o primeiro elemento da lista encadeada
// por ser mais fácil inserir e acessar 
// este elemento
void Stack::push(int data)
{   
    // insere o elemento no inicio da lista
    stack.insertFirstNode(data);

} // end push

// retorna e remove o elemento no topo da lista
int Stack::pop()
{   
    // armazena o valor de retorno 
    int retData = stack.get(0);

    // remove o elemento da lista
    stack.deleteNode(0);

    // retorna o valor armazenado
    return retData;

} // end pop

// apenas retorna, sem remover o elemento no topo da pilha
int Stack::peek()
{
    return stack.get(0);

} // end peek

// retorna true caso a pilha esteja vazia
// e false caso não esteja
bool Stack::isEmpty()
{   
    // se o tamanho da lista for igual a 0
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
    // apenas deleta a lista encadeada
    stack.deleteList();

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