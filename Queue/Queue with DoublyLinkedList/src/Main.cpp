/*
 *  Queue with DoublyLinkedList test Code
 * 
 *  Author: Carlos Henrique Silva Correia de Araujo
 *  Computer engineering - UFPB (Undergraduate)
 *  github.com/Ch94Ca
 * 
 *  Description:
 *     
 *     Queue with DoublyLinkedList test Code
 * 
 */

#include <iostream>
#include "include/Queue.hpp"

using namespace std;

int main(void){

        Queue queue;

        cout << "- Fila criada..." << endl << endl;
        cout << "- A fila está vazia? " << queue.isEmpty() << endl << endl;
        cout << "- Enfileirando valores na fila..." << endl << endl;
        
        queue.enqueue(5);
        queue.enqueue(12);
        queue.enqueue(2);
        queue.enqueue(3);
        queue.enqueue(22);
        queue.enqueue(32);

        cout << "- A fila está vazia? " << queue.isEmpty() << endl << endl;
        cout << "- Tamanho da fila: " << queue.get_size() << endl << endl;
        cout << "- Imprimindo a fila: " << endl << endl;
        queue.print();

        cout << "- Desenfileirando valores: " << endl << endl;

        cout << "Desenfileirar: " << queue.dequeue() << endl;
        cout << "Desenfileirar: " << queue.dequeue() << endl;
        cout << "Desenfileirar: " << queue.dequeue() << endl << endl;

        cout << "- Tamanho da fila: " << queue.get_size() << endl << endl;
        cout << "- Imprimindo a fila: " << endl << endl;
        queue.print();

        cout << "- Acessando valores do início da fila sem remove-los: " << endl << endl;

        cout << "Início da fila: " << queue.peek() << endl << endl;

        cout << "- Tamanho da fila: " << queue.get_size() << endl << endl;
        cout << "- Imprimindo a fila: " << endl << endl;
        queue.print();

        cout << "- Apagando toda a fila..." << endl << endl;
        queue.deleteQueue();

        cout << "- Tamanho da fila: " << queue.get_size() << endl << endl;
        cout << "- Imprimindo a fila: " << endl << endl;
        queue.print();

        return 0;

} // End Main
