/*
 *  Author: Carlos Henrique Silva Correia de Araujo
 *  Computer engineering - UFPB (Undergraduate)
 *  github.com/Ch94Ca
 *
 *  Description:
 *     
 *     Doubly linked list class implementation
 *    
 */ 

#include <iostream>
#include "include/HashMap.hpp"

using namespace std;

int main(void)
{       
        HashMap hash;

        cout << "- HashMap vazio, status: " << endl << endl;

        hash.printStatus();

        cout << "- inserindo alguns elementos no HashMap..." << endl << endl;

        hash.insert("joão", 58979635095);
        hash.insert("José", 17841339062);

        cout << "- imprimindo todos os elementos no array do HashMap: " << endl << endl;
        
        hash.printArray();

        cout << "- Status do HashMap após a inserção: " << endl << endl;

        hash.printStatus();

        cout << "- Inserindo mais elementos no HashMap..." << endl << endl;

        hash.insert("Maria", 96569359002);
        hash.insert("Lúcia", 22893731090);

        cout << "- imprimindo todos os elementos válidos no HashMap: " << endl << endl;
        
        hash.print();

        cout << "- Status do HashMap após a inserção: " << endl << endl;

        hash.printStatus();

        cout << "- Buscando elementos no HashMap a partir da chave: " << endl << endl;

        hash.printKey(58979635095); // João
        hash.printKey(96569359002); // Maria

        cout << "- Buscando um elemento que não existe no HashMap" << endl << endl;

        hash.printKey(96569259002); // Não Existe

        cout << "- Removendo dois elementos do HashMap..." << endl << endl;

        hash.deleteElement(17841339062); // José
        hash.deleteElement(22893731090); // Lúcia

        cout << "- imprimindo todos os elementos válidos no HashMap: " << endl << endl;
        
        hash.print();

        cout << "- Status do HashMap após a remoção: " << endl << endl;

        hash.printStatus();
 
        cout << "- Removendo os dois últimos elementos do HashMap..." << endl << endl;

        hash.deleteElement(58979635095); // João
        hash.deleteElement(96569359002); // Maria

        cout << "- imprimindo todos os elementos no array do HashMap: " << endl << endl;
        
        hash.printArray();

        cout << "- Status do HashMap após a remoção: " << endl << endl;

        hash.printStatus();

        return 0;

} // End Main