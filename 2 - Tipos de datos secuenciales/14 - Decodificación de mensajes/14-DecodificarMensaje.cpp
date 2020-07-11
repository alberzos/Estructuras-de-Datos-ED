// Alvaro Berzosa Tordesillas
// E08

#include <iostream>
#include <fstream>
#include <string>
#include "queue_eda.h"
#include "stack_eda.h"


bool comprobarVocal(const char& c) {

    switch (std::tolower(c)) {
        case 'a': return true;
        case 'e': return true;
        case 'i': return true;
        case 'o': return true;
        case 'u': return true;
        default: return false;
    }

}



bool resuelveCaso() {

    std::string frase, sol = "";
    getline(std::cin, frase);

    queue<char> cola;
    stack<char> pila;

    if (!std::cin) return false;

    for (int i = 0; i < frase.size(); ++i) {
        if (i % 2 == 0)
            cola.push(frase[i]);
        else
            pila.push(frase[i]);
    }

    while (!pila.empty()) {
        cola.push(pila.top());
        pila.pop();
    }

    for (int i = 0; !cola.empty(); ++i) {
        if (comprobarVocal(cola.front())) {
            while (!pila.empty()) {
                sol += pila.top();
                pila.pop();
            }
            sol += cola.front();
        }
        else
            pila.push(cola.front());
        cola.pop();
    }

    while (!pila.empty()) {
        sol += pila.top();
        pila.pop();
    }

    std::cout << sol << "\n";

    return true;
}

int main() {

   

    while (resuelveCaso());


}