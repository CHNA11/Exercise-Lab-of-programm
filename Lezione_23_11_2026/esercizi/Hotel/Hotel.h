#pragma once

#include <string>
#include <vector>

using namespace std;

class Data
{
private:
    int giorno;
    int mese;
    int anno;

public:
    Data(int gg, int mm, int aaaa);
    void stampaData() const;
    int getGiorno() const;
    int getMese() const;
    int getAnno() const;
    int confrontaData(const Data &altra);
};

class Camera{
    protected:
    int numeroCamera;
    double prezzoPerNotte;
    bool occupata;
    int numeroPosti;
    public:
    Camera(int numCam, double prezz, int numPos);
    virtual double calcolaPrezzoTotale(int notti) const;
    virtual void stampaDettagli() const;
    void prenota();
    void libera();
    bool isOccupata() const;
    int getNumeroCamera();
    double getPrezzoPerNotte();
    int getNumeroPosti();
};

class CameraSingola : public Camera{
    private:
    bool vistaMare;
    public:
    double calcolaPrezzoTotale(int notti) const override;
    void stampaDettagli() const override;
};

class Suite : public Camera{
    private:
    bool jacuzzi;
    int numeroStanze;
    bool servizioIncamera;
    public:
    double calcolaPrezzoTotale(int notti) const override;
    void stampaDettagli() const override;
};

class Prenotazione{
    private:
    int codicePrenotazione;
    string nomeCliente;
    Camera *camera;
    Data dataInizio;
    Data dataFine;
    public:
    int getNotti() const;
    void stampaPrenotazione() const;
    double calcolaCostoTotale() const;
};

class Hotel{
    private:
    string nomeHotel;
    std::vector<Camera*> camera;
    std::vector<Prenotazione> prenotazioni;
    public:
    void aggiungiCamera(Camera* c);
    void visualizzaCamereDisponibili() const;
    void creaPrenotazione(Prenotazione prenotazione);
    void cancellaPrenotazione();
    double calcolaIncassoTotale() const;
    void stampaStatistiche() const;
};
