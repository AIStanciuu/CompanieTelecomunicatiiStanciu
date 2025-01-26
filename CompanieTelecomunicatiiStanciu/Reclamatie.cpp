#include "Reclamatie.h"
#include <iostream>


Reclamatie::Reclamatie(int id, Client& client, const std::string& problema, bool rezolvata)
    : id(id), client(client), problema(problema), rezolvata(rezolvata) {
}


void Reclamatie::solutioneaza() {
    if (!rezolvata) {
        rezolvata = true;
        std::cout << "Reclamatia " << id << " a fost rezolvata.\n";
    }
    else {
        std::cout << "Reclamatia " << id << " era deja rezolvata.\n";
    }
}


void Reclamatie::afiseaza() const {
    std::cout << "Reclamatia ID: " << id
        << ", Client: " << client.getNume()
        << ", Problema: " << problema
        << ", Rezolvata: " << (rezolvata ? "Da" : "Nu")
        << std::endl;
}
