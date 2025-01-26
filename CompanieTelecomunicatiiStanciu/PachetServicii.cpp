#include "PachetServicii.h"


PachetServicii::PachetServicii(const std::string& nume, int minute, int sms, int traficInternet, double pret)
    : nume(nume), minute(minute), sms(sms), traficInternet(traficInternet), pret(pret) {
}


const std::string& PachetServicii::getNume() const {
    return nume;
}


double PachetServicii::getPret() const {
    return pret;
}


void PachetServicii::afiseaza() const {
    std::cout << "Pachet Servicii: " << nume << "\n"
        << "Minute incluse: " << minute << "\n"
        << "SMS incluse: " << sms << "\n"
        << "Trafic internet inclus: " << traficInternet << " MB\n"
        << "Pret: " << pret << " RON\n";
}
