#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Client.h"
#include "Factura.h"
#include "PachetServicii.h"
#include "Reclamatie.h"

using namespace std;
string generateRandomName() {
    const vector<string> fullNames = {
        "Nunio Bobilca",
        "Mihai Giju",
        "Tom Cringureanu",
        "Cosmin Ilie",
        "Vlad Manescu",
        "Mihai Cirlugea",
        "Denis Firu",
        "Eduard Lula",
        "Ciprian Dincu",
       
    };
    return fullNames[rand() % fullNames.size()];
}


vector<Client> generateRandomClients(PachetServicii& basic, PachetServicii& premium) {
    vector<Client> clients;
    int clientCount =1 ; 
    for (int i = 0; i < clientCount; ++i) {
        string name = generateRandomName();
        PachetServicii& chosenPackage = (rand() % 2 == 0) ? basic : premium;
        clients.emplace_back(name, chosenPackage);
    }
    return clients;
}



void mainMenu() {
    cout << "\nAlegeti categoria introducand numarul corespunzator:\n";
    cout << "1. Informati client\n";
    cout << "2. Informatii despre factura\n";
    cout << "3. Informatii despre pachetul de servicii\n";
    cout << "4. Informatii despre reclamatii\n";
    cout << "5. Delogare\n";
    cout << "Introduceti alegerea dumneavoastra: ";
}


void handleClientInfo(const vector<Client>& clients) {
    system("cls");
    cout << "--- Informatii Clienti ---\n";
    for (size_t i = 0; i < clients.size(); ++i) {
        cout << i + 1 << ". " << clients[i].getNume() << "\n";
        clients[i].getPachet().afiseaza();
        cout << "--------------------------------\n";
    }
}


void handleInvoiceInfo(Factura& factura) {
    system("cls");
    cout << "--- Informatii despre facturare ---\n";
    factura.afiseaza();
    cout << "Doriti sa platiti aceasta factura? (Y/N): ";
    char choice;
    cin >> choice;
    if (choice == 'Y' || choice == 'y') {
        factura.platesteFactura();
        factura.afiseaza();
    }
}


void handlePackageInfo(PachetServicii& basic, PachetServicii& premium) {
    system("cls");
    cout << "--- Informatii despre pachetul de servicii ---\n";
    basic.afiseaza();
    cout << "\n";
    premium.afiseaza();
}


void handleComplaintInfo(Reclamatie& reclamatie) {
    system("cls");
    cout << "--- Informatii despre reclamatii ---\n";
    reclamatie.afiseaza();
    cout << "Doriti sa rezolvati aceasta reclamatie? (Y/N): ";
    char choice;
    cin >> choice;
    if (choice == 'Y' || choice == 'y') {
        reclamatie.solutioneaza();
        reclamatie.afiseaza();
    }
}

int main() {
    srand(time(0)); 
    const string password = "Stanciu2024";
    string enteredPassword;
    int attempts = 3;

    while (attempts > 0) {
        cout << "Introduceti parola de administrator: ";
        cin >> enteredPassword;
        if (enteredPassword == password) {
            system("cls");
            cout << "Bine ati venit, dnl Administrator!\n";
            break;
        }
        else {
            attempts--;
            cout << "Parola incorecta. Mai aveti " << attempts << " incercari ramase.\n";
        }
        if (attempts == 0) {
            cout << "Prea multe incercari incorecte. Programul se inchide...\n";
            return 0;
        }
    }

    PachetServicii pachetBasic("Basic", 100, 1, 1, 20);
    PachetServicii pachetPremium("Premium", 500, 5, 5, 50);
    vector<Client> clients = generateRandomClients(pachetBasic, pachetPremium);
    Factura factura1(1, clients[0], 100, false);
    Reclamatie reclamatie1(1, clients[0], "Problema de facturare", false);


    char choice;
    do {
        mainMenu();
        cin >> choice;
        switch (choice) {
        case '1':
            handleClientInfo(clients);
            break;
        case '2':
            handleInvoiceInfo(factura1);
            break;
        case '3':
            handlePackageInfo(pachetBasic, pachetPremium);
            break;
        case '4':
            handleComplaintInfo(reclamatie1);
            break;
        case '5':
            system("cls");
            cout << "Delogare...\n";
            return 0;
        default:
            cout << "Alegere invalida. Incearca din nou.\n";
            break;
        }
        cout << "\nDoriti sa va intoarceti la meniul principal (Y/N): ";
        char returnToMenu;
        cin >> returnToMenu;
        if (returnToMenu != 'Y' && returnToMenu != 'y') {
            cout << "Programul se inchide. La revedere!\n";
            return 0;
        }
        system("cls");
    } while (true);

    return 0;
}
