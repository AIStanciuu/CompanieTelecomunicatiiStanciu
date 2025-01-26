#ifndef FACTURA_H
#define FACTURA_H

class Client;

class Factura {
private:
    int id;
    Client& client; 
    double suma;
    bool platita;

public:
  
    Factura(int id, Client& client, double suma, bool platita);

   
    void platesteFactura();


    int getId() const;
    double getSuma() const;

 
    void afiseaza() const;
};

#endif
