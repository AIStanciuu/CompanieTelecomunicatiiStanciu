#include "Raportare.h"
#include <iostream>

void Raportare::genereazaRaportClient(const Client& client) {
    std::cout << "=== Raport pentru client: " << client.getNume() << " ===\n";
    client.afiseazaIstoric();
}
