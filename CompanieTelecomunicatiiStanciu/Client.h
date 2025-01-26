#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <vector>
#include "PachetServicii.h"
#include "Factura.h"

class Client {
private:
    std::string nume;                
    PachetServicii pachet;           
    std::vector<Factura> istoricFacturi; 

public:
   
    Client(const std::string& nume, const PachetServicii& pachet);


    void adaugaFactura(const Factura& factura);

    void afiseazaIstoric() const;


    const std::string& getNume() const;
    const PachetServicii& getPachet() const;
};

#endif
