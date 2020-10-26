/*
 *   AUTOR: Carlos Henrique Silva Correia de Araujo
 *   ENGENHARIA DE COMPUTAÇÃO - UFPB
 *   https://github.com/ch94ca
 *     
 */ 

#include <iostream>
#include "include/Queue.hpp"

using namespace std;

int main(void){

        Queue queue;

        cout << "Queue is empty? " << queue.isEmpty() << endl;
        
        queue.enqueue(5);
        queue.enqueue(12);
        queue.enqueue(2);
        queue.enqueue(3);
        queue.enqueue(22);
        queue.enqueue(32);

        cout << "Queue is empty? " << queue.isEmpty() << endl;

        queue.print();

        cout << "Dequeue: " << queue.dequeue() << endl;
        cout << "Dequeue: " << queue.dequeue() << endl;
        cout << "Dequeue: " << queue.dequeue() << endl;

        queue.print();

        queue.emptyQueue();

        queue.print();
        
        cout << "Queue is empty? " << queue.isEmpty() << endl;

        return 0;

} // End Main
