/*
 *  Queue
 * 
 *  Author: Carlos Henrique Silva Correia de Araujo
 *  Computer engineering - UFPB (Undergraduate)
 *  github.com/Ch94Ca
 * 
 *  Description:
 *     
 *    Queue implementation using DoublyLinkedList.
 * 
 *     Supported operations:
 *      
 *      - get_size:
 *          return stack size
 *
 *      - enqueue:
 *          enqueue (insert) element in the end of the queue
 *
 *      - dequeue:
 *          dequeue (return and remove) the element at queue start
 *
 *      - peek:
 *          peek (return only) element in queue start
 *
 *      - isEmpty:
 *          return true if queue is empty and false if not
 *
 *      - deleteQueue:
 *          delete entire queue
 *
 *      - print:
 *          print all elements in the queue
 *
 */

#include <iostream>
#include "include/Queue.hpp"

Queue::Queue()
{


} // end class constructor

// retorna o tamanho da fila
unsigned int Queue::get_size()
{   
    return queue.get_size();

} // end get_size

// insere um elemento no fim da fila
// nesta implementação com lista duplamente encadeada
// defini que o 'fim' da fila, seria 
// o ultimo elemento da lista
void Queue::enqueue(int data)
{
    queue.insertLastNode(data);

} // end enqueue

// retorna e remove o elemento no início da lista
int Queue::dequeue()
{   
    // armazena o valor de retorno
    int retVal = queue.get(0);

    // remove o elemento do array
    queue.deleteNode(0);

    // retorna o valor armazenado
    return retVal;

} // end dequeue

// apenas retorna, sem remover o elemento no topo da pilha
int Queue::peek()
{
    return queue.get(0);

} // end peek

// retorna true caso a fila esteja vazia
// e false caso não esteja
bool Queue::isEmpty()
{   
    // se o tamanho da lista for igual a 0
    // retorna true
    if(queue.get_size() == 0)
    {
        return true;

    } // end if
    else
    {
        return false;

    } // end else
 
} // end isEmpty

// deleta a fila
void Queue::deleteQueue()
{
    queue.deleteList();

} // end emptyQueue

// imprime a fila
void Queue::print()
{
    unsigned int queueSize = queue.get_size();
    
    std::cout << "Fim da fila -> ";

    for(int i = (queueSize - 1); i >= 0; i--)
    {
        std::cout << queue.get(i);

        if(i != 0)
        {
            std::cout << " | ";

        } // end if

    } // end for

    std::cout << " -> Início da fila" << std:: endl << std::endl;

} // end print