/*
 *  Doubly Linked List
 * 
 *  Author: Carlos Henrique Silva Correia de Araujo
 *  Computer engineering - UFPB (Undergraduate)
 *  github.com/Ch94Ca
 * 
 *  Description:
 *     
 *     Doubly linked list implementation.
 * 
 *     Supported operations:
 *      
 *      - get_FirstNodePtr:
 *          return first node pointer
 * 
 *      - get_LastNodePtr:
 *          return last node pointer
 * 
 *      - get_NodePtr:
 *          return node pointer by index 
 * 
 *      - get_size: 
 *          return list size
 * 
 *      - get: 
 *          return list content by index
 * 
 *      - print:
 *          print list data in forward order
 *      
 *      - printBackward:
 *          print list data in backward order  
 * 
 *      - printListPtr:
 *          print list data and pointers for each node (for debug) 
 *  
 *      - insertFirstNode:
 *          insert node at list start
 * 
 *      - insertLastNode:
 *          insert node at list end
 * 
 *      - insertNodeAt:
 *          insert node in the middle list by index
 * 
 *       - insertNodeAt:
 *          modify node value by index
 *
 *      - deleteNode:
 *          delete list node by index
 * 
 *      - deleteList:
 *          delete entire list
 */

#include "include/DoublyLinkedList.hpp"
#include "include/DoublyLinkedListNode.hpp"

#include <iostream>
#include <new>

// inicializa a lista vazia
DoublyLinkedList::DoublyLinkedList()
{
    lastNodePtr = nullptr;
    firstNodePtr = nullptr;
    size = 0;

} // end class constructor

// retorna o tamanho da lista
unsigned int DoublyLinkedList::get_size()
{
    return size;

} // end get_size

// imprime os valores da lista
void DoublyLinkedList::print()
{
    DoublyLinkedListNode *accessNode = firstNodePtr;

    std::cout << "{";

    for (unsigned int i = 0; i < size; i++)
    {
        std::cout << accessNode->get_nodeData();
        accessNode = accessNode->get_nextNodePtr();

        if (i < (size - 1))
        {
            std::cout << ", ";

        } // end if

    } // end for

    std::cout << "}" << std::endl;

} // end printList

// imprime os valores da lista de trás para frente
void DoublyLinkedList::printBackward()
{
    DoublyLinkedListNode *accessNode = lastNodePtr;

    std::cout << "{";

    for (unsigned int i = size; i > 0; i--)
    {
        std::cout << accessNode->get_nodeData();
        accessNode = accessNode->get_previousNodePtr();

        if (i != 1)
        {
            std::cout << ", ";

        } // end if

    } // end for

    std::cout << "}" << std::endl;

} // end printBackwart

// imprime para cada nó da lista, o dado armazenado,
// ponteiro para o próprio nó, e para o nó antecessor
// e sucessor. útil para depuração.
void DoublyLinkedList::printListPtr()
{
    DoublyLinkedListNode *currentNodePtr;
    DoublyLinkedListNode *previousNodePtr;
    DoublyLinkedListNode *nextNodePtr;

    std::cout << std::endl
              << "List size: " << size << std::endl;
    std::cout << "First node pointer: " << firstNodePtr << std::endl;

    for (unsigned int i = 0; i < size; i++)
    {
        currentNodePtr = this->get_NodePtr(i);
        previousNodePtr = currentNodePtr->get_previousNodePtr();
        nextNodePtr = currentNodePtr->get_nextNodePtr();

        std::cout << std::endl
                  << "Node: " << i << std::endl;
        std::cout << "Node data: " << this->get(i) << std::endl;
        std::cout << "Previous node pointer: " << previousNodePtr << std::endl;
        std::cout << "Current node pointer : " << currentNodePtr << std::endl;
        std::cout << "Next node pointer    : " << nextNodePtr << std::endl
                  << std::endl;

    } // end for

    std::cout << "Last node pointer: " << lastNodePtr << std::endl;

} // end printListPtr

// retorna o ponteiro para o primeiro nó da lista
DoublyLinkedListNode *DoublyLinkedList::get_firstNodePtr()
{
    return firstNodePtr;

} // end get_firstNodePtr

// retorna o ponteiro para o último nó da lista
DoublyLinkedListNode *DoublyLinkedList::get_lastNodePtr()
{
    return lastNodePtr;

} // end get_firstNodePtr

// retorna o ponteiro para o nó do índice requisitado
DoublyLinkedListNode *DoublyLinkedList::get_NodePtr(unsigned int index)
{
    // armazena o meio da lista
    unsigned int listMiddle = size / 2;

    DoublyLinkedListNode *accessNode = nullptr;

    // se o índice estiver até o meio da lista,
    // realiza o acesso a partir do primeiro elemento
    if (index <= listMiddle)
    {
        accessNode = firstNodePtr;

        for (unsigned int i = 0; i < index; i++)
        {
            accessNode = accessNode->get_nextNodePtr();

        } // end for

    } // end if

    // se o índice estiver depois do meio da lista
    // realiza o acesso a partir do ultimo elemento
    else if (index > listMiddle)
    {
        accessNode = lastNodePtr;
        unsigned int backwardIndex = (size - 1) - index;

        for (unsigned int i = 0; i < backwardIndex; i++)
        {
            accessNode = accessNode->get_previousNodePtr();

        } // end for

    } // end else if

    return accessNode;

} // end get_NodePtr

// retorna o dado armazenado no nó do índice requisitado
int DoublyLinkedList::get(unsigned int index)
{
    // calcula o meio da lista
    unsigned int listMiddle = size / 2;

    DoublyLinkedListNode *accessNode;

    // se o índice estiver até o meio da lista,
    // realiza o acesso a partir do primeiro elemento
    if (index <= listMiddle)
    {
        accessNode = firstNodePtr;

        for (unsigned int i = 0; i < index; i++)
        {
            accessNode = accessNode->get_nextNodePtr();

        } // end for

    } // end if

    // se o índice estiver depois do meio da lista
    // realiza o acesso a partir do ultimo elemento
    else if (index > listMiddle)
    {
        accessNode = lastNodePtr;
        unsigned int backwardIndex = (size - 1) - index;

        for (unsigned int i = 0; i < backwardIndex; i++)
        {
            accessNode = accessNode->get_previousNodePtr();

        } // end for

    } // end else if

    return accessNode->get_nodeData();

} // end accessNodeData

// insere um nó no início da lista
void DoublyLinkedList::insertFirstNode(int data)
{
    DoublyLinkedListNode *newNode;

    // tenta alocar dinamicamente o espaço de memória para o nó
    // encerra a execução em caso de erro de alocação
    try
    {
        newNode = new DoublyLinkedListNode;

    } // end try
    catch (std::bad_alloc &)
    {
        std::cout << "Memory allocation failure." << std::endl;
        exit(1);

    } // end catch

    // se o tamanho atual da lista for maior que 0, insere o nó
    // no início da lista e define o ponteiro para o próximo
    // nó como sendo o ponteiro do antigo primeiro nó, e o ponteiro
    // para o nó anterior do antigo primeiro nó como o ponteiro
    // para o novo nó adicionado
    if (size > 0)
    {
        newNode->set_nextNodePtr(firstNodePtr);
        firstNodePtr->set_previousNodePtr(newNode);

    } // end if/else if

    // se o tamanho atual da lista for 0, define o ponteiro para o
    // ultimo nó, como sendo o ponteiro para o novo nó criado
    else
    {
        lastNodePtr = newNode;

    } // end if

    // define o ponteiro para o primeiro nó como sendo o ponteiro
    // do novo nó criado
    firstNodePtr = newNode;

    // insere o dado no nó criado
    newNode->set_nodeData(data);

    // incrementa o tamanho da lista
    size++;

} // end insertNodeAtStart

// insere um nó no fim da lista 
void DoublyLinkedList::insertLastNode(int data)
{
    DoublyLinkedListNode *newNode;

    // tenta alocar dinamicamente o espaço de memória para o nó
    // encerra a execução em caso de erro de alocação
    try
    {
        newNode = new DoublyLinkedListNode;

    } // end try
    catch (std::bad_alloc &)
    {
        std::cout << "Memory allocation failure." << std::endl;
        exit(1);

    } // end catch

    // insere o dado no nó criado
    newNode->set_nodeData(data);

    // se o tamanho atual da lista for maior que 0, insere o nó
    // no fim da lista e define o ponteiro para o nó anterior
    // como sendo o ponteiro do antigo último nó, e o ponteiro
    // para o próximo nó do antigo último nó como o ponteiro
    // para o novo nó adicionado
    if (size > 0)
    {
        lastNodePtr->set_nextNodePtr(newNode);
        newNode->set_previousNodePtr(lastNodePtr);

    } // end if

    // se o tamanho atual da lista for 0, define o ponteiro para o
    // primeiro nó, como sendo o ponteiro para o novo nó criado
    else
    {
        firstNodePtr = newNode;

    } // end else/if

    // define que o ponteiro para o último nó será o ponteiro para o
    // novo nó
    lastNodePtr = newNode;

    // incrementa o tamanho da lista
    size++;

} // end insertLastNode

// insere um nó no meio da lista no índice dado
// "empurrando" o nó atual para frente
void DoublyLinkedList::insertNodeAt(unsigned int index, int data)
{
    // se o índice dado for 0, insere o nó no início da lista
    if (index == 0)
    {
        this->insertFirstNode(data);
        return;

    } // end if

    // se o índice dado for igual o tamanho da lista,
    // insere o nó no fim da lista
    else if (index == size)
    {
        this->insertLastNode(data);
        return;

    } // end else/if

    // se o índice dado for maior que o tamanho atual da lista
    // insere o nó no índice dado, completando com 0 os nós
    // intermediários caso seja necessário
    else if (index > size)
    {
        unsigned int newZeroNodes = index - size;

        for (unsigned int i = 0; i < newZeroNodes; i++)
        {
            this->insertLastNode(0);

        } //end for

        this->insertLastNode(data);
        return;

    } // end else/if

    DoublyLinkedListNode *newNode;

    // tenta alocar dinamicamente o espaço de memória para o nó
    // encerra a execução em caso de erro de alocação
    try
    {
        newNode = new DoublyLinkedListNode;

    } // end try
    catch (std::bad_alloc &)
    {
        std::cout << "Memory allocation failure." << std::endl;
        exit(1);

    } // end catch

    // armazena os ponteiros para o nó atual e o nó anterior
    // ao nó atual
    DoublyLinkedListNode *nextNode = this->get_NodePtr(index);
    DoublyLinkedListNode *previousNode = this->get_NodePtr(index - 1);

    // define o ponteiro para o nó anterior do nó que estava
    // no índice dado como sendo o ponteiro para o nó criado
    nextNode->set_previousNodePtr(newNode);

    // define o ponteiro para o próximo nó do nó anterior ao índice dado
    // como sendo o ponteiro para o nó criado
    previousNode->set_nextNodePtr(newNode);

    // define os ponteiros para o nó anterior e próximo nó do nó
    // criado, como sendo o ponteiro do nó anterior ao índice dado,
    // e o ponteiro do antigo nó do índice dado respectivamente.
    newNode->set_previousNodePtr(previousNode);
    newNode->set_nextNodePtr(nextNode);

    // insere o dado no nó criado
    newNode->set_nodeData(data);

    // incrementa o tamanho da lista
    size++;
    
} // end insertNodeAt

// modifica o dado em um nó existente
void DoublyLinkedList::modifyNodeData(unsigned int index, int data)
{
    // acessa o ponteiro para o nó no índice dado
    DoublyLinkedListNode *accessNode = this->get_NodePtr(index);

    // modifica o dado no nó do índice dado
    accessNode->set_nodeData(data);

} // end modifyNodeData

// remove o nó do índice dado
void DoublyLinkedList::deleteNode(unsigned int index)
{
    // acessa o ponteiro para o nó no índice dado
    DoublyLinkedListNode *deletedNode = this->get_NodePtr(index);

    // se o tamanho atual da lista for 1, define os ponteiros
    // para o primeiro e ultimo nó como sendo nulos
    if (size == 1)
    {
        firstNodePtr = nullptr;
        lastNodePtr = nullptr;

    } // end if

    // se o índice dado for 0, define o ponteiro para o nó anterior
    // do próximo nó ao índice dado como sendo nulo, e o ponteiro
    // para o primeiro nó como sendo o ponteiro para o póximo nó
    // ao índice dado
    else if (index == 0)
    {
        DoublyLinkedListNode *nextNode = deletedNode->get_nextNodePtr();

        nextNode->set_previousNodePtr(nullptr);
        firstNodePtr = nextNode;

    } // end else if

    // se o índice dado for igual ao tamanho da lista -1 (último elemento)
    // define o novo último nó como sendo o nó anterior ao nó do índice dado
    else if (index == (size - 1))
    {
        DoublyLinkedListNode *newLastNode = this->get_NodePtr(index - 1);
        newLastNode->set_nextNodePtr(nullptr);
        lastNodePtr = newLastNode;

    } // end else if

    // se o índice dado estiver no meio da lista, define o ponteiro
    // para o próximo elemento do nó anterior ao índice dado como sendo
    // o ponteiro para o próximo nó do índice dado e o ponteiro para o
    // próximo nó do índice dado como sendo o ponteiro para o nó anterior
    // do índice dado
    else
    {
        DoublyLinkedListNode *previousNode = this->get_NodePtr(index - 1);
        DoublyLinkedListNode *nextNode = this->get_NodePtr(index + 1);

        previousNode->set_nextNodePtr(nextNode);
        nextNode->set_previousNodePtr(previousNode);

    } // end else

    // remove o nó do índice dado
    delete deletedNode;

    // decrementa o valor da lista
    size--;

} // end deleteNode

// remove todos os nós da lista
void DoublyLinkedList::deleteList()
{
    DoublyLinkedListNode *accessNode = firstNodePtr;
    DoublyLinkedListNode *nextNode = firstNodePtr;

    // percorre toda lista deletando cada nó
    for (unsigned int i = 0; i < size; i++)
    {
        accessNode = nextNode;
        nextNode = accessNode->nextNodePtr;

        delete accessNode;

    } // end for

    // define os ponteiros para o primeiro e o último elemento
    // como nulos e o tamanho da lista como 0
    firstNodePtr = nullptr;
    lastNodePtr = nullptr;
    size = 0;

} // end deleteList
