#include <iostream>
#include <string>
#include <list>
#include <time.h>
#include <iomanip>

using namespace std;

class Furnizor {
    private:
        string nume;
        string iban;
    public:
        Furnizor(string nume = "", string iban = "");
        string GetNume();        
        friend istream& operator>>(istream& is, Furnizor& furnizor);
        friend ostream& operator<<(ostream& os, Furnizor& furnizor);
        ~Furnizor();
};

class Factura {
    private:
        int id;
        Furnizor* furnizor;
        double valoare;
    public:
        Factura(int id = 0, Furnizor* furnizor = nullptr, double valoare = 0);
        friend istream& operator>>(istream& is, Factura& factura);
        friend ostream& operator<<(ostream& os, Factura& factura);
        ~Factura();
};

class Chitanta {
    private:
        int id;
        Factura* factura;
        double valoare;
    public:
        Chitanta(int id = 0, Factura* factura = nullptr, double valoare = 0);
};

class LocDeConsum {
    private:
        string nume;
        string adresa;
    public:
        LocDeConsum(string nume, string adresa);
        void setNume(string value);
        string getNume();
        void PrintInfo();
};

class Aplicatie {
    private:
        static list<Furnizor> furnizori;
        static list<Chitanta> chitante;
        static list<LocDeConsum> locuriDeConsum;
        static list<Factura> facturi;
    public:
        Aplicatie() = delete;
        static void Init();
        static void ShowOpeningView();
        static void AdaugaFurnizor();
        static void ShowListaFurnizoriView();
        static void ShowAdaugaFurnizorView();
        static void ShowListaFacturiView();
        static void ShowAdaugaFacturaView();
        static void ShowMainMenuView();
        static void ShowClosingView();
        static Furnizor* GetFurnizorByNume(string nume);
        static int GetNextFacturaId();
};

list<Furnizor> Aplicatie::furnizori;
list<Chitanta> Aplicatie::chitante;
list<LocDeConsum> Aplicatie::locuriDeConsum;
list<Factura> Aplicatie::facturi;

void Aplicatie::Init() {
    Aplicatie::furnizori.clear();
    Aplicatie::chitante.clear();
    Aplicatie::locuriDeConsum.clear();
    Aplicatie::facturi.clear();
    Aplicatie::ShowOpeningView();
}

void Aplicatie::ShowOpeningView() {
    cout << "Aplicatia se deschide..." << endl;
    Aplicatie::ShowMainMenuView();
}

void Aplicatie::AdaugaFurnizor() {
    Furnizor furnizor;
    cin >> furnizor;
    Aplicatie::furnizori.push_back(furnizor);
}

void Aplicatie::ShowListaFurnizoriView() {
    cout << endl;
    cout << "Nume - IBAN (" << Aplicatie::furnizori.size() << (Aplicatie::furnizori.size() == 1 ? " inregistrare)" : " inregistrari)") << endl;
    cout << "- - - - - - - - - - - - - - - - - - - -" << endl;
    for (list<Furnizor>::iterator it = Aplicatie::furnizori.begin(); it != Aplicatie::furnizori.end(); it++) {
        cout << (*it);
    }

    Aplicatie::ShowMainMenuView();
}

void Aplicatie::ShowAdaugaFurnizorView() {
    Furnizor furnizor;
    cin >> furnizor;
    Aplicatie::furnizori.push_back(furnizor);
    Aplicatie::ShowMainMenuView();
}

void Aplicatie::ShowListaFacturiView() {
    cout << endl;
    cout << "Id - Furnizor - Valoare (" << Aplicatie::facturi.size() << (Aplicatie::facturi.size() == 1 ? " inregistrare)" : " inregistrari)") << endl;
    cout << "- - - - - - - - - - - - - - - - - - - -" << endl;
    for (list<Factura>::iterator it = Aplicatie::facturi.begin(); it != Aplicatie::facturi.end(); it++) {
        cout << (*it);
    }

    Aplicatie::ShowMainMenuView();
}

void Aplicatie::ShowAdaugaFacturaView() {
    Factura factura;
    cin >> factura;
    Aplicatie::facturi.push_back(factura);
    Aplicatie::ShowMainMenuView();
}

void Aplicatie::ShowMainMenuView() {
    cout << endl;
    cout << "Meniul principal" << endl;
    cout << "- - - - - - - - -" << endl;
    cout << "0. Inchide aplicatia" << endl;
    cout << "1. Arata lista furnizori" << endl;
    cout << "2. Adauga furnizor" << endl;
    cout << "3. Arata lista facturi" << endl;
    cout << "4. Adauga factura" << endl;
    cout << "5. Arata lista chitante" << endl;
    cout << "6. Adauga chitanta" << endl;

    int choice;

    do {
        cout << "Alegeti o optiune valida: " << endl;
        cin >> choice;

        switch(choice) {
            case 0:
                Aplicatie::ShowClosingView();
                break;
            case 1:
                Aplicatie::ShowListaFurnizoriView();
                break;
            case 2:
                Aplicatie::ShowAdaugaFurnizorView();
                break;
            case 3:
                Aplicatie::ShowListaFacturiView();
                break;
            case 4:
                Aplicatie::ShowAdaugaFacturaView();
                break;
            default:
                choice = -1;
                break; 
        }
    } while (choice == -1);
}

void Aplicatie::ShowClosingView() {
    cout << "Aplicatia se inchide..." << endl;
}

Furnizor* Aplicatie::GetFurnizorByNume(string nume) {
    for (list<Furnizor>::iterator it = Aplicatie::furnizori.begin(); it != Aplicatie::furnizori.end(); it++) {
        if (it->GetNume() == nume) {
            return &(*it);
        }
    }

    return nullptr;
}

int Aplicatie::GetNextFacturaId() {
    return Aplicatie::facturi.size() + 1;
}

Furnizor::Furnizor(string nume, string iban) {
    this->nume = nume;
    this->iban = iban;
}

string Furnizor::GetNume() {
    return this->nume;
}

istream& operator>>(istream& is, Furnizor& furnizor) {
    cout << endl;
    cout << "Introduceti datele furnizorului" << endl;
    cout << "- - - - - - - - - - - - - - - -" << endl;
    
    cout << "Nume = ";
    is >> furnizor.nume;
    
    cout << "IBAN = ";
    is >> furnizor.iban;

    return is;
}

ostream& operator<<(ostream& os, Furnizor& furnizor) {
    os << furnizor.nume << " - " << furnizor.iban << endl;

    return os;
}

Furnizor::~Furnizor() { }

Factura::Factura(int id, Furnizor* furnizor, double valoare) :
    id(id),
    furnizor(furnizor),
    valoare(valoare) {
}

istream& operator>>(istream& is, Factura& factura) {
    factura.id = Aplicatie::GetNextFacturaId();

    cout << endl;
    cout << "Introduceti datele facturii" << endl;
    cout << "- - - - - - - - - - - - - - - -" << endl;
    
    cout << "Nume furnizor = ";
    string numeFurnizor;
    is >> numeFurnizor;
    factura.furnizor = Aplicatie::GetFurnizorByNume(numeFurnizor);

    cout << "Valoare = ";
    is >> factura.valoare;

    return is;
}

ostream& operator<<(ostream& os, Factura& factura) {
    os << factura.id << " - " << factura.furnizor->GetNume() << " - " << to_string(factura.valoare) << endl;

    return os;
}

Factura::~Factura() { }

Chitanta::Chitanta(int id, Factura* factura, double valoare) :
    id(id),
    factura(factura),
    valoare(valoare) {
}

LocDeConsum::LocDeConsum(string nume, string adresa) {
    this->nume = nume;
    this->adresa = adresa;
}

void LocDeConsum::setNume(string value) {
    this->nume = value;
}

string LocDeConsum::getNume() {
    return this->nume;
}

void LocDeConsum::PrintInfo() {
    cout << "Loc de consum - " << this->nume << " - " << this->adresa << endl;
}

int main() {
    Aplicatie::Init();

    return 0;
}