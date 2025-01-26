#ifndef RECLAMATIE_H
#define RECLAMATIE_H

#include <string>
#include "Client.h"

class Reclamatie {
private:
    int id;                
    Client& client;         
    std::string problema;      
    bool rezolvata;            

public:
    
    Reclamatie(int id, Client& client, const std::string& problema, bool rezolvata = false);

    
    void solutioneaza();

    
    void afiseaza() const;
};

#endif
