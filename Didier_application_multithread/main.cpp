#include <cstdio>

#include <iostream>
#include <thread>
#include <chrono>

extern void afficherNombresPairs();
extern void afficherNombresImpairs();

int main() {
    // Création des threads pour les tâches
    std::thread threadPairs(afficherNombresPairs);
    std::thread threadImpairs(afficherNombresImpairs);

    // Attente de la fin des threads
    threadPairs.join();
    threadImpairs.join();

    // Affichage du message de fin de calcul
    std::cout << "Fin de calcul" << std::endl;

    return 0;
}

#include <iostream>
#include <thread>
#include <chrono>

void afficherNombresPairs() {
    for (int i = 0; i <= 50; i += 2) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Pair: " << i << std::endl;
    }
}

#include <iostream>
#include <thread>
#include <chrono>

void afficherNombresImpairs() {
    for (int i = 1; i <= 50; i += 2) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Impair: " << i << std::endl;
    }
}
