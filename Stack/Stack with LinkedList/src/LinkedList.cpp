/*
 *  Linked List
 * 
 *  Author: Carlos Henrique Silva Correia de Araujo
 *  Computer engineering - UFPB (Undergraduate)
 *  github.com/Ch94Ca
 * 
 *  Description:
 *     
 *     linked list implementation.
 * 
 *     Supported operations:
 *      
 *      - get_FirstNodePtr:
 *          return first node pointer
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
 *      - insertFirstNode:
 *          insert node at list start
 * 
 *      - insertLastNode:
 *          insert node at list end
 * 
 *      - insertNodeAt:
 *          insert node in the middle list by index
 * 
 *       - modifyNodeData:
 *          modify node value by index
 *
 *      - deleteNode:
 *          delete list node by index
 * 
 *      - deleteList:
 *          delete entire list
 * 
 */

#include <iostream>
#include <new>
#include "include/LinkedList.hpp"
#include "include/LinkedListNode.hpp"

// inicializa a lista vazia
LinkedList::LinkedList()
{
    firstNodePtr = nullptr;
    size = 0;

} // end class constructor

// retorna o tamanho da lista
unsigned int LinkedList::get_size()
{
    return size;

} // end get_size

// imprime os valores armazenados na lista
void LinkedList::print()
{   
    std::cout << "{";

    for(unsigned int i = 0; i < size; i++)
        {
                std::cout << this->get(i);

                if(i != (size - 1))
                {
                    std::cout << ", ";

                } // end if

        } // end for

        std::cout << "}" << std::endl;

} // end printList

// retorna o ponteiro para o primeiro nó da lista
LinkedListNode* LinkedList::get_firstNodePtr()
{
    return firstNodePtr;

} // end get_firstNodePtr

// retorna o ponteiro para o nó do índice requisitado
LinkedListNode* LinkedList::get_NodePtr(unsigned int index)
{   
    LinkedListNode* accessNode = firstNodePtr;

    // percorre a lista e armazena o ponteiro no indice
    // selecionado
    for(unsigned int i = 0; i < index; i++)
    {
        accessNode = accessNode->get_nextNodePtr();

    } // end for

    // retorna o ponteiro do nó no índice dado
    return accessNode;

} // end get_NodePtr

// retorna o dado armazenado no nó do índice requisitado
int LinkedList::get(unsigned int index)
{   
    LinkedListNode* accessNode = firstNodePtr;

    // percorre a lista e armazena o ponteiro no indice
    // selecionado
    for(unsigned int i = 0; i < index; i++)
    {
        accessNode = accessNode->get_nextNodePtr();

    } // end for

    // retorna o dado armazenado no índice dado
    return accessNode->get_nodeData();

} // end accessNodeData

// insere um nó no início da lista
void LinkedList::insertFirstNode(int data)
{
    LinkedListNode* newNode;

    // tenta alocar dinamicamente o espaço de memória para o nó
    // encerra a execução em caso de erro de alocação
    try
    {
        newNode = new LinkedListNode;

    } // end try
    catch(std::bad_alloc&)
    {            
        std::cout << "Memory allocation failure." << std::endl;
        exit(1);
 
    } // end catch

    // se o tamanho da lista for 0, define o ponteiro
    // para o proximo elemento do novo nó como nulo
    if(size == 0)
    {
        newNode->set_nextNodePtr(nullptr);

    } // end if

    // se o tamanho da lista for maior que 0
    // define o ponteiro para o antigo primeiro nó
    // como ponteiro para o próximo do do novo nó
    else if(size > 0)
    {
        newNode->set_nextNodePtr(firstNodePtr);

    } // end if/else if

    // define o novo nó como primeiro nó da lista
    firstNodePtr = newNode;

    // insere o dado no nó criado
    newNode->set_nodeData(data);

    // incrementa o tamanho da lista
    size++;

} // end insertFirstNode

// insere um nó no fim da lista 
void LinkedList::insertLastNode(int data)
{
    LinkedListNode* newNode;

    // tenta alocar dinamicamente o espaço de memória para o nó
    // encerra a execução em caso de erro de alocação
    try
    {
        newNode = new LinkedListNode;

    } // end try
    catch(std::bad_alloc&)
    {            
        std::cout << "Memory allocation failure." << std::endl;
        exit(1);
 
    } // end catch

    // define o ponteiro para o próximo nó do novo nó
    // como nulo
    newNode->set_nextNodePtr(nullptr);

    // insere o dado no nó criado
    newNode->set_nodeData(data);

    // se o tamanho da lista for maior que 0, define o ponteiro
    // para o próximo nó do antigo ultimo nó, como o ponteiro
    // para o novo nó criado
    if(size > 0)
    {
        LinkedListNode* previousLastNode = this->get_NodePtr(size - 1);
        previousLastNode->set_nextNodePtr(newNode);

    } // end if

    // se o tamanho da lista for 0, define o novo nó como primeiro nó da lista
    else if(size == 0)
    {
        firstNodePtr = newNode;

    } // end else if

    // incrementa o tamanho da lista
    size++;

} // end insertNodeAtEnd

// insere um nó no meio da lista no índice dado
// "empurrando" o nó atual para frente
void LinkedList::insertNodeAt(unsigned int index, int data)
{   
    // se o índice dado for 0, insere o nó no início da lista
    if(index == 0)
    {
        this->insertFirstNode(data);
        return;

    } // end if

    // se o índice dado for igual o tamanho da lista,
    // insere o nó no fim da lista
    if(index == size)
    {
        this->insertLastNode(data);
        return;

    } // end if

    LinkedListNode* newNode;

    // tenta alocar dinamicamente o espaço de memória para o nó
    // encerra a execução em caso de erro de alocação
    try
    {
        newNode = new LinkedListNode;

    } // end try
    catch(std::bad_alloc&)
    {            
        std::cout << "Memory allocation failure." << std::endl;
        exit(1);
 
    } // end catch      

    // armazena o nó anterior ao nó a ser inserido
    LinkedListNode* previousNode = this->get_NodePtr(index - 1);

    // define o ponteiro para o próximo nó do novo nó
    // como sendo o ponteiro para o próximo nó
    // do elemento anterior (nó do índice onde o novo nó será inserido)
    newNode->set_nextNodePtr(previousNode->get_nextNodePtr());
    previousNode->set_nextNodePtr(newNode);

    // insere o dado no nó criado
    newNode->set_nodeData(data);

    // incrementa o tamanho da lista
    size++;

} // end insertNodeAt

// modifica o dado em um nó existente
void LinkedList::modifyNodeData(unsigned int index, int data)
{
    // acessa o ponteiro para o nó no índice dado
    LinkedListNode *accessNode = this->get_NodePtr(index);

    // modifica o dado no nó do índice dado
    accessNode->set_nodeData(data);

} // end modifyNodeData

// remove o nó do índice dado
void LinkedList::deleteNode(unsigned int index)
{   
    // acessa o ponteiro para o nó no índice dado
    LinkedListNode* deletedNode = this->get_NodePtr(index);

    // se o tamanho atual da lista for 1, define os ponteiros
    // para o primeiro e ultimo nó como sendo nulos
    if (size == 1)
    {
        firstNodePtr = nullptr;

    } // end if

    // se o índice dado for 0, define o próximo nó
    // como novo primeiro nó da lista
    if(index == 0)
    {
        firstNodePtr = deletedNode->get_nextNodePtr();

    } // end if

    // se o índice dado for no ultimo elemento da lista
    // define o ponteiro para o nó anterior como nulo
    else if(index == (size - 1))
    {
        LinkedListNode* newLastNode = this->get_NodePtr(index - 1);
        newLastNode->set_nextNodePtr(nullptr);

    } // end else/if

    // se o índice estiver no meio da lista, define que o ponteiro para 
    // o próximo nó do nó anterior será o ponteiro para o proximo nó
    // do nó que será deletado
    else
    {
        LinkedListNode* previousNode = this->get_NodePtr(index - 1);
        previousNode->set_nextNodePtr(deletedNode->get_nextNodePtr());

    } // end else

    // libera o espaço de memória do nó deletado
    delete deletedNode;

    // decrementa o tamanho da lista
    size--;

} // end deleteNode

// remove todos os nós da lista
void LinkedList::deleteList()
{
    LinkedListNode *accessNode = firstNodePtr;
    LinkedListNode *nextNode = firstNodePtr;

    for (unsigned int i = 0; i < size; i++)
    {
        accessNode = nextNode;
        nextNode = accessNode->nextNodePtr;

        delete accessNode;

    } // end for

    // define o ponteiro para o primeiro nó da lista como nulo
    // e o tamanho da lista como 0
    firstNodePtr = nullptr;
    size = 0;

} // end deleteList
