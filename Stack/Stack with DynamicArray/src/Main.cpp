/*
 *   AUTOR: Carlos Henrique Silva Correia de Araujo
 *   ENGENHARIA DE COMPUTAÇÃO - UFPB
 *   https://github.com/ch94ca
 *     
 */ 

#include <iostream>
#include "include/Stack.hpp"

using namespace std;

int main(void){

        Stack stack;

        cout << "Stack is empty? " << stack.isEmpty() << endl;
        
        stack.push(2);
        stack.push(12);
        stack.push(4);
        stack.push(3); 

        cout << "Stack is empty? " << stack.isEmpty() << endl;

        stack.print();

        cout << "Pop: " << stack.pop() << endl;
        cout << "Pop: " << stack.pop() << endl;

        stack.print();

        cout << "Peek: " << stack.peek() << endl;

        stack.print();

        stack.emptyStack();

        stack.print();

        return 0;

} // End Main
