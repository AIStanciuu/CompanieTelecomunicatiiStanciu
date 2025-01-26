#ifndef PACHET_SERVICII_H
#define PACHET_SERVICII_H

#include <string>
#include <iostream>

class PachetServicii {
private:
    std::string nume;        
    int minute;              
    int sms;                 
    int traficInternet;       
    double pret;            

public:
    
    PachetServicii(const std::string& nume = "", int minute = 0, int sms = 0, int traficInternet = 0, double pret = 0.0);


    const std::string& getNume() const;
    double getPret() const;

  
    void afiseaza() const;
};

#endif
