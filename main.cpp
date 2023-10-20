#include <iostream>
#include <string>
#include <list>
#include <time.h>
#include <iomanip>

using namespace std;


// Clase
class Furnizor {
    private:
        string nume;
        string iban;
    public:
        Furnizor(string nume = "", string iban = "");
        Furnizor(const Furnizor& other);
        Furnizor& operator=(Furnizor& other);
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
        double valoareRamasa;
    public:
        Factura(int id = 0, Furnizor* furnizor = nullptr, double valoare = 0, double valoareRamasa = 0);
        Factura(const Factura& other);
        Factura& operator=(Factura& other);
        int GetId();
        void Achita(const double valoare);
        Furnizor* GetFurnizor();
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
        Chitanta(const Chitanta& other);
        Chitanta& operator=(Chitanta& other);
        Factura* GetFactura();
        friend istream& operator>>(istream& is, Chitanta& chitanta);
        friend ostream& operator<<(ostream& os, Chitanta& chitanta);
        ~Chitanta();
};

class Aplicatie {
    private:
        static list<Furnizor> furnizori;
        static list<Chitanta> chitante;
        static list<Factura> facturi;
    public:
        Aplicatie() = delete;
        Aplicatie(const Aplicatie& other) = delete;
        Aplicatie& operator=(Aplicatie& other);
        static void Init();
        static void ShowOpeningView();
        static void ShowListaFurnizoriView();
        static void ShowAdaugaFurnizorView();
        static void ShowListaFacturiView();
        static void ShowAdaugaFacturaView();
        static void ShowListaChitanteView();
        static void ShowAdaugaChitantaView();
        static void ShowMainMenuView();
        static void ShowClosingView();
        static Furnizor* GetFurnizorByNume(const string nume);
        static int GetNextIdFactura();
        static Factura* GetFacturaById(const int id);
        static int GetNextIdChitanta();
        ~Aplicatie();
};

list<Furnizor> Aplicatie::furnizori;
list<Chitanta> Aplicatie::chitante;
list<Factura> Aplicatie::facturi;


// Aplicatie

void Aplicatie::Init() {
    Aplicatie::furnizori.clear();
    Aplicatie::chitante.clear();
    Aplicatie::facturi.clear();
    Aplicatie::ShowOpeningView();
}

void Aplicatie::ShowOpeningView() {
    cout << "Aplicatia se deschide..." << endl;
    Aplicatie::ShowMainMenuView();
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
    cout << "Id - Furnizor - Valoare - Valoare ramasa (" << Aplicatie::facturi.size() << (Aplicatie::facturi.size() == 1 ? " inregistrare)" : " inregistrari)") << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - -" << endl;
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

void Aplicatie::ShowListaChitanteView() {
    cout << endl;
    cout << "Id - Furnizor - Factura - Valoare (" << Aplicatie::chitante.size() << (Aplicatie::chitante.size() == 1 ? " inregistrare)" : " inregistrari)") << endl;
    cout << "- - - - - - - - - - - - - - - - - " << endl;
    for (list<Chitanta>::iterator it = Aplicatie::chitante.begin(); it != Aplicatie::chitante.end(); it++) {
        cout << (*it);
    }

    Aplicatie::ShowMainMenuView();
}

void Aplicatie::ShowAdaugaChitantaView() {
    Chitanta chitanta;
    cin >> chitanta;
    Aplicatie::chitante.push_back(chitanta);
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
            case 5:
                Aplicatie::ShowListaChitanteView();
                break;
            case 6:
                Aplicatie::ShowAdaugaChitantaView();
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

Furnizor* Aplicatie::GetFurnizorByNume(const string nume) {
    for (list<Furnizor>::iterator it = Aplicatie::furnizori.begin(); it != Aplicatie::furnizori.end(); it++) {
        if (it->GetNume() == nume) {
            return &(*it);
        }
    }

    return nullptr;
}

int Aplicatie::GetNextIdFactura() {
    return Aplicatie::facturi.size() + 1;
}

Factura* Aplicatie::GetFacturaById(const int id) {
    for (list<Factura>::iterator it = Aplicatie::facturi.begin(); it != Aplicatie::facturi.end(); it++) {
        if (it->GetId() == id) {
            return &(*it);
        }
    }

    return nullptr;
}

int Aplicatie::GetNextIdChitanta() {
    return Aplicatie::chitante.size() + 1;
}

Aplicatie& Aplicatie::operator=(Aplicatie& other) {
    return *this;
}

Aplicatie::~Aplicatie() { }


// Furnizor

Furnizor::Furnizor(string nume, string iban) {
    this->nume = nume;
    this->iban = iban;
}

Furnizor::Furnizor(const Furnizor& other) {
    this->nume = other.nume;
    this->iban = other.iban;
}

Furnizor& Furnizor::operator=(Furnizor& other) {
    if (this != &other) {
        this->nume = other.nume;
        this->iban = other.iban;
    }

    return *this;
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


// Factura

Factura::Factura(int id, Furnizor* furnizor, double valoare, double valoareRamasa) :
    id(id),
    furnizor(furnizor),
    valoare(valoare),
    valoareRamasa(valoareRamasa) {
}

Factura::Factura(const Factura& other) {
    this->id = other.id;
    this->valoare = other.valoare;
    this->valoareRamasa = other.valoareRamasa;
    this->furnizor = other.furnizor;
}

Factura& Factura::operator=(Factura& other) {
    if (this != &other) {
        this->id = other.id;
        this->valoare = other.valoare;
        this->valoareRamasa = other.valoareRamasa;
        this->furnizor = other.furnizor;
    }

    return *this;
}

istream& operator>>(istream& is, Factura& factura) {
    factura.id = Aplicatie::GetNextIdFactura();

    cout << endl;
    cout << "Introduceti datele facturii" << endl;
    cout << "- - - - - - - - - - - - - - - -" << endl;
    
    cout << "Nume furnizor = ";
    string numeFurnizor;
    is >> numeFurnizor;
    factura.furnizor = Aplicatie::GetFurnizorByNume(numeFurnizor);

    cout << "Valoare = ";
    is >> factura.valoare;

    factura.valoareRamasa = factura.valoare;

    return is;
}

ostream& operator<<(ostream& os, Factura& factura) {
    os << factura.id << " - " << factura.furnizor->GetNume() << " - " << factura.valoare << " - " << factura.valoareRamasa << endl;

    return os;
}

Furnizor* Factura::GetFurnizor() {
    return this->furnizor;
}

int Factura::GetId() {
    return this->id;
}

void Factura::Achita(const double valoare) {
    this->valoareRamasa -= valoare;
}

Factura::~Factura() { }


// Chitanta

Chitanta::Chitanta(int id, Factura* factura, double valoare) :
    id(id),
    factura(factura),
    valoare(valoare) {
}

Chitanta::Chitanta(const Chitanta& other) {
    this->id = other.id;
    this->factura = other.factura;
    this->valoare = other.valoare;
}

Chitanta& Chitanta::operator=(Chitanta& other) {
    if (this != &other) {
        this->id = other.id;
        this->factura = other.factura;
        this->valoare = other.valoare;
    }

    return *this;
}

Factura* Chitanta::GetFactura() {
    return this->factura;
}

istream& operator>>(istream& is, Chitanta& chitanta) {
    chitanta.id = Aplicatie::GetNextIdChitanta();

    cout << endl;
    cout << "Introduceti datele chitantei" << endl;
    cout << "- - - - - - - - - - - - - - - -" << endl;
    
    cout << "Id factura = ";
    int idFactura;
    is >> idFactura;

    chitanta.factura = Aplicatie::GetFacturaById(idFactura);

    cout << "Valoare = ";
    is >> chitanta.valoare;

    chitanta.factura->Achita(chitanta.valoare);

    return is;
}

ostream& operator<<(ostream& os, Chitanta& chitanta) {
    os << chitanta.id << " - " << chitanta.GetFactura()->GetFurnizor()->GetNume() << " - " << chitanta.GetFactura()->GetId() << " - " << chitanta.valoare << endl;

    return os;
}

Chitanta::~Chitanta() { }


// Main

int main() {
    Aplicatie::Init();

    return 0;
}