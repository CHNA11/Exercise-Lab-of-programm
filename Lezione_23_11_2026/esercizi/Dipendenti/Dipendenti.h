#pragma once // protettore per header
#include <string> //inclusione minima per struttura stringa

//inclusione namespace standard
using namespace std;


//definizione classe base
class Dipendente{
    //attributi protetti
    protected:
    string nome;
    string cognome;
    int matricola;
    double stipendioBase;
    public:
    //costruttore
    Dipendente(string name, string surname, int num, double stipendio);
    //metodi virtuali per classe base
    //può essere usato come getStipendio
    virtual double calcolaStipendio() const;
    virtual void stampaInfo() const;
    //distruttore
    virtual ~Dipendente();
    //funzioni getter
    string getNome() const;
    string getCognome() const;
    int getMatricola() const;
};

//eredita di Dipendente
class DipendenteFullTime : public Dipendente{
    //attributi privati 
    private:
    double bonus;
    public:
    //costruttore
    DipendenteFullTime(string name, string surname, int num, double stipendio, double aggiunta);
    //funzioni override
    double calcolaStipendio() const override;
    void stampaInfo() const override;
};

//classe eredita di Dipendente
class DipendentePartTime : public Dipendente{
    //attributi privati
    private:
    int oreLavorate;
    double pagaOraria;
    public:
    //costruttore
    DipendentePartTime(string name, string surname, int num,int ore, double pagamento);
    //funzioni override
    double calcolaStipendio() const override;
    void stampaInfo() const override;
};

//classe eredita di DipendenteFullTime
class Manager : public DipendenteFullTime{
    //attributi privati
    private:
    double bonusGestione;
    int numeroSubordinati;
    public:
    //costruttore
    Manager(string name, string surname, int num, double stipendio, double aggiunta,double bonus, int numerosub);
    //funzioni override
    double calcolaStipendio() const override;
    void stampaInfo() const override;
};