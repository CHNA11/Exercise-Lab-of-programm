#include "Hotel.h" //inclusione classe definito in header.h
//inclusione libreria basiche per operaizone su classe
#include <iostream>
#include <vector>

using namespace std;
//costruttore della data
Data::Data(int gg, int mm, int aaaa)
{
    //controllo validità basica della data
    if ((gg < 1 || gg > 31) || (mm < 1 || mm > 12) || ((mm == 2 || mm == 4 || mm == 6 || mm == 9 || mm == 11) && gg == 31) || ((aaaa % 4) != 0 && mm == 2 && gg == 29))
    {
        cerr << "Data non valida" << endl;
    }
    else
    {
        giorno = gg;
        mese = mm;
        anno = aaaa;
    }
}
//stampa data in formato gg/mm/aaaa
void Data::stampaData() const
{
    cout << giorno << "/" << mese << "/" << anno << endl;
    return;
}

// funzioni getter

int Data::getGiorno() const
{
    return giorno;
}
int Data::getMese() const
{
    return mese;
}
int Data::getAnno() const
{
    return anno;
}
//funzione che confronta due data e loro ordine con distanza massima 1
int Data::confrontaData(const Data &altra)
{
    if (anno == altra.getAnno())
    {
        if (altra.getMese() == mese)
        {
            //casi più semplici
            if (altra.getGiorno() == (giorno + 1))
            {
                return -1;
            }
            else if (altra.getGiorno() == (giorno - 1))
            {
                return 1;
            }
            else
            {
                return -2;
            }
        }
        //caso tra un fine del mese e inizio del prossimo
        else if (altra.getMese() != 12 && mese == (altra.getMese() + 1))
        {
            if ((altra.getMese() % 2) == 1 && altra.getMese() < 8)
            {
                if (giorno == 1 && altra.getGiorno() == 31)
                {
                    return 1;
                }
                else if (mese == 3)
                {
                    if ((giorno == 1 && altra.getGiorno() == 28 && anno % 4 != 0) || (giorno == 1 && altra.getGiorno() == 29 && anno % 4 == 0))
                    {
                        return 1;
                    }
                }
                else
                {
                    return -2;
                }
            }
            else if (((altra.getMese() % 2) == 0) && altra.getMese() > 7)
            {
                if (giorno == 1 && altra.getGiorno() == 31)
                {
                    return 1;
                }
                else
                {
                    return -2;
                }
            }
        }
        else if (altra.getMese() != 1 && mese == (altra.getMese() - 1))
        {
            if ((altra.getMese() % 2) == 1 && altra.getMese() < 8)
            {
                if (giorno == 30 && altra.getGiorno() == 1)
                {
                    return -1;
                }
                else
                {
                    return -2;
                }
            }
            else if (((altra.getMese() % 2) == 0) && altra.getMese() > 7)
            {
                if (mese == 7)
                {
                    if (giorno == 31 && altra.getGiorno() == 1)
                    {
                        return -1;
                    }
                }
                else if (giorno == 30 && altra.getGiorno() == 1)
                {
                    return -1;
                }
                else
                {
                    return -2;
                }
            }
        }
    }
    //caso fine di anno e inizio di anno prossimo
    else if (altra.getAnno() == (anno + 1))
    {
        if ((mese == 12 && altra.getMese() == 1) && (giorno == 31 && altra.getGiorno() == 1))
        {
            return -1;
        }
        else
        {
            return -2;
        }
    }
    else if (altra.getAnno() == (anno - 1))
    {
        if ((mese == 1 && altra.getMese() == 12) && (giorno == 1 && altra.getGiorno() == 31))
        {
            return 1;
        }
        else
        {
            return -2;
        }
    }
    return -2;
}

//costruttore di caso base
Camera::Camera(int numCam, double prezz, int numPos) : numeroCamera(numCam), prezzoPerNotte(prezz), numeroPosti(numPos), occupata(false)
{
    cout << "Camera costruita correttamente" << endl;
}
//calcola prezzo totale, prezzo*notti
double Camera::calcolaPrezzoTotale(int notti) const
{
    return prezzoPerNotte * notti;
}
//stampa informazioni
void Camera::stampaDettagli() const
{
    cout << "il numero di camera è " << numeroCamera << " con " << numeroPosti << " posti ad " << prezzoPerNotte << " euro per notte" << endl;
}

//distruttore basta default
Camera::~Camera() = default;

//prenotare una camera
void Camera::prenota()
{
    occupata = true;
}
//liberare una camera
void Camera::libera()
{
    occupata = false;
}
//ritorna situazione della camera
bool Camera::isOccupata() const
{
    return occupata;
}

//funzioni getter

int Camera::getNumeroCamera()
{
    return numeroCamera;
}
double Camera::getPrezzoPerNotte()
{
    return prezzoPerNotte;
}
int Camera::getNumeroPosti()
{
    return numeroPosti;
}

//costruttore Camera singola richiamando anche quello di caso base
CameraSingola::CameraSingola(int numCam, double prezz, int numPos, bool vista) : Camera(numCam, prezz, numPos), vistaMare(vista)
{
    cout << "Camera singola costruito" << endl;
}

// aggiungere 20 se si vede mare
double CameraSingola::calcolaPrezzoTotale(int notti) const
{
    if(vistaMare==true){
    return prezzoPerNotte * notti +20;
    }
    else {
        return prezzoPerNotte*notti;
    }

}
//funzione di stampa
void CameraSingola::stampaDettagli() const
{
    Camera::stampaDettagli();
    cout << " Con la visione del mare" << endl;
}

//costruttore suite
Suite::Suite(int numCam, double prezz, int numPos, bool jacuzzi, int numStanze, bool servizio) : Camera(numCam, prezz, numPos), jacuzzi(jacuzzi), numeroStanze(numStanze), servizioIncamera(servizio)
{
    cout << "Suite costruito" << endl;
}

//funzioni getter

bool Suite::getJacuzzi() const
{
    return jacuzzi;
}

int Suite::getNumStanze() const
{
    return numeroStanze;
}

bool Suite::getServizio() const
{
    return servizioIncamera;
}

//calcola prezzo totale della camera per notti
double Suite::calcolaPrezzoTotale(int notti) const
{
    double sum = Camera::calcolaPrezzoTotale(notti);
    //distinguere casi di ogni status
    if (jacuzzi == true)
    {
        sum = sum + 50;
    }
    if (servizioIncamera == true)
    {
        sum = sum + 20;
    }
    return sum;
}
//funzione di stampa informazioni
void Suite::stampaDettagli() const
{
    Camera::stampaDettagli();
    if (jacuzzi == true)
    {
        cout << " con jacuzzi ";
    }
    else
    {
        cout << " senza jacuzzi ";
    }
    if (servizioIncamera == true)
    {
        cout << "e con servizio in camera" << endl;
    }
    else
    {
        cout << "e senza servizio in camera" << endl;
    }
}

//variabile globale per generazione di codice prenotazione, si può usare Static ha siccome attributi vengono fissati uso variabile globale
int codicecontatore = 1;

//costruttore Prenotazione
Prenotazione::Prenotazione(string nomeCliente, Camera *camera, Data Inizio, Data Fine) : codicePrenotazione(codicecontatore), nomeCliente(nomeCliente), camera(camera), dataInizio(Inizio), dataFine(Fine)
{
    cout << "Prenotazione costruito con codice di Prenotazione " << codicecontatore << endl;
    camera->prenota();
    codicecontatore++;
}

//funzioni getter

int Prenotazione::getCodice() const
{
    return codicePrenotazione;
}

string Prenotazione::getNome() const
{
    return nomeCliente;
}

Data Prenotazione::getInizio() const
{
    return dataInizio;
}

Data Prenotazione::getFine() const
{
    return dataFine;
}

Camera *Prenotazione::getCamera() const
{
    return camera;
}

int Prenotazione::getNotti() const
{
    int diffanno = dataFine.getAnno() - dataInizio.getAnno();
    int diffmese = dataFine.getMese() - dataInizio.getMese();
    int diffgiorno = dataFine.getGiorno() - dataInizio.getGiorno();
    //calcoal Notti in modo più semplice escludendo casi di 31 giorni o anno bisestile
    return (diffanno * 365) + (diffmese * 30) + diffgiorno;
}

//stampa informazioni delle prenotazione
void Prenotazione::stampaPrenotazione() const
{
    cout << "il codice di prenotazione è " << codicePrenotazione << " per il cliente " << nomeCliente << endl;
    cout << "Con la camera ";
    camera->stampaDettagli();
    cout << "Dal ";
    dataInizio.stampaData();
    cout << " al ";
    dataFine.stampaData();
    cout << endl;
}

//funzione che calcola costo del Prenotazione corrispondente
double Prenotazione::calcolaCostoTotale() const
{
    return camera->calcolaPrezzoTotale(getNotti());
}

// Costruttore hotel
Hotel::Hotel(string nome) : nomeHotel(nome)
{
    cout << "Hotel costruito " << endl;
}

//funzione di inserimento coda
void Hotel::aggiungiCamera(Camera *c)
{
    camera.push_back(c);
}
//stampa tutte le camere con occupato==false
void Hotel::visualizzaCamereDisponibili() const
{
    for (const Camera *c : camera)
    {
        if (!c->isOccupata())
        {
            c->stampaDettagli();
        }
    }
}
//funzione di inserimento in coda
void Hotel::creaPrenotazione(Prenotazione prenotazione)
{
    prenotazioni.push_back(prenotazione);
}
//funzione che cancella una prenotazione
void Hotel::cancellaPrenotazione()
{
    int codicePrenotazione;
    cout << "Inserisci codice di prenotazione da cancellare : ";
    cin >> codicePrenotazione;
    for (size_t i = 0; i < prenotazioni.size(); i++)
    {
        if (prenotazioni[i].getCodice() == codicePrenotazione)
        {
            prenotazioni[i].getCamera()->libera();
            prenotazioni.erase(prenotazioni.begin() + i);
            cout << "Prenotazione con codice " << codicePrenotazione << " è stato cancellato" << endl;
            return;
        }
    }
    cout << "Prenotazione non trovato" << endl;
}

//funzione che calcola incasso presenti nelle prenotazione
double Hotel::calcolaIncassoTotale() const
{
    double incasso = 0;
    for (const Prenotazione p : prenotazioni)
    {
        incasso = incasso + p.calcolaCostoTotale();
    }
    return incasso;
}
//funzione che stampa dati statistiche
void Hotel::stampaStatistiche() const
{
    int contCamera = 0;
    int numoccupati = 0;
    int numlibere = 0;
    double incasso = calcolaIncassoTotale();
    for (const Camera *c : camera)
    {
        //incrementare contatori per condizioni giuste scorrendo vettore
        if (c->isOccupata())
        {
            numoccupati++;
        }
        else
        {
            numlibere++;
        }
        contCamera++;
    }
    //stampa risultato
    cout << "Ci sono in tutto " << contCamera << " camere con " << numoccupati << " occupati e " << numlibere << " libere ad un incasso totale di " << incasso << endl;
}
