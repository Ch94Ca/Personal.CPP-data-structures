/*
 *  Stack with DynamicArray test Code
 * 
 *  Author: Carlos Henrique Silva Correia de Araujo
 *  Computer engineering - UFPB (Undergraduate)
 *  github.com/Ch94Ca
 * 
 *  Description:
 *     
 *     Stack with DynamicArray test Code
 * 
 */

#include <iostream>
#include "include/Stack.hpp"

using namespace std;

int main(void){

        Stack stack;

        cout << "- Pilha criada..." << endl << endl;
        cout << "- A pilha está vazia? " << stack.isEmpty() << endl << endl;
        cout << "- Empilhando valores na pilha..." << endl << endl;

        stack.push(2);
        stack.push(12);
        stack.push(4);
        stack.push(3); 

        cout << "- A pilha está vazia? " << stack.isEmpty() << endl << endl;
        cout << "- Tamanho da pilha: " << stack.get_size() << endl << endl;
        cout << "- Imprimindo a pilha: " << endl << endl;
        stack.print();

        cout << "- Desempilhando valores: " << endl << endl;

        cout << "Desempilhar: " << stack.pop() << endl;
        cout << "Desempilhar: " << stack.pop() << endl << endl;

        cout << "- Tamanho da pilha: " << stack.get_size() << endl << endl;
        cout << "- Imprimindo a pilha: " << endl << endl;
        stack.print();

        cout << "- Acessando valores do topo sem remove-los: " << endl << endl;

        cout << "Topo: " << stack.peek() << endl << endl;

        cout << "- Tamanho da pilha: " << stack.get_size() << endl << endl;
        cout << "- Imprimindo a pilha: " << endl << endl;
        stack.print();

        cout << "- Apagando toda a pilha..." << endl << endl;
        stack.deleteStack();

        cout << "- Tamanho da pilha: " << stack.get_size() << endl << endl;
        cout << "- Imprimindo a pilha: " << endl << endl;
        stack.print();

        return 0;

} // End Main
