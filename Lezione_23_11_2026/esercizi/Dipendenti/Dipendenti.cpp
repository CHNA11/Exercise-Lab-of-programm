#include "Dipendenti.h"
#include <iostream>

using namespace std;

//costruttore di dipendente, con inizializing list
Dipendente::Dipendente(string name, string surname, int num, double stipendio) : nome(name), cognome(surname), matricola(num), stipendioBase(stipendio)
{
    cout << "Dipendente costruito correttamente" << endl;
}

//caso base, ritorna semplicemente stipendio base, quindi come getStipendio
double Dipendente::calcolaStipendio() const
{
    return stipendioBase;
}

//stampa informazione del Dipendente
void Dipendente::stampaInfo() const
{
    cout << "Il dipendente " << nome << " " << cognome << " con matricola " << matricola << " ha stipendio base " << stipendioBase << endl;
}

//Distruttore, stampa solo un messaggio per distruzione
Dipendente::~Dipendente()
{
    cout << "Dipendente distrutto correttamente" << endl;
}

//funzioni getter

string Dipendente::getNome() const
{
    return nome;
}

string Dipendente::getCognome() const
{
    return cognome;
}

int Dipendente::getMatricola() const
{
    return matricola;
}

//costruttore Dipendente full time, richiama costruttore di caso base
DipendenteFullTime::DipendenteFullTime(string name, string surname, int num, double stipendio, double aggiunta) : Dipendente(name, surname, num, stipendio), bonus(aggiunta) {}

//aggiungere al stipendio base il bonus
double DipendenteFullTime::calcolaStipendio() const
{
    return Dipendente::calcolaStipendio() + bonus;
}

//stampa in aggiunta del suo bonus
void DipendenteFullTime::stampaInfo() const
{
    Dipendente::stampaInfo();
    cout << "Come dipendente full time di bonus " << bonus << endl;
}

//costruttore Dipendente Part Time, richiama costruttore di caso base e setta stipendio base come 0
DipendentePartTime::DipendentePartTime(string name, string surname, int num, int ore, double pagamento) : Dipendente(name, surname, num, 0.0), oreLavorate(ore), pagaOraria(pagamento) {}

//stipendio indipendente da quello base
double DipendentePartTime::calcolaStipendio() const
{
    return oreLavorate * pagaOraria;
}

//stampa in aggiunta ore e pagamento per ore
void DipendentePartTime::stampaInfo() const
{
    Dipendente::stampaInfo();
    cout << "Come dipendente part time ha ore lavorate " << oreLavorate << " e stipendio oraria " << pagaOraria << endl;
}

//costruttore manager richiamando costruttore per Dipendente full time
Manager::Manager(string name, string surname, int num, double stipendio, double aggiunta, double bonus, int numerosub) : DipendenteFullTime(name, surname, num, stipendio, aggiunta), bonusGestione(bonus), numeroSubordinati(numerosub) {}

//calcola stipendio aggiungendo da quello di full time in più bonus di gestione
double Manager::calcolaStipendio() const
{
    return DipendenteFullTime::calcolaStipendio() + bonusGestione;
}

//stampa informazione di manager in aggiunta di qualche dati nuovi
void Manager::stampaInfo() const
{
    DipendenteFullTime::stampaInfo();
    cout << "Come manager ha anche bonus di Gestione " << bonusGestione << " e numero di Subordinati " << numeroSubordinati << endl;
}
