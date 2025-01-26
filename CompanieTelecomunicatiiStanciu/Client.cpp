#include "Client.h"
#include <iostream>


Client::Client(const std::string& nume, const PachetServicii& pachet)
    : nume(nume), pachet(pachet) {
}


void Client::adaugaFactura(const Factura& factura) {
    istoricFacturi.push_back(factura);
}


void Client::afiseazaIstoric() const {
    std::cout << "Istoric facturi pentru clientul: " << nume << "\n";
    for (const auto& factura : istoricFacturi) {
        factura.afiseaza(); 
    }
}


const std::string& Client::getNume() const {
    return nume;
}


const PachetServicii& Client::getPachet() const {
    return pachet;
}
