#include "Factura.h"
#include "Client.h" 
#include <iostream>


Factura::Factura(int id, Client& client, double suma, bool platita)
    : id(id), client(client), suma(suma), platita(platita) {
}


void Factura::platesteFactura() {
    if (!platita) {
        platita = true;
        std::cout << "Factura cu ID " << id << " a fost platita.\n";
    }
    else {
        std::cout << "Factura cu ID " << id << " este deja platita.\n";
    }
}


int Factura::getId() const {
    return id;
}


double Factura::getSuma() const {
    return suma;
}

void Factura::afiseaza() const {

        std::cout << "Factura ID: " << id
            << ", Suma: " << suma
            << ", Platita: " << (platita ? "Da" : "Nu")
            << "\n";
    
}

