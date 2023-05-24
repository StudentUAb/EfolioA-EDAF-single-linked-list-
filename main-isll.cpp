/*
** file: main-isll.cpp
**
** Integer Single Linked List
** UC: 21046 - EDAF @ UAb
** e-fólio A 2022-23
**
** Aluno: 2100927 - Ivo Baptista
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "isll.h"

// main
int main() {
    // criar lista
    ISll list;
    // ler comandos
    std::string line;
    while (std::getline(std::cin, line)) {
        // ignorar linhas em branco
        if (!line.empty() && line[0] != '#') {
            // ler comando
            std::istringstream iss(line);
            std::string cmd;
            // processar comando
            iss >> cmd;
            // processar argumentos
            if (cmd == "insert_0") {
                int value;
                while (iss >> value) {
                    list.insert_0(value);
                }
            } else if (cmd == "insert_end") {
                int value;
                while (iss >> value) {
                    list.insert_end(value);
                }
            } else if (cmd == "print_0") {
                list.print_0();
            } else if (cmd == "print_end") {
                list.print_end();
            } else if (cmd == "print") {
                list.print();
            } else if (cmd == "delete_0") {
                list.delete_0();
            } else if (cmd == "delete_end") {
                list.delete_end();
            } else if (cmd == "dim") {
                std::cout << "Lista tem " << list.dim() << " itens" << std::endl;
            } else if (cmd == "clear") {
                if (list.dim() == 0) {
                    // lista vazia
                    std::cout << "Comando clear: Lista vazia!" << std::endl;
                } else {
                    list.clear();
                }
            } else if (cmd == "find") {
                int item;
                while (iss >> item) {
                    list.find(item);
                }
            } else if (cmd == "find_max") {
                list.find_max();
            } else if (cmd == "delete_pos") {
                int pos;
                while (iss >> pos) {
                    if (pos >= 0) {
                        list.delete_pos(pos);
                    } else {
                        // posição inválida
                        std::cout << "Primeira posição da lista é a posição 0!" << std::endl;
                    }
                }
            } else if (cmd == "invert_range") {
                int pos1, pos2;
                if (iss >> pos1 >> pos2) {
                    list.invert_range(pos1, pos2);
                }
            }
        }
    }

    return 0;
}