/*
** file: isll.cpp
**
** Integer Single Linked List
** UC: 21046 - EDAF @ UAb
** e-fólio A 2022-23
**
** Aluno: 2100927 - Ivo Baptista
*/

// Defina:
// em file.h as classes da estrutura de dados
// em file.cpp a implementação dos métodos das classes da estrutura de dados

#include <iostream>
#include "isll.h"
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>


// construtor e destrutor
ISll::ISll()
{
    head = nullptr;
   // tail = nullptr;
    n = 0;
}
//
ISll::~ISll()
{
    clear();
}

// métodos obrigatórios
bool ISll::isClear()
{
    return n == 0;
}

// outros métodos
void ISll::insert_0(int value)
{
    INode* node = new INode;
    node->item = value;
    node->next = nullptr;
    if (head == nullptr) {
        head = node;
        tail = node;
    }
    else {
        node->next = head;
        head = node;
    }
    n++;
}

//insere no fim da lista
void ISll::insert_end(int value)
{
    INode* node = new INode;
    node->item = value;
    node->next = nullptr;
    if (tail == nullptr) {
        head = node;
        tail = node;
    }
    else {
        tail->next = node;
        tail = node;
    }
    n++;
}

//imprime o primeiro nó da lista
void ISll::print_0()
{
    if (head == NULL) {
        std::cout << "Comando print_0: Lista vazia!" << std::endl;
        return;
    }
    std::cout << "Lista(0)=" << " " << head->item << std::endl;
}

//imprime o último nó da lista
void ISll::print_end() {
        
        //verificação de lista vazia
        if(head == NULL) {
            std::cout << "Comando print_end: Lista vazia!" << std::endl;
            return;
        }
        
        //cria um nó temporário que liga ao nó já existente na lista, para não se perder a referência da mesma (igual ao método de inserir no fim da fila)
        else {
            INode *temp = head;
            while(temp->next != NULL) {
                temp = temp->next;
            }
            std::cout << "Lista(end)= " << temp->item << std::endl; // imprime o último nó adicionado
        }
}

//imprime toda a lista
void ISll::print()
{
    if (n == 0) {
       std::cout << "Comando print: Lista vazia!" << std::endl;
    }
    else {
        INode* node = head;
        std::cout << "Lista=";
    while (node != nullptr) {
        std::cout <<  " " << node->item;
        node = node->next;
    }
        std::cout << std::endl;
    }
}

//apaga o primeiro nó da lista
void ISll::delete_0()
{
    if (head == NULL) {
        std::cout << "Comando delete_0: Lista vazia!" << std::endl;
    return;
    }
    INode* node = head;
    head = head->next;
    delete node;
    n--;
}

//apaga o último nó da lista
void ISll::delete_end()
{
    INode* node = find_prev(tail);
    delete tail;
    tail = node;
    tail->next = nullptr;
    n--;
}

//tamanho da lista
int ISll::dim()
{
   return n;
    // std::cout << n << endl;
}

//apaga a lista
void ISll::clear()
{
    while (n > 0) {
        delete_0();
    }
}

//encontra o nó 
void ISll::find(int value)
{
    
    if(head == NULL) {
        std::cout << "Comando find: Lista vazia!" << std::endl;
        return;
    }
    else{
        INode* node = head;
        int pos = 0;
        while (node != nullptr) {
            if (node->item == value) {
            std::cout << "Item " << value << " na posicao " << pos << std::endl;
            }
            node = node->next;
            pos++;
        }
     }   
     // std::cout << "Item " << value << " nao encontrado!" << std::endl;     
}

//encontra o nó maximo
void ISll::find_max()
{
      if(head == NULL) {
        std::cout << "Comando find_max: Lista vazia!" << std::endl;
        return;
    }
    else 
    {
        INode* node = head;
        int max = node->item;
        int pos = 0;
        int i = 0;
        while (node != nullptr) {
            if (node->item > max) {
            max = node->item;
            pos = i;
            }
        node = node->next;
        i++;
    }
    std::cout << "Max Item " << max << " na posicao " << pos << std::endl;
    }
}

//apaga o nó na posição indicada
void ISll::delete_pos(int pos)
{
    if (head == nullptr) {
        std::cout << "Comando delete_pos: Lista vazia!" << std::endl;
        return;
    }
    else if (pos >= n || pos < 0) {
        std::cout << "Comando delete_pos: Posicao invalida!" << std::endl;
        return;
    }
    else {
        INode* node = head;
        INode* prev = nullptr;
        for (int i = 0; i < pos; i++) {
            prev = node;
            node = node->next;
        }
        if (prev == nullptr) {
            head = node->next;
        }
        else {
            prev->next = node->next;
        }
        delete node;
        n--;
    }
}

//invertendo a lista entre duas posições
void ISll::invert_range(int pos1, int pos2) {
    //inverte todos os elementos entre as posições indicadas
    if (pos1 < 0 || pos1 >= n || pos2 < 0 || pos2 >= n) {
        std::cout << "Posicao invalida" << std::endl;
        return;
    }

    //criar lista auxiliar
    ISll tlist;
    INode *temp = head;
    //inserir os valores na lista auxiliar
    for (int i = 0; i <= pos2; i++) {
        if (i >= pos1) {
            //inserir no inicio da lista auxiliar
            tlist.insert_0(temp->item);
        }
        //avançar para o próximo nó
        temp = temp->next;
    }
   //guardar os valores invertidos na lista original
    temp = head;
    //inserir os valores na lista original
    for (int i = 0; i <= pos2; i++) {
        if (i >= pos1) {
            temp->item = tlist.head->item;
            //apagar o primeiro nó da lista auxiliar
            tlist.delete_0();
        }
        //avançar para o próximo nó
        temp = temp->next;
    }
}

//encontra o nó na posição indicada
INode* ISll::find_pos(int pos) {
    if (pos < 0 || pos >= n) return nullptr;

    INode* node = head;
    for (int i = 0; i < pos; i++) {
        node = node->next;
    }
    return node;
}
//
INode* ISll::find_prev(INode* node) {
    if (node == head) return nullptr;

    INode* prev = head;
    while (prev->next != node) {
        prev = prev->next;
    }
    return prev;
}

// EOF
