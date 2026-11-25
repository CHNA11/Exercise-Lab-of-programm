#pragma once //prottettore per file header.h

//inclusione minima per definizione di classe
#include <string>
#include <vector>

using namespace std;

//definzione classe Data
class Data
{
private:
    int giorno;
    int mese;
    int anno;

public:
//costruttore
    Data(int gg, int mm, int aaaa);
    //stampa data in formato gg/mm/aaaa
    void stampaData() const;
    //funzioni getter
    int getGiorno() const;
    int getMese() const;
    int getAnno() const;
    //funzione che confronta se date sono precedente, uguale o successivo
    int confrontaData(const Data &altra);
};

//definizone classe base Camera
class Camera{
    protected:
    int numeroCamera;
    double prezzoPerNotte;
    bool occupata;
    int numeroPosti;
    public:
    //costruttore
    Camera(int numCam, double prezz, int numPos);
    //calcola prezzo della camera
    virtual double calcolaPrezzoTotale(int notti) const;
    //stampa informazioni della camera
    virtual void stampaDettagli() const;
    //distruttore virtuale
    virtual ~Camera();
    //oprezioni su occupazione
    void prenota();
    void libera();
    bool isOccupata() const;
    //funzioni getter
    int getNumeroCamera();
    double getPrezzoPerNotte();
    int getNumeroPosti();
};

//definizione classe CameraSingola ereditaria di Camera
class CameraSingola : public Camera{
    private:
    bool vistaMare;
    public:
    //costruttore ereditaria
    CameraSingola(int numCam,double prezz,int numPos, bool vista);
    //funzioni getter
    bool getVista() const;
    //funzione che calcola prezzo della stanza
    double calcolaPrezzoTotale(int notti) const override;
    //funzione che stampa dettaglio della Camera singola
    void stampaDettagli() const override;
};

//definizione classe Suite ereditaria di camera
class Suite : public Camera{
    private:
    bool jacuzzi;
    int numeroStanze;
    bool servizioIncamera;
    public:
    //costruttore
    Suite(int numCam, double prezz, int numPos, bool jacuzzi, int numStanze, bool servizio);
    //funzioni getter
    bool getJacuzzi() const;
    int getNumStanze() const;
    bool getServizio() const;
    //calcola prezzo della stanza 
    double calcolaPrezzoTotale(int notti) const override;
    //stampa dettaglio della stanza
    void stampaDettagli() const override;
};

//definizione classe di Prenotazioni
class Prenotazione{
    private:
    int codicePrenotazione;
    string nomeCliente;
    Camera *camera;
    Data dataInizio;
    Data dataFine;
    public:
    //costruttore
    Prenotazione(string nomeCliente, Camera* camera, Data Inizio, Data Fine);
    //funzioni getter
    int getNotti() const;
    int getCodice() const;
    string getNome() const;
    Data getInizio() const;
    Data getFine() const;
    Camera* getCamera() const;
    //funzione di stampa
    void stampaPrenotazione() const;
    //funzione di calcolo
    double calcolaCostoTotale() const;
};

//definizione di classe Hotel
class Hotel{
    private:
    string nomeHotel;
    std::vector<Camera*> camera;
    std::vector<Prenotazione> prenotazioni;
    public:
    //costruttore
    Hotel(string nome);
    //funzione getter
    string getNome() const;
    //funzione che aggiunge un Camera nel vettore di camere
    void aggiungiCamera(Camera* c);
    //funzione che stampa tutte le camere disponibili
    void visualizzaCamereDisponibili() const;
    //funzione che aggiugne un prenotazione nel vettore di prenotazioni
    void creaPrenotazione(Prenotazione prenotazione);
    //funzione che cancella un prenotazione
    void cancellaPrenotazione();
    //funzione di calcolo
    double calcolaIncassoTotale() const;
    //funzione di stampa informazione
    void stampaStatistiche() const;
};
