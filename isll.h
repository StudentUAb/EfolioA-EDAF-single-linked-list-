/*
** file: isll.h
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

#ifndef ISLL_H
#define ISLL_H


// definir nó
struct INode {
   // atributos obrigatórios
   int item;             // informação em cada nó
    INode* next;
    INode* prev;
   // // outros atributos e métodos (protótipos) livres
   // INode() {}
   // INode(int item): item(item), next(nullptr) {}
};

// definir lista
class ISll {
private:
   // atributos obrigatórios
   int n;                // dimensão atual da lista
   // outros atributos e métodos (protótipos) livres
   INode* head;
   INode* tail;
   INode* find_pos(int pos);
   INode* find_prev(INode* node);


public:
   // métodos obrigatórios
   bool isClear();   
   void insert_0(int value);
   void insert_end(int value);
   void print_0();
   void print_end();
   void print();
   void delete_0();
   void delete_end();
   int dim();
   void clear();
   void find(int value);
   void find_max();
   void delete_pos(int pos);
   void invert_range(int pos1, int pos2);


   // construtor e destrutor
   ISll();
   ~ISll();
};

#endif // ISLL_H

// EOF


