#include "ProgramLoialitate.h"
#include <iostream>

void ProgramLoialitate::adaugaPuncte(Client& client, int puncte) {
    std::cout << "Clientul " << client.getNume() << " a primit " << puncte << " puncte de loialitate.\n";
}